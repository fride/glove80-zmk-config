{ firmware ? import ../src {}
# semi colon separated paths to modules
, extra_modules ? ""
}:

let
  config = ./.;

  glove80_left = firmware.zmk.override {
    board = "glove80_lh";
    keymap = "${config}/glove80.keymap";
    kconfig = "${config}/glove80.conf";
    extra_modules = extra_modules;
  };

  glove80_right = firmware.zmk.override {
    board = "glove80_rh";
    keymap = "${config}/glove80.keymap";
    kconfig = "${config}/glove80.conf";
    extra_modules = extra_modules;
  };

in firmware.combine_uf2 glove80_left glove80_right
