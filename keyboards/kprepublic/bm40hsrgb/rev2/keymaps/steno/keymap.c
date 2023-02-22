#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _NUMBER,
  _SYMBOL,
  _SYMBOL2,
  _BRACKETS,
  _NAVIGATION,
  _CP,
  _APP,
  _RGB,
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

#define LeftClick KC_BTN1

#define Space KC_SPC
#define Backspace KC_BSPC
#define Delete KC_DEL
#define Command KC_LCMD
#define ChangeApp RSFT(RALT(KC_RCMD))
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

#define PrntSc1 LCAG(_1)
#define PrntSc2 LCAG(_2)
#define PrntSc3 LCAG(_3)

#define NewLine LSFT(Enter)
#define DelWord LALT(Backspace)

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

const uint16_t PROGMEM space[] =     {KC_A, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM enter[] =     {KC_H, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM newline[] =   {KC_K, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM backspace[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM delword[] =   {KC_R, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM esc[] =       {KC_W, KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM tab[] =       {KC_W, KC_F, KC_P, COMBO_END};

const uint16_t PROGMEM cmd[] =         {KC_B, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM control[] =     {KC_B, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM cmdcontrol[] =  {KC_B, KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM shiftcmd[] =    {KC_B, KC_S, KC_D, COMBO_END};

const uint16_t PROGMEM cmd2[] =        {KC_L, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM control2[] =    {KC_L, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM cmdcontrol2[] = {KC_L, KC_A, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM shiftcmd2[] =   {KC_L, KC_H, KC_E, COMBO_END};

const uint16_t PROGMEM alt[] =         {KC_H, KC_M, COMBO_END};
const uint16_t PROGMEM rcmd[] =        {KC_Z, KC_Q, COMBO_END};

const uint16_t PROGMEM tmux[] =       {KC_H, KC_Z, KC_Q, COMBO_END};
const uint16_t PROGMEM alfred[] =     {KC_J, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM buffer[] =     {KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM language[] =   {KC_A, KC_E, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM reset[] =      {KC_L, KC_M, COMBO_END};

const uint16_t PROGMEM app_layer[] =              {KC_G, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM symbol_layer[] =           {KC_G, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM symbol2_layer[] =          {KC_G, KC_S, KC_R, COMBO_END};
const uint16_t PROGMEM navigation_layer[] =       {KC_M, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM navigation_layer_block[] = {KC_M, KC_H, KC_E, COMBO_END};
const uint16_t PROGMEM number_layer[] =           {KC_M, KC_H, KC_Z, COMBO_END};
const uint16_t PROGMEM number_layer_block[] =     {KC_L, KC_H, KC_Z, COMBO_END};
const uint16_t PROGMEM brackets_layer[] =         {KC_M, KC_Z, KC_Q, COMBO_END};
const uint16_t PROGMEM cp_layer[] =               {KC_H, KC_Z, COMBO_END};
const uint16_t PROGMEM rgb_layer[] =              {KC_K, KC_H, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(space, Space),
    COMBO(backspace, Backspace),
    COMBO(delword, DelWord),
    COMBO(enter, Enter),
    COMBO(newline, NewLine),
    COMBO(tab, Tab),
    COMBO(esc, Esc),
    COMBO(reset, QK_BOOT),

    COMBO(cmd, Command),
    COMBO(cmd2, Command),
    COMBO(control, Control),
    COMBO(control2, Control),
    COMBO(cmdcontrol, C(KC_LCMD)),
    COMBO(cmdcontrol2, C(KC_LCMD)),
    COMBO(shiftcmd, S(KC_LCMD)),
    COMBO(shiftcmd2, S(KC_LCMD)),
    COMBO(rcmd, ChangeApp),
    COMBO(alt, Alt),

    COMBO(tmux, Tmux),
    COMBO(alfred, Alfred),
    COMBO(buffer, Buffer),
    COMBO(language, Lang),

    COMBO(app_layer, MO(_APP)),
    COMBO(symbol_layer, MO(_SYMBOL)),
    COMBO(symbol2_layer, MO(_SYMBOL2)),
    COMBO(navigation_layer, MO(_NAVIGATION)),
    COMBO(navigation_layer_block, TG(_NAVIGATION)),
    COMBO(number_layer, MO(_NUMBER)),
    COMBO(number_layer_block, TG(_NUMBER)),
    COMBO(brackets_layer, MO(_BRACKETS)),
    COMBO(cp_layer, MO(_CP)),
    COMBO(rgb_layer, MO(_RGB)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
    _,  _W, _F, _P, _,  _, _, _,  _J, _U, _Y, _,
    _N, _R, _S, _T, _,  _, _, _,  _A, _E, _I, _O,
    _,  _X, _C, _D, _V, _, _, _K, _H, _Z, _Q, _,
    _,  _,  _,  _G, _B,   __, _L, _M, _,  _,  _
),
[_APP] = LAYOUT(
    _, _, _, _, _, _, _, _, PrntSc1, PrntSc2, PrntSc3, _,
    _, _, _, _, _, _, _, _, LightDec, LightInc, SoundDec, SoundInc,
    _, _, _, _, _, _, _, _, Smaller, Bigger, Settings, _,
    _, _, _, _,    __,   _, _, MoveToBin, _, _, _
),
[_NAVIGATION] = LAYOUT(
    _,         PgUp, Up,    PgDn,   _, _, _, _, Esc, Tab, _, _,
    LeftClick, Left, Down,  Right,  _, _, _, _, Command, Shift, Alt, TG(_NAVIGATION),
    _,         _0,   Caret, Dollar, _, _, _, _, Control, _,     _,   _,
    _,         _,    _,     Home,   End,    __,   Space, Enter, _, _, _
),
[_NUMBER] = LAYOUT(
    _,  _1, _2, _3, _, _, _, _, Asterisk, Slash, Minus, _,
    _0, _4, _5, _6, _, _, _, _, Comma, Dot, _, TG(_NUMBER),
    _,  _7, _8, _9, Equal, _, _, _, Semicolon, Colon, _, _,
    _,  _,  _,  Plus, Minus,   __,  Backspace, Space, _, _, _
),
[_SYMBOL] = LAYOUT(
    _, _, _, _, _, _, _, _, Question,  Exlm,  Underscore,     _,
    _, _, _, _, _, _, _, _, Comma,     Dot,   Quote, DQuote,
    _, _, _, _, _, _, _, _, Semicolon, Colon, _,    _,
    _, _, _, _, _, __,  _, _, _, _, _
),
[_SYMBOL2] = LAYOUT(
    _, _, _, _, _, _, _, _,       Asterisk,  Slash,     Minus,  _,
    _, _, _, _, _, _, _, _,       At,        Hash,      Caret, Dollar,
    _, _, _, _, _, _, _, Percent, BackSlash, Tilda,     Grave,  _,
    _, _, _, _, _, ____, Pipe,    Ampersand, _,         _,      _
),
[_CP] = LAYOUT(
    _, _, _, _, _, _, _, _, _, _, _, _,
    SelectAll, Cut, Copy, Paste, _, _, _, _, _, _, _, _,
    _,  _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _
),
[_BRACKETS] = LAYOUT(
    _,      _,    KC_LCBR, KC_RCBR, _, _, _, _, _, _, _, _,
    KC_LT, KC_GT, KC_LPRN, KC_RPRN, _, _, _, _, _, _, _, _,
    _,     _,     KC_LBRC, KC_RBRC, _, _, _, _, _, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _
),
[_RGB] = LAYOUT(
    _, RGB_TOG, RGB_MOD, RGB_RMOD, _, _, _, _, _, _, _, _,
    RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _, _, _, _, _, _, _, _,
    _, RGB_VAI, RGB_VAD, _, _, _, _, _, _, _, _, _,
    _, _,  _, _, _,  _,  _, _, _, _, _
),
};
