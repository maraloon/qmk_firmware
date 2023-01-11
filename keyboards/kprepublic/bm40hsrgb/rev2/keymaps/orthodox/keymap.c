#include QMK_KEYBOARD_H

extern MidiDevice midi_device;

enum layers {
  _ALPHA,
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
#define _ KC_NO
#define _______ KC_NO
#define ________________ KC_NO

#define Numbers MO(_NUMBER) 
#define Symbols MO(_SYMBOL)
#define Velocity MO(_VELO)
#define Channel MO(_CHNL)
#define Brackets MO(_BRCKTS)
#define Mod MO(_MOD)
#define App MO(_APP) 
#define ToAlpha TO(_ALPHA) 
#define ToNotes TO(_NOTES) 

#define PRNTSC1 LCAG(KC_1) 
#define PRNTSC2 LCAG(KC_2) 
#define PRNTSC3 LCAG(KC_3) 

#define NewLine LSFT(KC_ENT) 
#define DelWord LALT(KC_BSPC) 

#define Alfred LCTL(KC_SPC)
#define Buffer LCTL(KC_V)
#define WARPPTAB S(C(KC_TAB))
#define WARPNTAB LCTL(KC_TAB)

#define _Q KC_Q
#define _W KC_W
#define _F KC_F
#define _P KC_P
#define _B KC_B
#define _J KC_J
#define _L KC_L
#define _Y KC_Y
#define _U KC_U
#define _A KC_A
#define _R KC_R
#define _S KC_S
#define _T KC_T
#define _G KC_G
#define _M KC_M
#define _N KC_N
#define _E KC_E
#define _I KC_I
#define _O KC_O
#define _Z KC_Z
#define _X KC_X
#define _C KC_C
#define _D KC_D
#define _V KC_V
#define _K KC_K
#define _H KC_H

#define _0 KC_P0 
#define _1 KC_P1 
#define _2 KC_P2 
#define _3 KC_P3 
#define _4 KC_P4 
#define _5 KC_P5 
#define _6 KC_P6 
#define _7 KC_P7 
#define _8 KC_P8 
#define _9 KC_P9 

#define Up KC_UP
#define Down KC_DOWN
#define Left KC_LEFT
#define Right KC_RIGHT

#define Space SFT_T(KC_SPC)
#define Backspace KC_BSPC
#define Command KC_LCMD 
#define rcmd KC_RCMD 
#define Lang KC_RSFT
#define Control KC_LCTL 
#define Alt KC_LALT 
#define Enter KC_ENT 
#define Esc KC_ESC 
#define Tab KC_TAB 

#define PgDn KC_PGDN 
#define PgUp KC_PGUP 
#define Home KC_HOME 
#define End KC_END 

#define BackSlash KC_BSLS 
#define Percent KC_PERC 
#define Asterisk KC_ASTR 
#define At KC_AT 
#define Hash KC_HASH 
#define Tilda KC_TILD 
#define Grave KC_GRV 
#define Equal KC_EQL 
#define Underscore KC_UNDS 
#define Minus KC_MINS 
#define Plus KC_PLUS 

#define Exlm KC_EXLM
#define Question KC_QUES
#define Slash KC_PSLS
#define Ampersand KC_AMPR
#define Dot KC_PDOT
#define Comma KC_COMM
#define Quote KC_QUOT
#define DQuote KC_DQUO
#define Pipe KC_PIPE
#define Colon KC_COLN
#define Semicolon KC_SCLN
#define Caret KC_CIRC
#define Dollar KC_DLR

#define LightDec KC_F1
#define LightInc KC_F2
#define SoundDec KC_F11
#define SoundInc KC_F12

#define Tmux LCTL(_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
    _Q, _W, _F, _P, _B, _, _, _J, _L, _U, _Y, Tmux,
    _A, _R, _S, _T, _G, _, _, _M, _N, _E, _I, _O, 
    _Z, _X, _C, _D, _V, _, _, _K, _H, Alt, _,  _,
    _, _, Control, Space, Command, _, Command, Mod, Control, _, _
),
[_NOTES] = LAYOUT(
    MI_C,    MI_Cs,   MI_D,    MI_D,    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_Gs,   MI_A,    MI_As,   MI_B,
    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_G,    _______, _______, MI_SOST, MI_OCT_1,MI_OCT_2,MI_OCT_3,MI_OCT_4,
    MI_Gs,   MI_A,    MI_As,   MI_B,    _______, _______, _______, MI_LEG,  MI_OCT_5,MI_OCT_6,MI_OCT_7,_______,
    _______, _______, _______, Velocity,App,    ________________, _______, Channel,   _______, _______, _______
),
[_MOD] = LAYOUT(
    _,         DelWord, Up,      Lang ,   _,       _, _, _, LightDec, LightInc, SoundDec, SoundInc,
    Backspace, Left,    Down,    Right,   _,       _, _, _, Esc,      Tab,      _,        rcmd,
    Alfred,    Buffer,  NewLine, Enter,   _,       _, _, _, PgDn,     PgUp,     Home,     End,
    _,         _,       _,       Numbers, Symbols, _, _, _, _, _, _
),
[_NUMBER] = LAYOUT(
    _,  _1, _2, _3, _, _, _, _,         Exlm,     Question,  Slash, _,
    _0, _4, _5, _6, _, _, _, Ampersand, Dot,      Comma,     Quote, DQuote,
    _,  _7, _8, _9, _, _, _, Pipe,      Colon,    Semicolon, Caret, Dollar,
    _,  _,  _,  _,  _, _,    App,       _,        _,         _,     _
),
[_SYMBOL] = LAYOUT(
    _,      _,    KC_LCBR, KC_RCBR, _, _, _, _, Asterisk, Percent, BackSlash,  _,
    KC_LT, KC_GT, KC_LPRN, KC_RPRN, _, _, _, _, At,       Hash,    Tilda,      Grave,
    _,     _,     KC_LBRC, KC_RBRC, _, _, _, _, Plus,     Minus,   Underscore, Equal,
    _, _, _, _, _, _, _, _, _, _, _
),
[_APP] = LAYOUT(
    _, _, WARPPTAB, WARPNTAB,_, _, _, _, ToAlpha, ToNotes,_,_,
    _, DM_REC1, DM_RSTP, DM_PLY1, _, _, _, _, _, _, _, _,
    QK_BOOT, PRNTSC1, PRNTSC2, PRNTSC3, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _
),
[_VELO] = LAYOUT(
    _, _, _, _, _, _, _, _, MI_VEL_1,  MI_VEL_2,  MI_VEL_3, _,
    _, _, _, _, _, _, _, MI_VELD, MI_VEL_4,  MI_VEL_5,  MI_VEL_6, MI_VEL_0,
    _, _, _, _, _, _, _, MI_VELU, MI_VEL_7,  MI_VEL_8,  MI_VEL_9, MI_VEL_10,
    _, _, _, _, _, _, _, _, _, _, _
),
[_CHNL] = LAYOUT(
    _, MI_CH1,  MI_CH2,  MI_CH3,  _, _, _, _, MI_CH11, MI_CH12, MI_CH13, _,
    MI_CH10, MI_CH4,  MI_CH5,  MI_CH6,  _, _, _, _, MI_CH14, MI_CH15, MI_CH16, _,
    _, MI_CH7,  MI_CH8,  MI_CH9,  _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _
),
};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {
                if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    switch (layer) {
                    case _ALPHA:
                        rgb_matrix_set_color(index, 0, 20, 20);
                        break;
                    case _MOD:
                        rgb_matrix_set_color(index, 20, 0, 0);
                        break;
                    case _NUMBER:
                        rgb_matrix_set_color(index, 0, 20, 0);
                        break;
                    case _SYMBOL:
                        rgb_matrix_set_color(index, 0, 0, 20);
                        break;
                    default: 
                        rgb_matrix_set_color(index, 20, 0, 20);
                        break;
                    }
                } else {
                    rgb_matrix_set_color(index, 20, 0, 20);
                }

            }
        }
    }
}
