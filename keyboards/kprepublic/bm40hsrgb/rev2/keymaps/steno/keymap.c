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
#define Buffer HYPR(_V)
#define Tmux LCTL(_A)
#define Smaller LCMD(Minus)
#define Bigger LCMD(Plus)
#define Settings LCMD(Comma)
#define MoveToBin LCMD(Backspace)
#define WinLeft LCTL(Left)
#define WinRight LCTL(Right)

// #define PrevDisplay LCAG(_P)
// #define NextDisplay LCAG(_N)
// #define TopHalf LCAG(Up)
// #define BottomHalf LCAG(Down)
// #define Center LCAG(_C)
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

enum custom_keycodes {
  CODE_ARRAY = SAFE_RANGE,
  CODE_TO,
  CODE_NOT_EQ,
  CODE_START,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case CODE_ARRAY:
      if (record->event.pressed) { SEND_STRING(" => "); } return false;
    case CODE_TO:
      if (record->event.pressed) { SEND_STRING("->"); } return false;
    case CODE_NOT_EQ:
      if (record->event.pressed) { SEND_STRING(" !== "); } return false;
    case CODE_START:
      if (record->event.pressed) { SEND_STRING("<?php\n"); } return false;
  }
  return true;
}

const uint16_t PROGMEM alfred[] =     {KC_H, KC_Z, KC_Q, COMBO_END};
const uint16_t PROGMEM buffer[] =     {KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM reset[] =      {MO(_NUMBER), KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM app_layer[] =  {MO(_NUMBER), KC_W, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(alfred, Alfred),
    COMBO(buffer, Buffer),
    COMBO(reset, QK_BOOT),
    COMBO(app_layer, MO(_APP)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
    _, _RI, _W, _F, _P, _B, _J,_L,_U, _Y, _RZ, _,
    _, _N, _R, _S, _T, _G, _M, _A, _E, _I, _O, _,
    _RF, _RY, _X, _C, _D, _V , _K, _H, _Z, _Q, _RH,_RT,
    _,  _, MO(_APP), _, MO(_NUMBER),   MT(MOD_LSFT, Space),   MO(_NAVIGATION), Control,_,_,_
),
[_NUMBER] = LAYOUT(
    _, _, KC_LCBR,  _0, KC_LPRN, _, _, KC_RPRN, _9, KC_RCBR, _, _,
    _, KC_LBRC, _1, _2, _3, _, _, _5, _6, _7, KC_RBRC, _,
    _, KC_LT, _,  _, _4, _, _, _8, _, _, KC_GT, _,
    _,  _,  _,  _, _,  Control,  MO(_SYMBOL), _, _, _, _
),
[_SYMBOL] = LAYOUT(
    _, _, Minus, Slash, Asterisk,   _, _,   Exlm, Question, Underscore, _,_,
    _, Tilda, BackSlash, Hash, At, _, Ampersand,   Dot, Comma, Quote, DQuote,_,
    _, Percent, Grave, Caret, Dollar, _, Pipe,   Colon, Semicolon, Plus, Equal,_,
    _, _, _, _, _,  _,  _, _,  _, _, _
),
[_APP] = LAYOUT(
    _, _, _, _, _, _, _, PrntSc1, PrntSc2, PrntSc3, _, _,
    _, _, _, _, _, _, _, LightDec, LightInc, SoundDec, SoundInc, _,
    _, _, _, _, _, _, MoveToBin, Smaller, Bigger, Settings, _, _,
    _, _, _, _,    _,   __, _, _, _, _, _
),
[_NAVIGATION] = LAYOUT(
        // WinLeft, WinRight, LeftClick, RightClick
    _, Home, PgUp, Up,        PgDn,    End, _, TG(_MOUSE),       MO(_TG), MO(_RECTANGLE),   _,_,
    _, DelWord, Left, Down,      Right,   _,  _, Esc, Tab, PrevApp, ChangeApp,_,
    _, Lang, WheelDown, WheelUp, Enter,  NewLine, _,           Shift, Alt,  Command,  _,_,
    _,         _,    _,         _, Backspace,    Command, _, _, _, _, _
),
[_TG] = LAYOUT(
    _, _, _,      SCUp,   _,         _, _,   _, _, _, _, _,
    _, _, SCLeft, SCDown, SCRight,   _, _,   _, _, _, _, _,
    _, _, _,      _,      _,         _, _,   _, _, _, _, _,
    _, _, _,      _,      _,          __,    _, _, _, _, _
),
[_RECTANGLE] = LAYOUT(
    _, _,  _,       Fullscreen, _, _,  _,  _, _, _, _, _,
    _, _, LeftHalf, Maximixe, RightHalf, _,  _,  _, _, _, _, _,
    _, _,  _, _, _, _, _, _, _, _, _, _,
    _,  _,  _,  WinSmaller, WinLarger,   __, _, _, _,  _,  _
),
[_MOUSE] = LAYOUT(
    _, _,       _,     MUp,   _,         _, _, _, _, _, _, _,
    _, _, MLeft, MDown, MRight,    _, _, MSpeed0, MSpeed1, MSpeed2, TG(_MOUSE), _,
    _, _,       _,     _,     _,  _, _, _, _, _, _, _,
    _,       _,     _,     LeftClick, WheelUp, __, WheelDown, RightClick, _, _, _
),
};
