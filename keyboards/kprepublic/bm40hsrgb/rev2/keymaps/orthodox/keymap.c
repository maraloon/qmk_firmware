#include QMK_KEYBOARD_H

extern MidiDevice midi_device;

enum layers {
  _ALPHA,
  _NUMBER,
  _SYMBOL,
  _BRCKTS,
  _MOD,
  _MOD2,
  _RGB,
};

#undef _______
#define _ KC_NO
#define __ KC_NO
#define _______ KC_NO
#define ________________ KC_NO

#define Numbers MO(_NUMBER)
#define Symbols MO(_SYMBOL)
#define Brackets MO(_BRCKTS)
#define Mod MO(_MOD)
#define Mod2 MO(_MOD2)
#define Rgb MO(_RGB)

#define PrntSc1 LCAG(KC_1)
#define PrntSc2 LCAG(KC_2)
#define PrntSc3 LCAG(KC_3)

#define NewLine LSFT(KC_ENT)
#define DelWord LALT(KC_BSPC)

#define Alfred HYPR(KC_SPC)
#define Buffer HYPR(KC_V)

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
#define Smaller LCMD(Minus)
#define Bigger LCMD(Plus)
#define Settings LCMD(Comma)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
    _, _Q, _W, _F, _P, _B, _J, _L, _U, _Y, Tmux, _,
    _, _A, _R, _S, _T, _G, _M, _N, _E, _I, _O, _,
    _, _Z, _X, _C, _D, _V, _K, _H, _, _, Alt, _,
    _, _,  _, Mod2, Numbers,  Space,  Mod, Mod2, _, _, _
),
[_MOD] = LAYOUT(
    _, Settings,  _,       Up,      Lang ,     _,       _, LightDec, LightInc, SoundDec, SoundInc, _,
    _, Alfred,    Left,    Down,    Right,     _,       _, Esc,      Tab,      _,        rcmd,     _,
    _, Smaller,   Bigger,  NewLine, Enter,     Buffer,  _, PgDn,     PgUp,     Home,     End,      _,
    _, _,         _,       _,       Backspace, DelWord, _,           _,        _,        _,        _
),
[_MOD2] = LAYOUT(
    _, QK_BOOT, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, PrntSc3, PrntSc2, PrntSc1, _, _, _, _, _, _, _,
    _, _, _, _, Control,  __,  Command, Rgb, _, _, _
),
[_NUMBER] = LAYOUT(
    _, _,  _1, _2, _3, _,       _,         Exlm,     Question,  Slash, _,      _,
    _, _0, _4, _5, _6, _,       Ampersand, Dot,      Comma,     Quote, DQuote, _,
    _, _,  _7, _8, _9, _,       Pipe,      Colon,    Semicolon, Caret, Dollar, _,
    _, _,  _,  _,  _,      __,  Symbols,  _,         _,     _,      _
),
[_SYMBOL] = LAYOUT(
    _,_,      _,    KC_LCBR, KC_RCBR, _, _, Asterisk, Percent, BackSlash,  _,_,
    _,KC_LT, KC_GT, KC_LPRN, KC_RPRN, _, _, At,       Hash,    Tilda,      Grave,_,
    _,_,     _,     KC_LBRC, KC_RBRC, _, _, Plus,     Minus,   Underscore, Equal,_,
    _,_, _, _, _, _, _, _, _, _, _
),
[_RGB] = LAYOUT(
    _, RGB_TOG, RGB_MOD, RGB_RMOD, _, _, _, _, _, _, _, _,
    _, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _, _, _, _, _, _, _,
    _, RGB_VAI, RGB_VAD, _, _, _, _, _, _, _, _, _,
    _, _,  _, _, _,  _,  _, _, _, _, _
),
};
