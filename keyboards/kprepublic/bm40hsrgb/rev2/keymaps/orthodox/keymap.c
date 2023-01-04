#include QMK_KEYBOARD_H

extern MidiDevice midi_device;

enum layers {
  _ALPHA,
  _QWERTY,
  _NOTES,
  _VELO,
  _CHNL,
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
[_QWERTY] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_W,    KC_E,    KC_R,    _______, _______, _______, _______, KC_U,    KC_I,    KC_O,    _______,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_Q,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_T,    KC_Y,    KC_P,
    _______, _______, _______, LNUMBER, LSYMBOL, ________________, LBRCKTS, LMOD,    _______, _______, _______
),
[_NOTES] = LAYOUT_ortho_4x12_1x2uC(
    _______, MI_C,    MI_Cs,   MI_D,    _______, _______, _______, _______, MI_OCT_N2,MI_OCT_N1,MI_OCT_0,_______,
    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_G,    _______, _______, MI_SOST, MI_OCT_1,MI_OCT_2,MI_OCT_3,MI_OCT_4,
    MI_Gs,   MI_A,    MI_As,   MI_B,    _______, _______, _______, MI_LEG,  MI_OCT_5,MI_OCT_6,MI_OCT_7,_______,
    _______, _______, _______,MO(_VELO),LAPP,    ________________, _______,MO(_CHNL),_______, _______, _______
),
[_VELO] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, _______, MI_VEL_1,  MI_VEL_2,  MI_VEL_3, _______,
    _______, _______, _______, _______, _______, _______, _______, MI_VELD, MI_VEL_4,  MI_VEL_5,  MI_VEL_6, MI_VEL_0,
    _______, _______, _______, _______, _______, _______, _______, MI_VELU, MI_VEL_7,  MI_VEL_8,  MI_VEL_9, MI_VEL_10,
    _______, _______, _______, _______, _______, ________________, _______, _______, _______, _______, _______
),
[_CHNL] = LAYOUT_ortho_4x12_1x2uC(
    _______, MI_CH1,  MI_CH2,  MI_CH3,  _______, _______, _______, _______, MI_CH11, MI_CH12, MI_CH13, _______,
    MI_CH10, MI_CH4,  MI_CH5,  MI_CH6,  _______, _______, _______, _______, MI_CH14, MI_CH15, MI_CH16, _______,
    _______, MI_CH7,  MI_CH8,  MI_CH9,  _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, ________________, _______, _______, _______, _______, _______
),
[_NUMBER] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, KC_QUES, KC_EXLM, KC_PSLS, _______,
    KC_P0,   KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______, KC_PDOT, KC_COMM, KC_QUOT, KC_DQUO,
    _______, KC_P7,   KC_P8,   KC_P9,   _______, _______, _______, _______, KC_COLN, KC_SCLN, KC_CIRC, KC_DLR,
    _______, _______, _______, _______, _______, ________________, KC_LALT, KC_LSFT, _______, _______, _______
),
[_SYMBOL] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_ASTR, KC_PERC, KC_TILD, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_AT,   KC_HASH, KC_AMPR, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,
    _______, _______, _______, _______, _______, ________________, LAPP,    _______, _______, _______, _______
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
    _______, _______, WARPPTAB,WARPNTAB,_______, _______, _______, _______,DF(_ALPHA),DF(_QWERTY),DF(_NOTES),_______,
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
                    rgb_matrix_set_color(index, 210, 170, 0);
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
