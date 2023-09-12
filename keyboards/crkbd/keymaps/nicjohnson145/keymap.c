/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NUM_SYM,
    _ALT
};

#ifdef OLED_ENABLE

bool oled_task_user() {
    oled_set_cursor(0, 1);

    oled_write("Hello World!", false);

    return false;
}

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                        ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                             KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                        |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,   KC_M,  KC_COMM,  KC_DOT, KC_SLSH,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, KC_LALT, KC_LGUI,  MO(_NUM_SYM), KC_SPC, MO(_ALT)
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------.                    ,-----------------------------------------------------.
         KC_1,    KC_2,    KC_3,       KC_4,    KC_5,    KC_6,                         KC_7,       KC_8,       KC_9,       KC_0,         KC_NO, KC_TRNS,
  //|--------+--------+--------+-----------+--------+-----------|                    |--------+-----------+-----------+-----------+-----------+--------|
      KC_TRNS,   KC_NO,   KC_NO,     KC_EQL, S(KC_9),   KC_MINS,                       KC_GRV, S(KC_QUOT), S(KC_LBRC),    KC_LBRC, S(KC_BSLS),   KC_NO,
  //|--------+--------+--------+-----------+--------+-----------|                    |--------+-----------+-----------+-----------+-----------+--------|
      KC_TRNS,   KC_NO,   KC_NO,  S(KC_EQL), S(KC_0), S(KC_MINS),                       KC_EQL,    KC_QUOT, S(KC_RBRC),    KC_RBRC,    KC_BSLS,   TO(0),
  //|--------+--------+--------+-----------+--------+-----------+--------|  |--------+--------+-----------+-----------+-----------+-----------+--------|
                                             KC_TRNS,    KC_TRNS, KC_TRNS,      KC_NO,   KC_NO,    KC_NO
                                      //`-----------------------------'  `--------------------------'
  ),


    [_ALT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      DM_REC1, DM_REC2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_TRNS,                      DM_PLY1, DM_PLY2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EE_CLR,   TO(0),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,    DM_RSTP, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )
};


