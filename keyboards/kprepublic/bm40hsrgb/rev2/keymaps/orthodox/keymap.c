#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _NUMBER,
  _SYMBOL,
  _BRCKTS,
  _MOD,
  _APP,
};

#undef _______
#define _______ KC_NO
#define ________________ KC_NO

#define LNUMBER LT(_NUMBER, KC_SPC) 
#define LSYMBOL MO(_SYMBOL)
#define LBRCKTS MO(_BRCKTS)
#define LMOD MO(_MOD)
#define LAPP MO(_APP) 

#define PRNTSC1 LCAG(KC_1) 
#define PRNTSC2 LCAG(KC_2) 
#define PRNTSC3 LCAG(KC_3) 

#define NEWLINE LSFT(KC_ENT) 
#define DELWORD LALT(KC_BSPC) 

#define N_CMD CMD_T(KC_N)
#define T_CMD CMD_T(KC_T)
#define E_CTL CTL_T(KC_E)
#define S_CTL CTL_T(KC_S)
#define O_RMD RCMD_T(KC_O)
#define A_RMD RCMD_T(KC_A)

#define ALFRED LCTL(KC_SPC)
#define BUFFER LCTL(KC_V)
#define WARPPTAB S(C(KC_TAB))
#define WARPNTAB LCTL(KC_TAB)
// #define TMUX LCTL(KC_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_W,    KC_F,    KC_P,    _______, _______, _______, _______, KC_L,    KC_U,    KC_Y,    _______,
    A_RMD,   KC_R,    S_CTL,   T_CMD,   KC_G,    _______, _______, KC_M,    N_CMD,   E_CTL,   KC_I,    O_RMD, 
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_Q,    KC_H,    KC_K,    KC_J,    KC_B,
    _______, _______, _______, LNUMBER, LSYMBOL, ________________, LBRCKTS, LMOD,    _______, _______, _______
),
[_NUMBER] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, KC_QUES, KC_EXLM, KC_PSLS, _______,
    KC_P0,   KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______, KC_PDOT, KC_COMM, KC_QUOT, KC_DQUO,
    _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, KC_COLN, KC_SCLN, KC_CIRC, KC_DLR,
    _______, _______, _______, _______, _______, ________________, KC_LALT, KC_LSFT, _______, _______, _______
),
[_SYMBOL] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_ASTR, KC_PERC, KC_TILD, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_AT,   KC_HASH, KC_AMPR, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,
    _______, _______, _______, _______, _______, ________________, _______, _______, _______, _______, _______
),
[_BRCKTS] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, LAPP,    ________________, _______, _______, _______, _______, _______
),
[_MOD] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, KC_UP,   KC_RSFT, _______, _______, _______, _______, KC_F1,   KC_F2,   _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_ESC,  KC_TAB,  KC_F11,  KC_F12,
    ALFRED,  _______, NEWLINE, KC_ENT,  BUFFER,  _______, _______, _______, KC_PGDN, KC_PGUP, KC_HOME, KC_END,
    _______, _______, _______, KC_BSPC, DELWORD, ________________, _______, _______, _______, _______, _______
),
[_APP] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, WARPPTAB,WARPNTAB,_______, _______, _______, _______, _______, _______, _______, _______,
    _______, DM_REC1, DM_RSTP, DM_PLY1, _______, _______, _______, _______, _______, _______, _______, _______,
    QK_BOOT, PRNTSC1, PRNTSC2, PRNTSC3, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, ________________, _______, _______, _______, _______, _______
),
};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {
                if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    // rgb_matrix_set_color(index, 152, 151, 26);
                    rgb_matrix_set_color(index, 177, 98, 134);
                    // rgb_matrix_set_color(index, 88, 49, 67);
                } else {
                    rgb_matrix_set_color(index, 0, 0, 0);
                }

            }
        }
    }
}
 
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LNUMBER:
            return 30;
        default:
            return 150;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LNUMBER:
            return true;
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LNUMBER:
            return true;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LNUMBER:
            return true;
        default:
            return false;
    }
}
