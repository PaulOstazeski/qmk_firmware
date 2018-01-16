#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

enum custom_layers {
    _QWERTY,
    _NUM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic QWERTY layer
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |   `    |  1  |  2  |  3  |  4  |  5  | Esc  |           | Esc  |  6  |  7  |  8  |  9  |  0  |   -    |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  [   |           |  ]   |  Y  |  U  |  I  |  O  |  P  |   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |Ctrl/Esc|  A  |  S  |  D  |  F  |  G  |------|           |------|  H  |  J  |  K  |  L  |  ;  |   '    |
 * |--------+-----+-----+-----+-----+-----|  -   |           |  =   |-----+-----+-----+-----+-----+--------|
 * | (Shift |  Z  |  X  |  C  |  V  |  B  |      |           |      |  N  |  M  |  ,  |  .  |  /  | Shift) |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   | Mute | Vol+|Vol- | Alt | LGUI|                                     | Left|Down | Up  |Right|      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |RESET|      |          |      |RESET|
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     | PgUp |          | Del  |     |     |
 *                             |BkSpc| Num |------|          |------|Enter|Space|
 *                             |     |     | PgDn |          | BkSpc|     |     |
 *                             `------------------'          `------------------'
 */
[_QWERTY] = LAYOUT_ergodox(
  // left hand
  KC_GRAVE      , KC_1    , KC_2    , KC_3    , KC_4    , KC_5 , KC_ESC      ,
  KC_TAB        , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T , KC_LBRACKET ,
  CTL_T(KC_ESC) , KC_A    , KC_S    , KC_D    , KC_F    , KC_G ,
  KC_LSPO       , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B , KC_MINUS    ,
  KC_MUTE       , KC_VOLU , KC_VOLD , KC_LALT , KC_LGUI ,

                                                        RESET, KC_NO,
                                                               KC_PGUP,
                                          KC_BSPACE, TO(_NUM), KC_PGDN,

  // right hand
  KC_ESC,      KC_6, KC_7     ,  KC_8    ,    KC_9   ,    KC_0,                KC_MINUS,
  KC_RBRACKET, KC_Y, KC_U     ,  KC_I    ,    KC_O   ,    KC_P,                KC_BSLASH,
               KC_H, KC_J     ,  KC_K    ,    KC_L   ,    KC_SCOLON,           KC_QUOTE,
  KC_EQUAL,    KC_N, KC_M     ,  KC_COMM ,    KC_DOT ,    KC_SLSH,             KC_RSPC,
                     KC_LEFT  ,  KC_DOWN ,    KC_UP  ,    KC_RIGHT,            KC_NO,

  KC_NO,      RESET,
  KC_DELETE,
  KC_BSPACE,  KC_ENTER, KC_SPACE
),

/* Keymap 1: NUMPAD
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           |      |      |      |  /   |  *   |  -   |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  !   |  @   |  {   |  }   |  |   |      |           |      |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |      |  1   |  2   |  3   |  =   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  0   |  .   | Enter|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,-------------.           ,-------------.
 *                                      |      |      |           |      |      |
 *                               ,------|------|------|           |------+------+------.
 *                               |      |      | Home |           |      |      |      |
 *                               |QWERTY|QWERTY|------|           |------|QWERTY|QWERTY|
 *                               |      |      | End  |           |      |      |      |
 *                               `--------------------'           `--------------------'
 */
[_NUM] = LAYOUT_ergodox(
  // left hand
  KC_NO , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F11 ,
  KC_NO , KC_EXLM , KC_AT   , KC_LCBR , KC_RCBR , KC_PIPE , KC_NO  ,
  KC_NO , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  ,
  KC_NO , KC_PERC , KC_CIRC , KC_LBRC , KC_RBRC , KC_TILD , KC_NO  ,
  KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,

                                                 KC_NO, KC_NO,
                                                        KC_HOME,
                              TO(_QWERTY), TO(_QWERTY), KC_END,

  // right hand
  KC_NO     , KC_NO   , KC_NO   , KC_PSLS     , KC_PAST    , KC_PMNS        , KC_NO   ,
  KC_NO     , KC_NO   , KC_KP_7 , KC_KP_8     , KC_KP_9    , KC_PPLS        , KC_NO   ,
              KC_NO   , KC_KP_4 , KC_KP_5     , KC_KP_6    , KC_PPLS        , KC_PPLS ,
  KC_NO     , KC_NO   , KC_KP_1 , KC_KP_2     , KC_KP_3    , KC_PEQL        , KC_NO   ,
                        KC_KP_0 , KC_KP_0     , KC_PDOT    , KC_ENTER       , KC_NO   ,

  KC_NO, KC_NO,
  KC_NO,
  KC_NO, TO(_QWERTY),  TO(_QWERTY)
),

};
