#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _PUNCT,
  _NUMSYM,
  _MODS,
  _ARRFN,
  _RGB
};

#define ALPHA MO(_ALPHA)
#define PUNCT MO(_PUNCT)
#define NUMSYM MO(_NUMSYM)
#define MODS MO(_MODS)
#define ARRFN MO(_ARRFN)
#define RGB MO(_RGB)

#define ALFRED LCTL(KC_SPC)
#define BUFFER LCTL(KC_V)
#define WARPPTAB S(C(KC_TAB))
#define WARPNTAB LCTL(KC_TAB)
#define TMUX LCTL(KC_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ALPHA] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_W,    KC_F,    KC_P,    _______, _______, _______, _______, KC_L,    KC_U,    KC_Y,    _______,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    _______, _______, KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_Q,    KC_H,    KC_K,    KC_J,    KC_B,
    _______, _______, _______, LT(_PUNCT,KC_SPC),NUMSYM,  _______, LT(_ARRFN,KC_COMM),LT(_MODS,KC_PDOT),_______, _______, _______
),
[_PUNCT] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, KC_QUES, KC_EXLM, _______, _______,
    KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, _______, _______, _______, _______, KC_COLN, KC_SCLN, KC_QUOT, KC_DQUO,
    _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          KC_LALT, KC_LSFT, _______, _______, _______
),
[_NUMSYM] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_BSLS, KC_PIPE, KC_PSLS, _______, _______, _______, _______, KC_AT,   KC_HASH, KC_AMPR, _______,
    KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_ASTR, _______, _______, KC_PERC, KC_P9,   KC_P8,   KC_P7,   KC_P6,
    KC_PLUS, KC_CIRC, KC_DLR,  KC_P5,   KC_MINS, _______, _______, KC_UNDS, KC_P0,   KC_TILD, KC_GRV,  KC_EQL,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
),
[_ARRFN] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, KC_UP,   KC_RSFT, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F11,  KC_F12,
    _______,LCAG(KC_1),LCAG(KC_2),LCAG(KC_3),_______,_______,_______,_______,_______,_______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______
),
[_MODS] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_TAB,  KC_ESC,  WARPNTAB, _______, _______, _______, _______, KC_HOME, KC_END,  _______, _______,
    KC_RGUI, TMUX,    KC_LGUI, KC_LCTL,  _______, _______, _______, _______, KC_LCTL, KC_LGUI, _______, KC_RGUI,
    ALFRED,  _______,LSFT(KC_ENT),KC_ENT,  BUFFER,  _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______,
    _______, _______, _______, KC_BSPC, LALT(KC_BSPC), _______,     QK_BOOT, _______, _______, _______, _______
),
// [_RGB] = LAYOUT_ortho_4x12_1x2uC(
//     _______, RGB_MOD, RGB_RMOD,_______, _______, _______, _______, _______, _______,  _______, _______, _______,
//     RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_TOG, _______, _______, _______, RGB_M_P,  RGB_M_B,  RGB_M_R, RGB_M_SW,
//     RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______,  _______, _______, _______,
//     _______, _______, _______, _______, _______, _______,          _______, _______,  _______, _______, _______
// )
};

//layer_state_t layer_state_set_user(layer_state_t state) {
//  return update_tri_layer_state(state, _PUNCT, _NUMSYM, _RGB);
//}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED &&
            keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                rgb_matrix_set_color(index, 25, 125, 0);
            }
        }
    }
}

