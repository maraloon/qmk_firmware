#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _DOTENT,
  _NUMSYM,
  _BRACKTS,
  _MODS,
  _ARRFN,
  _RGB
};

#define ALPHA MO(_ALPHA)
#define DOTENT MO(_DOTENT)
#define NUMSYM MO(_NUMSYM)
#define BRACKTS MO(_BRACKTS)
#define MODS MO(_MODS)
#define ARRFN MO(_ARRFN)
#define RGB MO(_RGB)

#define ALFRED LCTL(KC_SPC)
#define BUFFER LCTL(KC_V)
#define WARPNTAB LGUI(KC_TAB)
#define WARPPTAB SCMD(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ALPHA] = LAYOUT_ortho_4x12_1x2uC(
    KC_Q,    KC_W,    KC_F,    KC_P,    _______, _______, _______, _______, KC_L,    KC_U,    KC_Y,    KC_G,
    KC_A,    KC_R,    KC_S,    KC_T,    _______, _______, _______, _______, KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_M,    KC_H,    KC_K,    KC_J,    KC_B,
    _______, _______, KC_LALT, DOTENT,  NUMSYM,  _______,          ARRFN,   MODS,    KC_LALT, _______, _______
),
[_DOTENT] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_COMM,  KC_PDOT, KC_EXLM, KC_QUES,
    _______, _______, KC_TAB,  KC_ESC,  _______, _______, _______, _______, LSFT(KC_ENT), KC_ENT, KC_QUOT, KC_DQUO,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_COLN,  KC_SCLN, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, KC_SPC,   _______, _______, _______
),
[_NUMSYM] = LAYOUT_ortho_4x12_1x2uC(
    KC_BSLS, KC_PIPE, KC_PSLS, KC_ASTR, _______, _______, _______, _______, KC_AT,    KC_HASH, KC_AMPR, KC_PERC,
    KC_P1,   KC_P2,   KC_P3,   KC_P4,   _______, _______, _______, _______, KC_P9,    KC_P8,   KC_P7,   KC_P6,
    KC_PLUS, KC_CIRC, KC_DLR,  KC_P5,   KC_MINS, _______, _______, KC_UNDS, KC_P0,    KC_TILD, KC_GRV,  KC_EQL,
    _______, _______, _______, _______, _______, _______,          BRACKTS, _______,  _______, _______, _______
),
[_BRACKTS] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    KC_LT,   KC_LBRC, KC_LCBR, KC_LPRN, _______, _______, _______, _______, KC_RPRN,  KC_RCBR, KC_RBRC, KC_GT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______
),
[_ARRFN] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, KC_UP,   KC_RSFT, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_F1,    KC_F2,   KC_F11,  KC_F12,
    _______, LCAG(KC_1), LCAG(KC_2), LCAG(KC_3), _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______
),
[_MODS] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, WARPPTAB,WARPNTAB, _______, _______, _______, _______, KC_HOME,  KC_END,  _______, _______,
    KC_RGUI, KC_LALT, KC_LGUI, KC_LCTL,  _______, _______, _______, _______, KC_LCTL,  KC_LGUI, KC_LALT, KC_RGUI,
    _______, _______, _______, ALFRED,   BUFFER,  _______, _______, _______, KC_PGDN,  KC_PGUP, _______, _______,
    _______, _______, _______, KC_BSPC, LALT(KC_BSPC), _______,          _______,  _______,  _______, _______, _______
),
[_RGB] = LAYOUT_ortho_4x12_1x2uC(
    RGB_TOG, RGB_MOD, RGB_RMOD,_______, _______, _______, _______, _______, _______,  _______, _______, _______,
    RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, RGB_M_P,  RGB_M_B,  RGB_M_R, RGB_M_SW,
    RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _DOTENT, _NUMSYM, _RGB);
  return state;
}

