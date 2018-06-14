#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "version.h"

enum custom_layers {
    _QWERTY,
    _T1,
    _T2,
    _T3,
    _T4,
    _T5,
    _T6,
    _NUM,
    _MOUSE,
};

// I have a layer on semi-colon that when held down by my pinky, A and S become
// ( and ), D and F become { and }, and finally J and K become [ and ]. Don't
// know how I worked without it!
// https://www.reddit.com/r/MechanicalKeyboards/comments/8doesg/dvorak_fingers_vs_standard_fingers/dxqpk3n/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic QWERTY layer
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  [   |           |  ]   |  Y  |  U  |  I  |  O  |  P  |   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |Ctrl/Esc|  A  |  S  |  D  |  F  |  G  |------|           |------|  H  |  J  |  K  |  L  |;/Num|   '    |
 * |--------+-----+-----+-----+-----+-----|  -   |           |  =   |-----+-----+-----+-----+-----+--------|
 * | (Shift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  N  |  M  |  ,  |  .  |  /  | Shift) |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Mute | Vol+|Vol- | Alt | LGUI|                                     | Left|Down | Up  |Right|      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     |      |          | Num  |     |     |
 *                             |BkSpc| Del |------|          |------|Enter|Space|
 *                             |     |     |      |          | Mouse|     |     |
 *                             `------------------'          `------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5 , KC_ESC      ,
  KC_TAB        , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T , KC_LBRACKET ,
  CTL_T(KC_ESC) , KC_A    , KC_S    , KC_D    , KC_F    , KC_G ,
  KC_LSPO       , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B , KC_MINUS    ,
  KC_MUTE       , KC_VOLU , KC_VOLD , KC_LALT , KC_LGUI ,

                                                         KC_NO, KC_NO,
                                                                KC_NO,
                                          KC_BSPACE, KC_DELETE, KC_NO,

  // right hand
  KC_ESC,      KC_6, KC_7     ,  KC_8    ,    KC_9   ,    KC_0,                KC_MINUS,
  KC_RBRACKET, KC_Y, KC_U     ,  KC_I    ,    KC_O   ,    KC_P,                KC_BSLASH,
               KC_H, KC_J     ,  KC_K    ,    KC_L   ,    LT(_NUM, KC_SCOLON), KC_QUOTE,
  KC_EQUAL,    KC_N, KC_M     ,  KC_COMM ,    KC_DOT ,    KC_SLSH,             KC_RSPC,
                     KC_LEFT  ,  KC_DOWN ,    KC_UP  ,    KC_RIGHT,            KC_NO,

  KC_NO, KC_NO,
  TG(_NUM),
  TG(_MOUSE), KC_ENTER, KC_SPACE
),

/* Keymap 1: Tarmak1(E) (E>K>N>J)
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  J  |  R  |  T  |  [   |           |  ]   |  Y  |  U  |  I  |  O  |  P  |   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |Ctrl/Esc|  A  |  S  |  D  |  F  |  G  |------|           |------|  H  |  N  |  E  |  L  |;/Num|   '    |
 * |--------+-----+-----+-----+-----+-----|  -   |           |  =   |-----+-----+-----+-----+-----+--------|
 * | (Shift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  K  |  M  |  ,  |  .  |  /  | Shift) |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Mute | Vol+|Vol- | Alt | LGUI|                                     | Left|Down | Up  |Right|      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     |      |          | Num  |     |     |
 *                             |BkSpc| Del |------|          |------|Enter|Space|
 *                             |     |     |      |          | Mouse|     |     |
 *                             `------------------'          `------------------'
 */
[_T1] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5 , KC_ESC      ,
  KC_TAB        , KC_Q    , KC_W    , KC_J    , KC_R    , KC_T , KC_LBRACKET ,
  CTL_T(KC_ESC) , KC_A    , KC_S    , KC_D    , KC_F    , KC_G ,
  KC_LSPO       , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B , KC_MINUS    ,
  KC_MUTE       , KC_VOLU , KC_VOLD , KC_LALT , KC_LGUI ,

                                                         KC_NO, KC_NO,
                                                                KC_NO,
                                          KC_BSPACE, KC_DELETE, KC_NO,

  // right hand
  KC_ESC,      KC_6, KC_7     ,  KC_8    ,    KC_9   ,    KC_0,                KC_MINUS,
  KC_RBRACKET, KC_Y, KC_U     ,  KC_I    ,    KC_O   ,    KC_P,                KC_BSLASH,
               KC_H, KC_N     ,  KC_E    ,    KC_L   ,    LT(_NUM, KC_SCOLON), KC_QUOTE,
  KC_EQUAL,    KC_K, KC_M     ,  KC_COMM ,    KC_DOT ,    KC_SLSH,             KC_RSPC,
                     KC_LEFT  ,  KC_DOWN ,    KC_UP  ,    KC_RIGHT,            KC_NO,

  KC_NO, KC_NO,
  TG(_NUM),
  TG(_MOUSE), KC_ENTER, KC_SPACE
),

