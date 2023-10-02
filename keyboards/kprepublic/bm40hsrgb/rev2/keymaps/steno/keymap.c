#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _SYMBOL,
  _NUMBER,
  _NAVIGATION,
  _TG,
  _MOUSE,
  _APP,
  _APP2,
  _RECTANGLE,
};

enum my_keycodes {
  CHANGE_APP = SAFE_RANGE,
  CODE_ARRAY,
  CODE_TO,
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
#define _A CTL_T(KC_A)
#define _R KC_R
#define _S KC_S
#define _T CTL_T(KC_T)
#define _G KC_G
#define _M KC_M
#define _N KC_N
#define _E KC_E
#define _I KC_I
#define _O KC_O
#define _Z KC_Z
#define _X KC_X
#define _C KC_C
#define _D CMD_T(KC_D)
#define _V KC_V
#define _K KC_K
#define _H CMD_T(KC_H)

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
#define NextWindow LCMD(KC_GRV)
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
#define DelLine LCMD(Backspace)

#define Alfred HYPR(Space)
#define AlfredP HYPR(KC_P)
#define AlfredL HYPR(KC_L)
#define AlfredPrev HYPR(KC_F)
#define AlfredActions HYPR(KC_A)
#define Buffer HYPR(KC_V)

#define Tmux LCTL(KC_A)
#define ViW LCTL(KC_W)
#define Smaller LCMD(Minus)
#define Bigger LCMD(Plus)
#define Settings LCMD(Comma)
#define MoveToBin LCMD(Backspace)

#define LeftHalf LCAG(Left)
#define RightHalf LCAG(Right)
#define Maximixe LCAG(_M)
#define WinSmaller LCAG(Minus)
#define WinLarger LCAG(Equal)
#define Fullscreen LCMD(LCTL(_F))

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _T:
        case _D:
        case _A:
        case _H:
            // Do not select the hold action when another key is pressed.
            return false;
        default:
            // Immediately select the hold action when another key is pressed.
            return true;
    }
}

uint16_t change_app_timer = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CODE_ARRAY:
      if (record->event.pressed) { SEND_STRING(" => "); } return false;
    case CODE_TO:
      if (record->event.pressed) { SEND_STRING("->"); } return false;
    case CHANGE_APP:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        register_code(KC_RALT);
        register_code(KC_RCMD);
        change_app_timer = timer_read();
      } else {
        unregister_code(KC_RSFT);
        unregister_code(KC_RALT);
        unregister_code(KC_RCMD);
        if (timer_elapsed(change_app_timer) < 200) {
          register_code(KC_LCMD);
          tap_code(KC_TAB);
          unregister_code(KC_LCMD);
        }
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}

#define _RF LALT(KC_1)  // ф
#define _RYA LALT(KC_2) // я
#define _RJ LALT(KC_3)  // ж
#define _RZ LALT(KC_4)  // з
#define _RT LALT(KC_5)  // ъ
#define _RE LALT(KC_6)  // э
#define _RB LALT(KC_7)  // б
#define _RYU LALT(KC_8)  // ю

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_ALPHA] = LAYOUT(
    _Q, _W, _F, _P, _B, _, _, _J, _L, _U, _Y, _RZ,
    _N, _R, _S, _T, _G, _, _, _M, _A, _E, _I, _O,
    _Z, _X, _C, _D, _V, _, _, _K, _H, _RB, _RYU, _RJ,
    _, _,
    MO(_APP), LT(_NUMBER, Backspace), MT(MOD_LSFT, Space),
    __,
    LT(_SYMBOL, Enter), LT(_NAVIGATION, Esc), MO(_APP2), _, _
),
[_NUMBER] = LAYOUT(
    /*
     * KC_LBRC [ ] KC_RBRC
     * KC_LPRN ( ) KC_RPRN
     * KC_LCBR { } KC_RCBR
     * KC_LT < > KC_GT
     */
    _, _,  KC_LPRN, KC_RPRN, _, _, _, _, KC_LCBR, KC_RCBR, _, _,
    _0, _1, _2, _3, _, _, _, KC_LBRC, _5, _6, _7, _9,
    _, KC_LT,  KC_GT, _4, _, _, _, KC_RBRC, _8, CODE_TO, CODE_ARRAY, _,
    _,  _,  _, _,  _, __, NewLine, Tab, TG(_NUMBER), _, _
),
[_SYMBOL] = LAYOUT(
    _, Minus, Slash, Asterisk,   _, _, _, _,   Exlm, Question, Underscore, _,
    Equal, BackSlash, Caret, Dollar, Tilda, _, _, Ampersand,   Dot, Comma, Quote, DQuote,
    _, Percent, Hash, At, Grave, _, _, Pipe,   Colon, Semicolon, Plus, _,
    _, _, _, MO(_NUMBER), MT(MOD_LSFT, Space),  _,  _, _,  _, _, _
),
[_APP] = LAYOUT(
    _, QK_BOOT, AlfredActions, AlfredPrev, _, _, _, _, PrntSc1, PrntSc2, PrntSc3, _,
    _, _, Buffer, Alfred, _, _, _, _, LightDec, LightInc, SoundDec, SoundInc,
    _, _, AlfredP, AlfredL, _, _, _, MoveToBin, Smaller, Bigger, Settings, _,
    _, _, _, _,    _,   __, _, _, _, _, _
),
[_APP2] = LAYOUT(
    _, ViW, KC_LBRC, _, _, _, _, _, _, _, _, _,
    _, _RT, KC_RBRC, _RF, _, _, _, _, Tmux, _, _, _,
    _, _, _, _, _, _, _, _, _, _, _, _,
    _, _, _, _, KC_LSFT,  __, _,  _, _, _, _
),
[_NAVIGATION] = LAYOUT(
    _, PgUp, Up,        PgDn,    _, _, _, TG(_NUMBER), TG(_MOUSE),       MO(_TG), MO(_RECTANGLE),   _,
    _, Left, Down,      Right,   Home,  _, _, _, CHANGE_APP, NextWindow, Alt,  Command,
    _, WheelDown, WheelUp, Lang, End, _, _, _,           Shift, _,  _,  _,
             _,    _,         _, DelWord,    DelLine, __, _, _, _, _, _
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
    RightClick, MLeft, MDown, MRight, _, _, _, _, MSpeed0, MSpeed1, MSpeed2, _,
    _, WheelUp, WheelDown, LeftClick,  _, _, _, _, _, _, _, _,
    _,       _,     _,     _, _, __, _, TG(_MOUSE), _, _, _
),
};
