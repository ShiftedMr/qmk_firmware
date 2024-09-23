/* Copyright 2021 shiftedmr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _MOD1,
    _MOD2
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
  //,-----------+--------+--------+-------+-------+-------+------+-------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------.
	KC_GRV      , KC_1   , KC_2   , KC_3  , KC_4  , KC_5  , KC_6 , KC_7  , KC_8  , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_BSPC, KC_NLCK, KC_PSLS, KC_PAST,KC_PMNS,
  //|-----------+--------+--------+-------+-------+-------+------+-------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
	KC_TAB      , KC_Q   , KC_W   , KC_E  , KC_R  , KC_T  , KC_Y , KC_U  , KC_I  , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, KC_MUTE, KC_KP_7, KC_KP_8, KC_KP_9,KC_PPLS,
  //|-----------+--------+--------+-------+-------+-------+------+-------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
	LT(_MOD1,KC_ESC), KC_A   , KC_S   , KC_D  , KC_F  , KC_G  , KC_H , KC_J  , KC_K  , KC_L   , KC_SCLN, KC_QUOT, KC_ENT , KC_ENT , KC_PSCR , KC_KP_4, KC_KP_5, KC_KP_6,KC_PPLS,
  //|-----------+--------+--------+-------+-------+-------+------+-------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
    KC_LSFT     , KC_LSFT, KC_Z   , KC_X  , KC_C  , KC_V  , KC_B , KC_N  , KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_RSFT, KC_PAUS, KC_KP_1, KC_KP_2, KC_KP_3,KC_PENT,
  //|-----------+--------+--------+-------+-------+-------+------+-------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-------|
    KC_LCTL     , KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_NO, KC_SPC, KC_SPC, KC_SPC , KC_RALT, KC_RGUI, KC_APP , KC_RCTL, KC_BRK, KC_KP_0, KC_KP_0, KC_PDOT,KC_PENT
  //`-----------+--------+--------+-------+-------+-------+------+-------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
  ),
    [_MOD1] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+-------+--------+-------.
     KC_ESC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_INS,         XXXXXXX,KC_MPRV,KC_MNXT,KC_VOLD,
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+-------+-------+-------.
     _______,XXXXXXX, KC_UP ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,         XXXXXXX,XXXXXXX,XXXXXXX,KC_VOLU,
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+-------+-------+-------.
     _______,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,         XXXXXXX,KC_MSTP,KC_MPLY,KC_VOLU,
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+-------+-------+-------.
     MO(_MOD2)  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,         XXXXXXX,XXXXXXX,XXXXXXX,KC_VOLD,
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+------+--------+-------+--------+------+-------+-------.
     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,         KC_MUTE,KC_MUTE,KC_MUTE,KC_MUTE
  ),
    [_MOD2] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+-------+--------+-------.
     KC_ESC ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, BL_DEC, BL_INC, BL_OFF, BL_ON ,         XXXXXXX,KC_MPRV,KC_MNXT,KC_VOLD,
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+-------+-------+-------.
     _______,XXXXXXX,KC_PGUP,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,BL_BRTG,         XXXXXXX,XXXXXXX,XXXXXXX,KC_VOLU,
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+-------+-------+-------.
     _______,KC_HOME,KC_PGDN,KC_END ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,         XXXXXXX,KC_MSTP,KC_MPLY,KC_VOLU,
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+-------+-------+-------+-------.
     _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,BL_STEP,         XXXXXXX,XXXXXXX,XXXXXXX,KC_VOLD,
  //,-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------+------+--------+-------+--------+------+-------+-------.
     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,         KC_MUTE,KC_MUTE,KC_MUTE,KC_MUTE
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
