#include "dz60.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ISO 6u layout layer 0
* ,-----------------------------------------------------------------------------------------.
* | Esc |  ` | 1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  ß  |     BSPC    |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  Q  |  W  |  E  |  R  |  T  |  Z  |  U  |  I  |  O  |  P  |  P  |  Ü  | *  |   |
* |-------------------------------------------------------------------------------------|   +
* | Layer_2    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Ö  |  Ä |  # |Enter |
* |-----------------------------------------------------------------------------------------+
* | PRSCR | SHIFT |  Y  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  .  | RShift | F2 |
* |-----------------------------------------------------------------------------------------+
* | LCtrl |  LGUI  |  LAlt  |          Space           |  RAlt  |  RGUI  | Layer_1 |  RCtrl |
* `-----------------------------------------------------------------------------------------'
*/
	LAYOUT(
		KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, 
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
		LT(1,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_PSCR, 
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT,KC_RGUI, KC_NO, DF(1), KC_RCTL),

	LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS, 
		KC_TAB, KC_NO, KC_UP, KC_NO, RGB_M_R, KC_NO, KC_NO, KC_NO, KC_NO, RGB_M_SW, RGB_M_P, KC_NO, KC_NO, KC_NO,
		KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, RGB_M_G, KC_NO, KC_NO, RGB_M_K, KC_NO, KC_NO, KC_NO, KC_ENT, 
		MO(2),KC_LSFT,  KC_NO, RGB_M_X, KC__VOLUP, KC__VOLDOWN, KC_NO, KC_NO, KC__MUTE, KC_MPRV, KC_MNXT, KC_MPLY, DF(2), KC_PAUS, 
		KC_LCTL, KC_LGUI, KC_MENU, KC_NO, KC_NO, KC_NO, KC_RALT, KC_APP, KC_NO, DF(0), KC_RCTL),

	LAYOUT(
		RGB_TOG, RGB_MOD, RGB_RMOD, KC_NO, RGB_HUI, RGB_HUD, KC_NO, RGB_SAI, RGB_SAD, KC_NO, KC_NO, RGB_VAI, RGB_VAD, ALTG(KC_DEL), KC_EJCT, 
		KC_NO, KC_NO, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_TRNS,KC_LSFT,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_S_N, KC_NO, KC_NO, KC_NO, MO(3), KC_TRNS, KC_SLCK,
		KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(0), KC_NO),

	LAYOUT(
		KC_TILD,  KC_MPRV,   KC_MPLY,  KC_MNXT, M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), KC_DEL, KC_INS, 
		KC_PGUP, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, 
		KC_NO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
		KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DF(0), KC_NO),

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
