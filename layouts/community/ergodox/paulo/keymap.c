#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "version.h"

#define PERMISSIVE_HOLD
#define RETRO_TAPPING

enum custom_layers {
    _MOD_DH,
    _NUMB_SYMB,
    _FUNC,
};

// I have a layer on semi-colon that when held down by my pinky, A and S become
// ( and ), D and F become { and }, and finally J and K become [ and ]. Don't
// know how I worked without it!
// https://www.reddit.com/r/MechanicalKeyboards/comments/8doesg/dvorak_fingers_vs_standard_fingers/dxqpk3n/
// `~!@#$%^&*()-_=+,<.>/?;:'"[{]}\|
// There are 32 symbols
// ~!@#$%^&*()_+{}|:"<>?
// 21 symbol keys if we ignore numbers and double brackets, colons, etc

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base layer (colemak mod-dh)
 * ,---------------------------------------------.           ,---------------------------------------------.
 * |        |     |     |     |     |     | Esc  |           | Esc  |     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+------------|           |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  F  |  P  |  B  |  [   |           |  ]   |  J  |  L  |  U  |  Y  |  ;  |   \    |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * |Ctrl/Esc|  A  |  R  |  S  |  T  |  G  |------|           |------|  M  |  N  |  E  |  I  |  O  |   '    |
 * |--------+-----+-----+-----+-----+-----|  -   |           |  =   |-----+-----+-----+-----+-----+--------|
 * | (Shift |  Z  |  X  |  C  |  D  |  V  |      |           |      |  K  |  H  |  ,  |  .  |  /  | Shift) |
 * `--------+-----+-----+-----+-----+------------'           `------------+-----+-----+-----+-----+--------'
 *   |      |     |     | Alt | LGUI|                                     |     |     |     |     |      |
 *   `------------------------------'                                     `------------------------------'
 *                                   ,------------.          ,------------.
 *                                   |     | Mute |          | Home | End |
 *                             ,-----|-----|------|          |------+-----+-----.
 *                             |     |     | Vol+ |          | PgUp |     |     |
 *                             |BkSpc| Del |------|          |------|Enter|Space|
 *                             |Func | Func| Vol- |          | PgDn |Numb |Numb |
 *                             `------------------'          `------------------'
 */
[_MOD_DH] = LAYOUT_ergodox(
  // left hand
  _______       , _______ , _______ , _______ , _______ , _______ , KC_ESC      ,
  KC_TAB        , KC_Q    , KC_W    , KC_F    , KC_P    , KC_B    , KC_LBRACKET ,
  CTL_T(KC_ESC) , KC_A    , KC_R    , KC_S    , KC_T    , KC_G    ,
  KC_LSPO       , KC_Z    , KC_X    , KC_C    , KC_D    , KC_V    , KC_MINUS    ,
  KC_NO         , KC_NO   , KC_NO   , KC_LALT , KC_LGUI ,

                                                KC_NO  , KC_MUTE,
                                                         KC_VOLU,
              LT(_FUNC,KC_BSPACE), LT(_FUNC,KC_DELETE) , KC_VOLD,

  // right hand
  KC_ESC,      _______, _______    , _______    , _______   , _______      , _______,
  KC_RBRACKET, KC_J   , KC_L       , KC_U       , KC_Y      , KC_SCOLON    , KC_BSLASH,
               KC_M   , KC_N       , KC_E       , KC_I      , KC_O         , KC_QUOTE,
  KC_EQUAL,    KC_K   , KC_H       , KC_COMM    , KC_DOT    , KC_SLSH      , KC_RSPC,
                        KC_NO      , KC_NO      , KC_NO     , KC_NO        , KC_NO,

  KC_HOME , KC_END,
  KC_PGUP ,
  KC_PGDN , LT(_NUMB_SYMB,KC_ENTER), LT(_NUMB_SYMB,KC_SPACE)
),

/*
 * Numbers/symbols
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  1!  |  2@  |  3#  |  4$  |  5%  |      |           |      |  6^  |  7&  |  8*  |  9(  |  0)  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  +   |  <   |  {   |  [   |  (   |------|           |------|  )   |  ]   |  }   |  >   |  ~   |  `     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  _   |  -   |  =   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 */

[_NUMB_SYMB] = LAYOUT_ergodox(
  // left hand
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
  _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , _______ ,
  _______ , KC_PLUS , KC_LABK , KC_LCBR , KC_LBRC , KC_LPRN ,
  _______ , _______ , _______ , KC_UNDS , KC_MINS , KC_EQL  , _______ ,
  _______ , _______ , _______ , _______ , _______ ,

                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

  // right hand
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
  _______ , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ ,
            KC_RPRN , KC_RBRC , KC_RCBR , KC_RABK , KC_TILD , KC_GRV  ,
  _______ , _______ , _______ , _______  , _______ , _______ , _______ ,
                      _______ , _______ , _______ , _______ , _______ ,

  _______, _______,
  _______,
  _______, _______, _______
),

/*
 * Function
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F11 |  F12 |      |      |      |------|           |------|      | Left | Down |  Up  | Right|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *
 */

[_FUNC] = LAYOUT_ergodox(
  // left hand
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , _______ ,
  _______ , KC_F11  , KC_F12  , _______ , _______ , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
  _______ , _______ , _______ , _______ , _______ ,

                                                     _______, RESET  ,
                                                              _______,
                                            _______, _______, _______,

  // right hand
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
  _______ , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ ,
            _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT, _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                      _______ , _______ , _______ , _______ , _______ ,

  _______, _______,
  _______,
  _______, _______, _______
)
};
