#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
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

#define PrevDisplay LCAG(_P)
#define NextDisplay LCAG(_N)
#define LeftHalf LCAG(Left)
#define RightHalf LCAG(Right)
#define TopHalf LCAG(Up)
#define BottomHalf LCAG(Down)
#define Maximixe LCAG(_M)
#define Center LCAG(_C)
#define WinSmaller LCAG(Minus)
#define WinLarger LCAG(Equal)

#define _RF LALT(KC_S) // ф
#define _RU LALT(KC_T) // ю
#define _RH LALT(KC_F) // ш
#define _RC LALT(KC_P) // щ
#define _RT LALT(KC_C) // ъ
#define _RE LALT(KC_D) // э

enum custom_keycodes {
  CODE_ARRAY = SAFE_RANGE,
  CODE_TO,
  CODE_NOT_EQ,
  CODE_START,
  RU_II,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case CODE_ARRAY:
      if (record->event.pressed) { SEND_STRING("=>"); } return false;
    case CODE_TO:
      if (record->event.pressed) { SEND_STRING("->"); } return false;
    case CODE_NOT_EQ:
      if (record->event.pressed) { SEND_STRING("!=="); } return false;
    case CODE_START:
      if (record->event.pressed) { SEND_STRING("<?"); } return false;
    case RU_II:
      if (record->event.pressed) {
          register_code(KC_LALT);
          tap_code(KC_S);
          tap_code(KC_T);
          unregister_code(KC_LALT);
      }
      return false;
  }
  return true;
}

