default:
    @just --list --unsorted

config := absolute_path('config')
build := absolute_path('.build')
out := absolute_path('firmware')

init:
    west init -l config
    west update --fetch-opt=--filter=blob:none
    west zephyr-export

# build firmware for matching targets
build expr *west_args:
    #!/usr/bin/env bash
    set -euo pipefail
    targets=$(just _parse_targets {{ expr }})

    [[ -z $targets ]] && echo "No matching targets found. Aborting..." >&2 && exit 1
    echo "$targets" | while IFS=, read -r board shield snippet; do
        just _build_single "$board" "$shield" "$snippet" {{ west_args }}
    done

# build firmware for single board & shield combination
_build_single $board $shield $snippet *west_args:
    #!/usr/bin/env bash
    set -euo pipefail
    artifact="${shield:+${shield// /+}-}${board}"
    build_dir="{{ build / '$artifact' }}"

    echo "Building firmware for $artifact..."
    west build -s zmk/app -d "$build_dir" -b $board {{ west_args }} ${snippet:+-S "$snippet"} -- \
        -DZMK_CONFIG="{{ config }}" ${shield:+-DSHIELD="$shield"}

    if [[ -f "$build_dir/zephyr/zmk.uf2" ]]; then
        mkdir -p "{{ out }}" && cp "$build_dir/zephyr/zmk.uf2" "{{ out }}/$artifact.uf2"
    else
        mkdir -p "{{ out }}" && cp "$build_dir/zephyr/zmk.bin" "{{ out }}/$artifact.bin"
    fi

# parse build.yaml and filter targets by expression
_parse_targets $expr:
    #!/usr/bin/env bash
    attrs="[.board, .shield, .snippet]"
    filter="(($attrs | map(. // [.]) | combinations), ((.include // {})[] | $attrs)) | join(\",\")"
    echo "$(yq -r "$filter" build.yaml | grep -v "^," | grep -i "${expr/#all/.*}")"

#
# TODO
#
setup-zmk:
    docker volume create --driver local -o o=bind -o type=none \
         -o device="/Volumes/sourcecode/github/fride/glove80-zmk-config" zmk-config

# Modules are in here.
setup-modules:
    docker volume create --driver local -o o=bind -o type=none \
        -o device="/Users/jgf/code/github/zmk-modules" zmk-modules

dev-container: setup-zmk setup-modules
    devcontainer up --workspace-folder "/Users/jgf/code/github/zmk"

zmk:
    docker exec -w /workspaces/zmk -it 2d0db403e338 /bin/bash