/* Keymap 2: Tarmak2(ET) (G>T>F>E>K>N>J)
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  R  |  G  |  [   |           |  ]   |  Y  |  U  |  I  |  O  |  P  |   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |Ctrl/Esc|  A  |  S  |  D  |  T  |  J  |------|           |------|  H  |  N  |  E  |  L  |;/Num|   '    |
 * |--------+-----+-----+-----+-----+-----|  -   |           |  =   |-----+-----+-----+-----+-----+--------|
 * | (Shift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  K  |  M  |  ,  |  .  |  /  | Shift) |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Mute | Vol+|Vol- | Alt | LGUI|                                     | Left|Down | Up  |Right|      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     |      |          | Num  |     |     |
 *                             |BkSpc| Del |------|          |------|Enter|Space|
 *                             |     |     |      |          | Mouse|     |     |
 *                             `------------------'          `------------------'
 */
[_T2] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5 , KC_ESC      ,
  KC_TAB        , KC_Q    , KC_W    , KC_F    , KC_R    , KC_G , KC_LBRACKET ,
  CTL_T(KC_ESC) , KC_A    , KC_S    , KC_D    , KC_T    , KC_J ,
  KC_LSPO       , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B , KC_MINUS    ,
  KC_MUTE       , KC_VOLU , KC_VOLD , KC_LALT , KC_LGUI ,

                                                         KC_NO, KC_NO,
                                                                KC_NO,
                                          KC_BSPACE, KC_DELETE, KC_NO,

  // right hand
  KC_ESC,      KC_6, KC_7     ,  KC_8    ,    KC_9   ,    KC_0,                KC_MINUS,
  KC_RBRACKET, KC_Y, KC_U     ,  KC_I    ,    KC_O   ,    KC_P,                KC_BSLASH,
               KC_H, KC_N     ,  KC_E    ,    KC_L   ,    LT(_NUM, KC_SCOLON), KC_QUOTE,
  KC_EQUAL,    KC_K, KC_M     ,  KC_COMM ,    KC_DOT ,    KC_SLSH,             KC_RSPC,
                     KC_LEFT  ,  KC_DOWN ,    KC_UP  ,    KC_RIGHT,            KC_NO,

  KC_NO, KC_NO,
  TG(_NUM),
  TG(_MOUSE), KC_ENTER, KC_SPACE
),

/* Keymap 3: Tarmak3(ETR) (R>S>D>G>T>F>E>K>N>J)
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  J  |  G  |  [   |           |  ]   |  Y  |  U  |  I  |  O  |  P  |   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |Ctrl/Esc|  A  |  J  |  S  |  T  |  D  |------|           |------|  H  |  N  |  E  |  L  |;/Num|   '    |
 * |--------+-----+-----+-----+-----+-----|  -   |           |  =   |-----+-----+-----+-----+-----+--------|
 * | (Shift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  K  |  M  |  ,  |  .  |  /  | Shift) |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Mute | Vol+|Vol- | Alt | LGUI|                                     | Left|Down | Up  |Right|      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     |      |          | Num  |     |     |
 *                             |BkSpc| Del |------|          |------|Enter|Space|
 *                             |     |     |      |          | Mouse|     |     |
 *                             `------------------'          `------------------'
 */
[_T3] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5 , KC_ESC      ,
  KC_TAB        , KC_Q    , KC_W    , KC_F    , KC_J    , KC_G , KC_LBRACKET ,
  CTL_T(KC_ESC) , KC_A    , KC_J    , KC_S    , KC_T    , KC_D ,
  KC_LSPO       , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B , KC_MINUS    ,
  KC_MUTE       , KC_VOLU , KC_VOLD , KC_LALT , KC_LGUI ,

                                                         KC_NO, KC_NO,
                                                                KC_NO,
                                          KC_BSPACE, KC_DELETE, KC_NO,

  // right hand
  KC_ESC,      KC_6, KC_7     ,  KC_8    ,    KC_9   ,    KC_0,                KC_MINUS,
  KC_RBRACKET, KC_Y, KC_U     ,  KC_I    ,    KC_O   ,    KC_P,                KC_BSLASH,
               KC_H, KC_N     ,  KC_E    ,    KC_L   ,    LT(_NUM, KC_SCOLON), KC_QUOTE,
  KC_EQUAL,    KC_K, KC_M     ,  KC_COMM ,    KC_DOT ,    KC_SLSH,             KC_RSPC,
                     KC_LEFT  ,  KC_DOWN ,    KC_UP  ,    KC_RIGHT,            KC_NO,

  KC_NO, KC_NO,
  TG(_NUM),
  TG(_MOUSE), KC_ENTER, KC_SPACE
),

