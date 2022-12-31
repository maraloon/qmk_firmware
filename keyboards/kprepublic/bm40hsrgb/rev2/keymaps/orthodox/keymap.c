#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _PUNCT,
  _NUMSYM,
  _MODS,
  _ARRFN,
};

#define L1 LT(_PUNCT,KC_SPC) 
#define L2 LT(_NUMSYM,KC_PSLS)
#define L3 LT(_ARRFN,KC_COMM) 
#define L4 LT(_MODS,KC_PDOT) 

#define N_CTL CTL_T(KC_N)
#define T_CTL CTL_T(KC_T)
#define E_CMD CMD_T(KC_E)
#define S_CMD CMD_T(KC_S)
#define O_RMD RCMD_T(KC_O)
#define A_RMD RCMD_T(KC_A)

#define ALFRED LCTL(KC_SPC)
#define BUFFER LCTL(KC_V)
#define WARPPTAB S(C(KC_TAB))
#define WARPNTAB LCTL(KC_TAB)
#define TMUX LCTL(KC_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ALPHA] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_W,    KC_F,    KC_P,    _______, _______, _______, _______, KC_L,    KC_U,    KC_Y,    _______,
    A_RMD,   KC_R,    S_CMD,   T_CTL,   KC_G,    _______, _______, KC_M,    N_CTL,   E_CMD,   KC_I,    O_RMD, 
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_Q,    KC_H,    KC_K,    KC_J,    KC_B,
    _______, _______, _______, L1,      L2,      _______,          L3,      L4,      _______, _______, _______
),
[_PUNCT] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, KC_QUES, KC_EXLM, KC_PSLS, _______,
    KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, _______, _______, _______, _______, KC_COLN, KC_SCLN, KC_QUOT, KC_DQUO,
    _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_CIRC, KC_DLR,  KC_ASTR, KC_PERC,
    _______, _______, _______, _______, _______, _______,          KC_LALT, KC_LSFT, _______, _______, _______
),
[_NUMSYM] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_BSLS, KC_PIPE, _______, _______, _______, _______, _______, KC_AT,   KC_HASH, KC_AMPR, _______,
    KC_P1,   KC_P2,   KC_P3,   KC_P4,   _______, _______, _______, KC_PERC, KC_P9,   KC_P8,   KC_P7,   KC_P6,
    KC_PLUS, _______, _______, KC_P5,   KC_MINS, _______, _______, KC_UNDS, KC_P0,   KC_TILD, KC_GRV,  KC_EQL,
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
    _______, TMUX,    _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
    ALFRED,  _______,LSFT(KC_ENT),KC_ENT,  BUFFER,  _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______,
    _______, _______, _______, KC_BSPC, LALT(KC_BSPC), _______,     QK_BOOT, _______, _______, _______, _______
),
};

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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L1:
        case L2:
        case L3:
        case L4:
            return 30;
        default:
            return TAPPING_TERM;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L1:
        case L2:
        case L3:
        case L4:
            return true;
        default:
            return false;
    }
}
