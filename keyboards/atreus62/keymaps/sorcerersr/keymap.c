// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "features/select_word.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _LOWER 1
#define _RAISE 2


enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  // Other custom keys...
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEFAULT] = LAYOUT( /* qwerty */
    QK_GESC,  KC_1,    KC_2,    KC_3,            KC_4,      KC_5,                        KC_6,    KC_7,     KC_8,       KC_9,    KC_0,     KC_BSPC ,
    KC_TAB,   KC_Q,    KC_W,    KC_E,            KC_R,      KC_T,                        KC_Y,    KC_U,     KC_I,       KC_O,    KC_P,     KC_DEL ,
    SELWORD,  KC_A,    KC_S,    KC_D,            KC_F,      KC_G,                        KC_H,    KC_J,     KC_K,       KC_L,    KC_SCLN,  KC_QUOT ,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,            KC_V,      KC_B,                        KC_N,    KC_M,     KC_COMM,    KC_DOT,  KC_UP,    RSFT_T(KC_ENT) ,
    KC_LCTL,  KC_LALT, KC_LGUI, MO(_LOWER),      KC_MINS,   KC_SPC, KC_BSPC,   KC_ENT,   KC_SPC,  KC_SLSH,  MO(_RAISE), KC_LEFT, KC_DOWN,  KC_RGHT
  ),

  [_LOWER] = LAYOUT(
    KC_F1,         KC_F2,                KC_F3,               KC_F4,              KC_F5,            KC_F6,                       KC_F7,   KC_F8,      KC_F9,   KC_F10,     KC_F11  ,KC_F12 ,
    KC_TILD,       _______,              _______,             _______,            _______,          _______,                     _______, RALT(KC_Y), _______, RALT(KC_P), _______, _______ ,
    KC_TILD,       RALT(KC_Q),           RALT(KC_S),          _______,            _______,          _______,                     _______, KC_UNDS,    KC_PLUS, KC_LCBR,    KC_RCBR, KC_PIPE,
    _______,       LCTL(LGUI(KC_LEFT)),  LCTL(LGUI(KC_RGHT)), LCTL(LSFT(KC_C)),   LCTL(LSFT(KC_V)), _______,                     _______, _______,    _______, _______,    KC_PGUP, _______ ,
    _______,       _______,              _______,             _______,            _______,          _______, _______,  _______,  _______, _______,    _______, KC_HOME,    KC_PGDN, KC_END
  ),

   [_RAISE] = LAYOUT(
    KC_GRV,   _______, _______, _______, _______, RESET,                       _______, _______, _______, _______,  _______, KC_PSCR ,
    KC_GRV,   _______, _______, _______, _______, _______,                     _______, _______, _______, _______,  _______, KC_INS ,
    KC_GRV,   _______, _______, _______, _______, _______,                     _______, KC_MINS, KC_EQL,  KC_LBRC,  KC_RBRC, KC_BSLS ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______,  KC_VOLU, _______ ,
    _______,  _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, KC__MUTE, KC_VOLD, KC__MUTE
  ),

  /*
  [_TRNS] = LAYOUT(
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
  ),
  */
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_select_word(keycode, record, SELWORD)) { return false; }
  // Your macros ...

  return true;
}