/* Keymap 4: Tarmak4(ETRO) (Y>O>;>P>R>S>D>G>T>F>E>K>N>J)
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  P  |  G  |  [   |           |  ]   |  J  |  U  |  I  |  Y  |;/Num|   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |Ctrl/Esc|  A  |  R  |  S  |  T  |  D  |------|           |------|  H  |  N  |  E  |  L  |  O  |   '    |
 * |--------+-----+-----+-----+-----+-----|  -   |           |  =   |-----+-----+-----+-----+-----+--------|
 * | (Shift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  K  |  M  |  ,  |  .  |  /  | Shift) |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Mute | Vol+|Vol- | Alt | LGUI|                                     | Left|Down | Up  |Right|      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     |      |          | Num  |     |     |
 *                             |BkSpc| Del |------|          |------|Enter|Space|
 *                             |     |     |      |          | Mouse|     |     |
 *                             `------------------'          `------------------'
 */
[_T4] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5 , KC_ESC      ,
  KC_TAB        , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G , KC_LBRACKET ,
  CTL_T(KC_ESC) , KC_A    , KC_R    , KC_S    , KC_T    , KC_D ,
  KC_LSPO       , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B , KC_MINUS    ,
  KC_MUTE       , KC_VOLU , KC_VOLD , KC_LALT , KC_LGUI ,

                                                         KC_NO, KC_NO,
                                                                KC_NO,
                                          KC_BSPACE, KC_DELETE, KC_NO,

  // right hand
  KC_ESC,      KC_6, KC_7     ,  KC_8    ,    KC_9   ,    KC_0,                KC_MINUS,
  KC_RBRACKET, KC_J, KC_U     ,  KC_I    ,    KC_Y   ,    LT(_NUM, KC_SCOLON), KC_BSLASH,
               KC_H, KC_N     ,  KC_E    ,    KC_L   ,    KC_O,                KC_QUOTE,
  KC_EQUAL,    KC_K, KC_M     ,  KC_COMM ,    KC_DOT ,    KC_SLSH,             KC_RSPC,
                     KC_LEFT  ,  KC_DOWN ,    KC_UP  ,    KC_RIGHT,            KC_NO,

  KC_NO, KC_NO,
  TG(_NUM),
  TG(_MOUSE), KC_ENTER, KC_SPACE
),

/* Keymap 5: Colemak (Y>O>;>P>R>S>D>G>T>F>E>K>N>J & L>U>I)
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  P  |  G  |  [   |           |  ]   |  J  |  L  |  U  |  Y  |;/Num|   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |Ctrl/Esc|  A  |  R  |  S  |  T  |  D  |------|           |------|  H  |  N  |  E  |  I  |  O  |   '    |
 * |--------+-----+-----+-----+-----+-----|  -   |           |  =   |-----+-----+-----+-----+-----+--------|
 * | (Shift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  K  |  M  |  ,  |  .  |  /  | Shift) |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Mute | Vol+|Vol- | Alt | LGUI|                                     | Left|Down | Up  |Right|      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     |      |          | Num  |     |     |
 *                             |BkSpc| Del |------|          |------|Enter|Space|
 *                             |     |     |      |          | Mouse|     |     |
 *                             `------------------'          `------------------'
 */
[_T5] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5 , KC_ESC      ,
  KC_TAB        , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G , KC_LBRACKET ,
  CTL_T(KC_ESC) , KC_A    , KC_R    , KC_S    , KC_T    , KC_D ,
  KC_LSPO       , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B , KC_MINUS    ,
  KC_MUTE       , KC_VOLU , KC_VOLD , KC_LALT , KC_LGUI ,

                                                         KC_NO, KC_NO,
                                                                KC_NO,
                                          KC_BSPACE, KC_DELETE, KC_NO,

  // right hand
  KC_ESC,      KC_6, KC_7     ,  KC_8    ,    KC_9   ,    KC_0,                KC_MINUS,
  KC_RBRACKET, KC_J, KC_L     ,  KC_U    ,    KC_Y   ,    LT(_NUM, KC_SCOLON), KC_BSLASH,
               KC_H, KC_N     ,  KC_E    ,    KC_I   ,    KC_O,                KC_QUOTE,
  KC_EQUAL,    KC_K, KC_M     ,  KC_COMM ,    KC_DOT ,    KC_SLSH,             KC_RSPC,
                     KC_LEFT  ,  KC_DOWN ,    KC_UP  ,    KC_RIGHT,            KC_NO,

  KC_NO, KC_NO,
  TG(_NUM),
  TG(_MOUSE), KC_ENTER, KC_SPACE
),

