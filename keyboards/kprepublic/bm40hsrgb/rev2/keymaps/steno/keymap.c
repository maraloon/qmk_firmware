#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _SYMBOL,
  _SYMBOL2,
  _BRACKET,
  _LAYER,
  _NUMBER,
  _NAVIGATION,
  _TG,
  _MOUSE,
  _APP,
  _APP2,
  _RECTANGLE,
};

#undef _______
#define _ KC_NO
#define __ KC_NO
#define ____ KC_NO
#define _______ KC_NO
#define ________________ KC_NO

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

#define SCUp LSFT(LCTL(Up))
#define SCDown LSFT(LCTL(Down))
#define SCLeft LSFT(LCTL(Left))
#define SCRight LSFT(LCTL(Right))

#define LeftClick KC_BTN1
#define RightClick KC_BTN2
#define WheelUp KC_MS_WH_UP
#define WheelDown KC_MS_WH_DOWN
#define MUp KC_MS_UP
#define MDown KC_MS_DOWN
#define MLeft KC_MS_LEFT
#define MRight KC_MS_RIGHT
#define MSpeed0 KC_MS_ACCEL0
#define MSpeed1 KC_MS_ACCEL1
#define MSpeed2 KC_MS_ACCEL2

#define Space KC_SPC
#define Backspace KC_BSPC
#define Delete KC_DEL
#define Command KC_LCMD
#define ChangeApp RSFT(RALT(KC_RCMD))
#define PrevApp LCMD(KC_TAB)
#define Lang LCMD(Space)
#define Control KC_LCTL
#define Alt KC_LALT
#define Shift KC_LSFT
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

#define PrntSc1 LCAG(KC_1)
#define PrntSc2 LCAG(KC_2)
#define PrntSc3 LCAG(KC_3)

#define NewLine LSFT(Enter)
#define DelWord LALT(Backspace)

#define Quit LCMD(_Q)
#define Close LCMD(_W)
#define SelectAll LCMD(_A)
#define Cut LCMD(_X)
#define Copy LCMD(_C)
#define Paste LCMD(_V)

#define Alfred HYPR(Space)
#define AlfredP HYPR(_P)
#define AlfredL HYPR(_L)
#define Buffer HYPR(_V)
#define Tmux LCTL(_A)
#define Smaller LCMD(Minus)
#define Bigger LCMD(Plus)
#define Settings LCMD(Comma)
#define MoveToBin LCMD(Backspace)
#define WinLeft LCTL(Left)
#define WinRight LCTL(Right)

#define LeftHalf LCAG(Left)
#define RightHalf LCAG(Right)
#define Maximixe LCAG(_M)
#define WinSmaller LCAG(Minus)
#define WinLarger LCAG(Equal)
#define Fullscreen LCMD(LCTL(_F))

#define _RF LALT(KC_1) // ф
#define _RY LALT(KC_2) // ю
#define _RH LALT(KC_3) // ш
#define _RZ LALT(KC_4) // щ
#define _RT LALT(KC_5) // ъ
#define _RI LALT(KC_6) // э

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
    _RI, _W, _F, _P, _B, _, _, _J, _L, _U, _Y, _RZ,
    _N, _R, _S, _T, _G, _, _, _M, _A, _E, _I, _O,
    _RY, _X, _C, _D, _V, _, _, _K, _H, _Z, _Q, _RH,
    _, _,
    MO(_APP), LT(_NUMBER, Backspace), MT(MOD_LSFT, Space),
    __,
    LT(_SYMBOL, Space), LT(_NAVIGATION, Enter), MO(_APP2), _, _
),
[_NUMBER] = LAYOUT(
    _, KC_LCBR,  _0, KC_LPRN, _, _, _, _, KC_RPRN, _9, KC_RCBR, _,
    KC_LBRC, _1, _2, _3, Tmux, _, _, _, _5, _6, _7, KC_RBRC,
    _, _,  KC_LT, _4, _, _, _, _, _8, KC_GT, _, _,
    _,  _,  _, _,  _, __, Command, Control, _, _, _
),
[_SYMBOL] = LAYOUT(
    _, Minus, Slash, Asterisk,   _, _, _, _,   Exlm, Question, Underscore, _,
    Tilda, BackSlash, Caret, Dollar, _, _, _, Ampersand,   Dot, Comma, Quote, DQuote,
    Percent, Grave, Hash, At, _, _, _, Pipe,   Colon, Semicolon, Plus, Equal,
    _, _, _, _, _,  _,  _, _,  _, _, _
),
[_APP] = LAYOUT(
    _, QK_BOOT, _, _, _, _, _, _, PrntSc1, PrntSc2, PrntSc3, _,
    _, _, _, Tmux, _, _, _, _, LightDec, LightInc, SoundDec, SoundInc,
    _, _, _, _, _, _, _, MoveToBin, Smaller, Bigger, Settings, _,
    _, _, _, _,    _,   __, _, _, _, _, _
),
[_APP2] = LAYOUT(
    _, _, _RF, _RT, _, _, _, _, _, _, _, _,
    _, _, _, Alfred, _, _, _, _, Tmux, _, _, _,
    _, _, AlfredP, AlfredL, Buffer, _, _, _, _, _, _, _,
    _, _, _, _, _,  __, _,  _, _, _, _
),
[_NAVIGATION] = LAYOUT(
        // WinLeft, WinRight, LeftClick, RightClick
    Home, PgUp, Up,        PgDn,    End, _, _, _, TG(_MOUSE),       MO(_TG), MO(_RECTANGLE),   _,
    _, Left, Down,      Right,   _,  _, _, _, Esc, Tab, PrevApp, ChangeApp,
    _, WheelDown, WheelUp, Lang,  NewLine, _, _, _,           Shift, Alt,  Command,  _,
             _,    _,         _, DelWord,    _, __, _, _, _, _, _
),
[_TG] = LAYOUT(
    _, _,      SCUp,   _,         _, _, _, _,   _, _, _, _,
    _, SCLeft, SCDown, SCRight,   _, _, _, _,   _, _, _, _,
    _, _, _,      _,      _,         _, _,   _, _, _, _, _,
    _, _, _,      _,      _,          __,    _, _, _, _, _
),
[_RECTANGLE] = LAYOUT(
    _,  _,       Fullscreen, _, _,  _, _, _,  _, _, _, _,
    _, LeftHalf, Maximixe, RightHalf, _,  _, _, _,  _, _, _, _,
    _, _,  _, _, _, _, _, _, _, _, _, _,
    _,  _,  WinSmaller, WinLarger, _,   __, _, _, _,  _,  _
),
[_MOUSE] = LAYOUT(
    _,       _,     MUp,   _,         _, _, _, _, _, _, _, _,
    RightClick, MLeft, MDown, MRight, _, _, _, _, MSpeed0, MSpeed1, MSpeed2, TG(_MOUSE),
    _, WheelUp, WheelDown, LeftClick,  _, _, _, _, _, _, _, _,
    _,       _,     _,     _, _, __, _, _, _, _, _
),
};
