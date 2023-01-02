#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _NUMBER,
  _SYMBOL,
  _MOD,
  _APP,
};

#undef _______
#define _______ KC_NO
#define ________________ KC_NO

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

#define LNUMBER LT(_NUMBER, KC_SPC)
#define LSYMBOL LT(_SYMBOL, KC_PSLS)
#define LMOD LT(_MOD, KC_PDOT)
#define LAPP LT(_APP, KC_COMM)

// Tap dance enums
enum {
    L12,
    L34
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

void l12_finished(qk_tap_dance_state_t *state, void *user_data);
void l12_finished(qk_tap_dance_state_t *state, void *user_data);
void tap_reset(qk_tap_dance_state_t *state, void *user_data);

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    } else return TD_UNKNOWN;
}

static td_tap_t l12_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t l34_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void l12_finished(qk_tap_dance_state_t *state, void *user_data) {
    l12_tap_state.state = cur_dance(state);
    switch (l12_tap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_SPC); break;
        case TD_DOUBLE_TAP: tap_code(KC_PSLS); break;
        case TD_SINGLE_HOLD: layer_on(_NUMBER); break;
        case TD_DOUBLE_HOLD: layer_on(_SYMBOL); break;
        default: break;
    }
}

void l34_finished(qk_tap_dance_state_t *state, void *user_data) {
    l34_tap_state.state = cur_dance(state);
    switch (l34_tap_state.state) {
        case TD_SINGLE_TAP: tap_code(KC_PDOT); break;
        case TD_DOUBLE_TAP: tap_code(KC_COMM); break;
        case TD_SINGLE_HOLD: layer_on(_MOD); break;
        case TD_DOUBLE_HOLD: layer_on(_APP); break;
        default: break;
    }
}

void tap_reset(qk_tap_dance_state_t *state, void *user_data) {
    layer_move(_ALPHA);
    l12_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [L12] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l12_finished, tap_reset),
    [L34] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, l34_finished, tap_reset)
};

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
#define TMUX LCTL(KC_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_W,    KC_F,    KC_P,    _______, _______, _______, _______, KC_L,    KC_U,    KC_Y,    _______,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    _______, _______, KC_M,    KC_N,    KC_E,    KC_I,    KC_O, 
    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, KC_Q,    KC_H,    KC_K,    KC_J,    KC_B,
    _______, _______, _______, TD(L12), _______, ________________, _______, TD(L34), _______, _______, _______
),

[_NUMBER] = LAYOUT_ortho_4x12_1x2uC(
    _______, KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, _______, KC_QUES, KC_EXLM, _______, _______,
    KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_LCMD, _______, _______, KC_LCMD, KC_COLN, KC_SCLN, KC_QUOT, KC_DQUO,
    _______, KC_P7,   KC_P8,   KC_P9,   KC_LCTL, _______, _______, KC_LCTL, KC_CIRC, KC_DLR,  KC_ASTR, KC_PERC,
    _______, _______, _______, _______, _______, ________________, _______, KC_LALT, _______, _______, _______
),
[_SYMBOL] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, KC_TILD, KC_GRV, _______,
    KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, _______, _______, _______, _______, KC_AT,   KC_HASH, KC_AMPR, _______,
    KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, _______, _______, _______, _______, KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,
    _______, _______, _______, _______, _______, ________________, _______, _______, _______, _______, _______
),
[_MOD] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, KC_UP,   KC_RSFT, _______, _______, _______, _______, KC_F1,   KC_F2,   _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, TMUX,    _______, _______, _______, KC_ESC,  KC_TAB,  KC_F11,  KC_F12,
    ALFRED,  DELWORD, NEWLINE, KC_ENT,  BUFFER,  _______, _______, _______, KC_PGDN, KC_PGUP, KC_HOME, KC_END,
    _______, _______, _______, KC_BSPC, _______, ________________, _______, _______, _______, _______, _______
),
[_APP] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, WARPPTAB,WARPNTAB,_______, _______, _______, _______, _______, _______, _______, _______,
    _______, DM_REC1, DM_RSTP, DM_PLY1, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, PRNTSC1, PRNTSC2, PRNTSC3, _______, _______, _______, QK_BOOT, _______, _______, _______, _______,
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
                    // rgb_matrix_set_color(index, 177, 98, 134);
                    rgb_matrix_set_color(index, 88, 49, 67);
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
        case LSYMBOL:
        case LMOD:
        case LAPP:
            return 1;
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 150;
        default:
            return 150;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LNUMBER:
        case LSYMBOL:
        case LMOD:
        case LAPP:
            return false;
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LNUMBER:
        case LSYMBOL:
        case LMOD:
        case LAPP:
            return false;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LNUMBER:
        case LSYMBOL:
        case LMOD:
        case LAPP:
            return true;
        default:
            return false;
    }
}
