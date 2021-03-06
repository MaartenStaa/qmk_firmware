#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define ______ KC_TRNS

enum {
  TD_CAPS_L2 = 0
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Caps Lock, twice for layer 2
  [TD_CAPS_L2] = ACTION_TAP_DANCE_DUAL_ROLE(KC_CAPS, 2)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | GEsc|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * | Caps/L2 |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Shift/Up    |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl |  Alt  |  Cmd  |          LT(1, Space)             | Cmd |Alt/<- | Fnc/v |Ctrl/-> |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_60_ansi(
    KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    TD(TD_CAPS_L2), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_UP),
    KC_LCTL, KC_LALT, KC_LGUI, LT(1, KC_SPACE), KC_RGUI, MT(MOD_RALT, KC_LEFT), LT(3, KC_DOWN), MT(MOD_RCTL, KC_RIGHT)
  ),

  /* FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * | `/~ |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  Delete   |
   * |-----------------------------------------------------------------------------------------+
   * |        |     | Up  | Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |     |  F13 |  F14 |  F15 |
   * |-----------------------------------------------------------------------------------------+
   * |         |Left | Down|Right| BL+ | BL- |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |      |       |       |                                   |     |      |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_60_ansi(
    KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,
    ______, ______, KC_UP, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______, ______, KC_F13, KC_F14, KC_F15,
    ______, KC_LEFT, KC_DOWN, KC_RIGHT, BL_INC, BL_DEC, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______, ______, ______,         ______,         ______, ______, ______, ______
  ),

  /* Numpad layer
   * ,-----------------------------------------------------------------------------------------.
   * |     |     |  /  |  *  |  -  |     |     |     |     |     |     |     |     |           |
   * |-----------------------------------------------------------------------------------------+
   * |        |  7  |  8  |  9  |  +  |     |     |     |     |     |     |      |      |      |
   * |-----------------------------------------------------------------------------------------+
   * | L0      |  4  |  5  |  6  |  E  |     |     |     |     |     |     |     |             |
   * |-----------------------------  n  -------------------------------------------------------+
   * |           |  1  |  2  |  3  |  t  |     |     |     |     |     |     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |       |       |   0   |                                 |       |       |       |       |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_60_ansi(
    TO(0),  ______, KC_PSLS, KC_PAST, KC_PMNS, ______, ______, ______, ______, ______, ______, ______, ______,         ______,
    ______,         KC_P7,  KC_P8,   KC_P9,   KC_PPLS, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______,         KC_P4,  KC_P5,   KC_P6,   KC_PENT, ______, ______, ______, ______, ______, ______, ______, ______,
    ______,         KC_P1,  KC_P2,   KC_P3,   KC_PENT, ______, ______, ______, ______, ______, ______,         ______,
    ______, KC_P0,          KC_P0,                     ______,                         ______, ______,         ______, ______
  ),

  /* Another FN Layer
   * ,-----------------------------------------------------------------------------------------.
   * |RESET|     |     |     |     | Play| Stop| Prev| Next| Mute| Vol-| Vol+|     |  LockScr  |
   * |-----------------------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     | Play |      |      |      |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     |     |     |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |     |     |     |     |     |     |     |     |     |     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |       |       |       |                                 |       |       |       |       |
   * `-----------------------------------------------------------------------------------------'
   */

  LAYOUT_60_ansi(
    RESET,  ______, ______, ______, ______, KC_MPLY, KC_MSTP, KC_MRWD, KC_MFFD, KC__MUTE, KC__VOLDOWN, KC__VOLUP, ______, LCTL(LSFT(KC_EJCT)),
    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_MPLY, ______, ______, ______,
    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
    ______,         ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,
    ______, ______,         ______,                 ______,                         ______, ______,         ______, ______
  )
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