const uint16_t PROGMEM enter[] =     {KC_H, KC_E, COMBO_END};
const uint16_t PROGMEM newline[] =   {KC_K, KC_A, COMBO_END};
const uint16_t PROGMEM backspace[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM delword[] =   {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM esc[] =       {KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM tab[] =       {KC_W, KC_F, COMBO_END};

const uint16_t PROGMEM cmd[] =         {KC_H, KC_Z, COMBO_END};
const uint16_t PROGMEM control[] =     {Space, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM shift[] =       {KC_S, KC_G, COMBO_END};
const uint16_t PROGMEM cmdcontrol[] =  {Space, KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM shiftcmd[] =    {Space, KC_S, KC_D, COMBO_END};

const uint16_t PROGMEM cmd2[] =        {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM control2[] =    {KC_L, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM shift2[] =      {KC_M, KC_E, COMBO_END};
const uint16_t PROGMEM cmdcontrol2[] = {KC_L, KC_A, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM shiftcmd2[] =   {KC_L, KC_H, KC_E, COMBO_END};

const uint16_t PROGMEM rcmd[] =        {KC_A, KC_E, KC_I, COMBO_END};

const uint16_t PROGMEM n0[] =            {KC_D, KC_O, COMBO_END};
const uint16_t PROGMEM n1[] =            {KC_D, KC_J, COMBO_END};
const uint16_t PROGMEM n2[] =            {KC_D, KC_U, COMBO_END};
const uint16_t PROGMEM n3[] =            {KC_D, KC_Y, COMBO_END};
const uint16_t PROGMEM n4[] =            {KC_D, KC_A, COMBO_END};
const uint16_t PROGMEM n5[] =            {KC_D, KC_E, COMBO_END};
const uint16_t PROGMEM n6[] =            {KC_D, KC_I, COMBO_END};
const uint16_t PROGMEM n7[] =            {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM n8[] =            {KC_D, KC_Z, COMBO_END};
const uint16_t PROGMEM n9[] =            {KC_D, KC_Q, COMBO_END};
const uint16_t PROGMEM equal[] =         {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM minus[] =         {KC_D, KC_M, COMBO_END};
const uint16_t PROGMEM plus[] =          {KC_D, KC_L, COMBO_END};

const uint16_t PROGMEM exlm[] =          {KC_T, KC_J, COMBO_END};
const uint16_t PROGMEM question[] =      {KC_T, KC_U, COMBO_END};
const uint16_t PROGMEM minus2[] =        {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM dot[] =           {KC_T, KC_A, COMBO_END};
const uint16_t PROGMEM comma[] =         {KC_T, KC_E, COMBO_END};
const uint16_t PROGMEM quote[] =         {KC_T, KC_I, COMBO_END};
const uint16_t PROGMEM dquote[] =        {KC_T, KC_O, COMBO_END};
const uint16_t PROGMEM colon[] =         {KC_T, KC_H, COMBO_END};
const uint16_t PROGMEM semicolon[] =     {KC_T, KC_Z, COMBO_END};
const uint16_t PROGMEM code_to[] =       {KC_T, KC_M, COMBO_END};
const uint16_t PROGMEM code_array[] =    {KC_T, KC_L, COMBO_END};
const uint16_t PROGMEM code_start[] =    {KC_T, KC_Q, COMBO_END};
const uint16_t PROGMEM code_not_eq[] =   {KC_T, KC_K, COMBO_END};

const uint16_t PROGMEM asterisk[] =      {KC_S, KC_J, COMBO_END};
const uint16_t PROGMEM slash[] =         {KC_S, KC_U, COMBO_END};
const uint16_t PROGMEM underscore[] =    {KC_S, KC_Y, COMBO_END};
const uint16_t PROGMEM at[] =            {KC_S, KC_A, COMBO_END};
const uint16_t PROGMEM hash[] =          {KC_S, KC_E, COMBO_END};
const uint16_t PROGMEM caret[] =         {KC_S, KC_I, COMBO_END};
const uint16_t PROGMEM dollar[] =        {KC_S, KC_O, COMBO_END};
const uint16_t PROGMEM percent[] =       {KC_S, KC_K, COMBO_END};
const uint16_t PROGMEM backslash[] =     {KC_S, KC_H, COMBO_END};
const uint16_t PROGMEM tilda[] =         {KC_S, KC_Z, COMBO_END};
const uint16_t PROGMEM grave[] =         {KC_S, KC_Q, COMBO_END};
const uint16_t PROGMEM pipe[] =          {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM ampersand[] =     {KC_S, KC_M, COMBO_END};

const uint16_t PROGMEM lCBr[] =          {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM rCBr[] =          {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM lBr[] =           {KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM rBr[] =           {KC_F, KC_Z, COMBO_END};
const uint16_t PROGMEM lPrn[] =          {KC_F, KC_A, COMBO_END};
const uint16_t PROGMEM rPrn[] =          {KC_F, KC_E, COMBO_END};
const uint16_t PROGMEM lTag[] =          {KC_F, KC_I, COMBO_END};
const uint16_t PROGMEM rTag[] =          {KC_F, KC_O, COMBO_END};

const uint16_t PROGMEM alfred[] =     {KC_H, KC_Z, KC_Q, COMBO_END};
const uint16_t PROGMEM buffer[] =     {KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM reset[] =      {KC_L, KC_M, COMBO_END};

const uint16_t PROGMEM app_layer[] =              {_RH, KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM navigation_layer_block[] = {KC_M, KC_H, KC_E, COMBO_END};
const uint16_t PROGMEM tg_layer[] =               {KC_L, KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM mouse_layer_block[] =      {KC_H, KC_M, COMBO_END};
const uint16_t PROGMEM number_layer[] =           {KC_D, KC_G, COMBO_END};
const uint16_t PROGMEM rectangle_layer[] =        {KC_L, KC_U, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
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
    COMBO(shift, Shift),
    COMBO(shift2, Shift),
    COMBO(cmdcontrol, C(KC_LCMD)),
    COMBO(cmdcontrol2, C(KC_LCMD)),
    COMBO(shiftcmd, S(KC_LCMD)),
    COMBO(shiftcmd2, S(KC_LCMD)),
    COMBO(rcmd, ChangeApp),

    COMBO(n0, _0),
    COMBO(n1, _1),
    COMBO(n2, _2),
    COMBO(n3, _3),
    COMBO(n4, _4),
    COMBO(n5, _5),
    COMBO(n6, _6),
    COMBO(n7, _7),
    COMBO(n8, _8),
    COMBO(n9, _9),
    COMBO(equal, Equal),
    COMBO(minus, Minus),
    COMBO(plus, Plus),

    COMBO(question, Question),
    COMBO(exlm, Exlm),
    COMBO(underscore, Underscore),
    COMBO(comma, Comma),
    COMBO(dot, Dot),
    COMBO(quote, Quote),
    COMBO(dquote, DQuote),
    COMBO(semicolon, Semicolon),
    COMBO(colon, Colon),
    COMBO(code_array, CODE_ARRAY),
    COMBO(code_start, CODE_START),
    COMBO(code_not_eq, CODE_NOT_EQ),
    COMBO(code_to, CODE_TO),

    COMBO(asterisk, Asterisk),
    COMBO(slash, Slash),
    COMBO(minus2, Minus),
    COMBO(at, At),
    COMBO(hash, Hash),
    COMBO(caret, Caret),
    COMBO(dollar, Dollar),
    COMBO(percent, Percent),
    COMBO(backslash, BackSlash),
    COMBO(tilda, Tilda),
    COMBO(grave, Grave),
    COMBO(pipe, Pipe),
    COMBO(ampersand, Ampersand),

    COMBO(lCBr, KC_LCBR),
    COMBO(rCBr, KC_RCBR),
    COMBO(lBr, KC_LBRC),
    COMBO(rBr, KC_RBRC),
    COMBO(lPrn, KC_LPRN),
    COMBO(rPrn, KC_RPRN),
    COMBO(lTag, KC_LT),
    COMBO(rTag, KC_GT),

    COMBO(alfred, Alfred),
    COMBO(buffer, Buffer),

    COMBO(app_layer, MO(_APP)),
    COMBO(navigation_layer_block, TG(_NAVIGATION)),
    COMBO(tg_layer, MO(_TG)),
    COMBO(mouse_layer_block, TG(_MOUSE)),
    COMBO(number_layer, MO(_NUMBER)),
    COMBO(rectangle_layer, MO(_RECTANGLE)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
    _RT,  _W, _F, _P, _B,_, _, _J,_L,_U, _Y, Tmux,
    _N, _R, _S, _T, _G, _, _, _M,_A, _E, _I, _O,
    Lang,  _X, _C, _D, _V, _, _, _K, _H, _Z, _Q, _RU,
    _,  _,  _RF,_RH, MT(MOD_LSFT, Space),   __, MO(_NAVIGATION), _RE, _RC,_,  _
),
[_RECTANGLE] = LAYOUT(
    _,  PrevDisplay, TopHalf, NextDisplay, _,  _, _, _,  _, _, _, _,
    _, LeftHalf, BottomHalf, RightHalf, _,  _, _, _,  _, _, _, _,
    _,  Maximixe, Center, _, _, _, _, _, _, _, _, _,
    _,  _,  _,  WinSmaller, WinLarger,   __, _, _, _,  _,  _
),
[_APP] = LAYOUT(
// todo fix PrntSc buttons
    _, _, _, _, _, _, _, _, PrntSc1, PrntSc2, PrntSc3, _,
    _, _, _, _, _, _, _, _, LightDec, LightInc, SoundDec, SoundInc,
    _, _, _, _, _, _, _, MoveToBin, Smaller, Bigger, Settings, _,
    _, _, _, _,    _,   __, WinLeft, WinRight, _, _, _
),
[_NAVIGATION] = LAYOUT(
    _,         PgUp, Up,    PgDn,   _, _, _, _, _, _, _, _,
    LeftClick, Left, Down,  Right,  _, _, _, _, Command, Shift, Alt, TG(_NAVIGATION),
    _,         _,    _,     _, RightClick, _, _, _, Control, _,     _,   _,
    _,         _,    _,     Home,   End,    __,   Cut, Backspace, _, _, _
),
[_TG] = LAYOUT(
    _,         _, SCUp,    _,   _, _, _, _, _, _, _, _,
    WheelDown, SCLeft, SCDown,  SCRight,  _, _, _, _, _, _, _, _,
    _,         _,    _,     WheelUp, _, _, _, _, _, _,     _,   _,
    _,         _,    _,     _,   _,    __,   _, _, _, _, _
),
[_MOUSE] = LAYOUT(
    _,       _,     MUp,   _,         _, _, _, _, _, _, _, _,
    _, MLeft, MDown, MRight,    _, _, _, _, MSpeed0, MSpeed1, MSpeed2, TG(_MOUSE),
    _,       _,     _,     _, _, _, _, _, _, _, _, _,
    _,       _,     _,     LeftClick, WheelUp, __, WheelDown, RightClick, _, _, _
),
[_NUMBER] = LAYOUT(
    _,  _, _, _, _, _, _, _, _1, _2, _3, _,
    _, _, _, _, _, _, _, _, _4, _5, _6, _0,
    _,  _, _, _, _, _, _, Equal, _7, _8, _9, _,
    _,  _,  _,  _, _,   __,  Plus, Minus, _, _, _
),
};
