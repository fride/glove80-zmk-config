#define my_tapping_term 380
#define my_quick_tapping_term 112
#define my_ak_delay 40

#define HYPER LC(LS(LG(LALT)))
#define MEH LC(LA(LSFT))
#define NAV_SPCAE &lt l_nav SPACE

// layers
#define DEFAULT    0
#define l_alpha2   1
#define l_nav      2
#define l_sym      3
#define l_num      4
#define MAGIC      5



//
// Glove80 key positions index for positional hold-tap
// - https://discord.com/channels/877392805654306816/937645688244826154/1066713913351221248
// - https://media.discordapp.net/attachments/937645688244826154/1066713913133121556/image.png
//
// |------------------------|------------------------|
// | LEFT_HAND_KEYS         |        RIGHT_HAND_KEYS |
// |                        |                        |
// |  0  1  2  3  4         |          5  6  7  8  9 |
// | 10 11 12 13 14 15      |      16 17 18 19 20 21 |
// | 22 23 24 25 26 27      |      28 29 30 31 32 33 |
// | 34 35 36 37 38 39      |      40 41 42 43 44 45 |
// | 46 47 48 49 50 51      |      58 59 60 61 62 63 |
// | 64 65 66 67 68         |         75 76 77 78 79 |
// |                69 52   |   57 74                |
// |                 70 53  |  56 73                 |
// |                  71 54 | 55 72                  |
// |------------------------|------------------------|
//
#define LEFT_HAND_KEYS    0  1  2  3  4 10 11 12 13 14 15 22 23 24 25 26 27 34 35 36 37 38 39 46 47 48 49 50 51 64 65 66 67 68
#define RIGHT_HAND_KEYS   5  6  7  8  9 16 17 18 19 20 21 28 29 30 31 32 33 40 41 42 43 44 45 58 59 60 61 62 63 75 76 77 78 79
// Right hands but NOT the magic key! ;)
#define RIGHT_HAND_KEYS_M 5  6  7  8  9 16 17 18 19 20 21 28 30 31 32 33 40 41 42 43 44 45 58 59 60 61 62 63 75 76 77 78 79
#define THUMB_KEYS 69 52 57 74 70 53 56 73 71 54   55 72

#define MAGIC_LAYER(NAME, KEY) \
NAME  { \
  bindings = < \
            &trans            &trans              &trans          &trans          &trans                                                                                                           &kp C_MUTE   &kp C_VOL_DN &kp C_VOL_UP  &none           &kp PAUSE_BREAK \
            &trans            &trans              &trans          &trans          &trans          &kp HOME                                                                              &trans       &trans       &trans       &trans        &trans          &trans \
            &trans            &trans              &trans          &trans          &trans          &trans                                                                                &trans       KEY          &trans       &trans        &trans          &trans \
            &trans            &trans              &trans          &trans          &trans          &trans                                                                                &trans       &trans       &trans       &trans        &trans          &trans \
            &trans            &trans              &trans          &trans          &trans          &trans          &trans      &trans      &trans      &trans      &trans      &trans    &trans       &trans       &trans       &trans        &trans          &trans \
            &trans            &kp CAPS            &kp INS         &kp F11         &kp F12                         &trans      &trans      &trans      &trans      &trans      &trans                 &kp KP_N0    &kp KP_N0    &kp KP_DOT    &kp KP_ENTER    &trans \
  >; \
};