/* Keymap 6: Colemak-mod-DH
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  P  |  B  |  [   |           |  ]   |  J  |  L  |  U  |  Y  |;/Num|   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |Ctrl/Esc|  A  |  R  |  S  |  T  |  G  |------|           |------|  M  |  N  |  E  |  I  |  O  |   '    |
 * |--------+-----+-----+-----+-----+-----|  -   |           |  =   |-----+-----+-----+-----+-----+--------|
 * | (Shift |  Z  |  X  |  C  |  D  |  V  |      |           |      |  K  |  H  |  ,  |  .  |  /  | Shift) |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Mute | Vol+|Vol- | Alt | LGUI|                                     | Left|Down | Up  |Right|      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     |      |          |      |     |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     |      |          | Num  |     |     |
 *                             |BkSpc| Del |------|          |------|Enter|Space|
 *                             |     |     |      |          | Mouse|     |     |
 *                             `------------------'          `------------------'
 */
[_T6] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5 , KC_ESC      ,
  KC_TAB        , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B , KC_LBRACKET ,
  CTL_T(KC_ESC) , KC_A    , KC_R    , KC_S    , KC_T    , KC_G ,
  KC_LSPO       , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V , KC_MINUS    ,
  KC_MUTE       , KC_VOLU , KC_VOLD , KC_LALT , KC_LGUI ,

                                                         KC_NO, KC_NO,
                                                                KC_NO,
                                          KC_BSPACE, KC_DELETE, KC_NO,

  // right hand
  KC_ESC,      KC_6, KC_7     ,  KC_8    ,    KC_9   ,    KC_0,                KC_MINUS,
  KC_RBRACKET, KC_J, KC_L     ,  KC_U    ,    KC_Y   ,    LT(_NUM, KC_SCOLON), KC_BSLASH,
               KC_M, KC_N     ,  KC_E    ,    KC_I   ,    KC_O,                KC_QUOTE,
  KC_EQUAL,    KC_K, KC_H     ,  KC_COMM ,    KC_DOT ,    KC_SLSH,             KC_RSPC,
                     KC_LEFT  ,  KC_DOWN ,    KC_UP  ,    KC_RIGHT,            KC_NO,

  KC_NO, KC_NO,
  TG(_NUM),
  TG(_MOUSE), KC_ENTER, KC_SPACE
),

/* Keymap 7: NUMPAD
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | QWERTY | T-1  | T-2  | T-3  | T-4  | T-5  | T-6  |           |      |      |      |  /   |  *   |  -   |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  !   |  @   |  {   |  }   |  |   | Home |           | PgUp |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |------|           |------|      |  4   |  5   |  6   | TRNS |        |
 * |--------+------+------+------+------+------| End  |           | PgDn |------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |      |  1   |  2   |  3   |  =   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  0   |  .   | Enter|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      |      |           |      |      |      |
 *                               |      |      |------|           |------|      |      |
 *                               |      |      |      |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_NUM] = LAYOUT_ergodox(
  // left hand
  DF(_QWERTY) , DF(_T1) , DF(_T2) , DF(_T3) , DF(_T4) , DF(_T5) , DF(_T6) ,
  _______     , KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE , KC_HOME,
  _______     , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  ,
  _______     , KC_PERC , KC_CIRC , KC_LBRC , KC_RBRC , KC_TILD , KC_END ,
  _______     , _______ , _______ , _______ , _______ ,

                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

  // right hand
  _______   , _______   , _______ , KC_PSLS     , KC_PAST    , KC_PMNS        , _______   ,
  KC_PGUP   , _______   , KC_KP_7 , KC_KP_8     , KC_KP_9    , KC_PPLS        , _______   ,
              _______   , KC_KP_4 , KC_KP_5     , KC_KP_6    , _______        , KC_PPLS ,
  KC_PGDN   , _______   , KC_KP_1 , KC_KP_2     , KC_KP_3    , KC_PEQL        , _______   ,
                          KC_KP_0 , KC_KP_0     , KC_PDOT    , KC_ENTER       , _______   ,

  _______, _______,
  _______,
  _______, _______, _______
),

/* Keymap 8: MOUSE
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | Lclk | Rclk | Lclk | Rclk |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|MsLeft|MsDown| MsUp |MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_MOUSE] = LAYOUT_ergodox(
   RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,
 _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______,
                                     _______, _______,
                                              _______,
                            _______, _______, _______,
// right hand
_______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
_______,  KC_BTN1, KC_BTN2, KC_BTN1, KC_BTN2, _______, KC_F12,
          KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
_______,  _______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______,
_______, _______,
_______,
_______, _______, _______
),
};
