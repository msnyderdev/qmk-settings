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

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define TAB_MEH MEH_T(KC_TAB)

// Right-hand home row mods
#define HOME_TAB RCTL_T(KC_TAB)

#define KC_QUEST LSFT(KC_SLSH)

#define GAMING TG(3)
#define DEFAULT TG(0)

enum combos {
  WE_LBRC,
  ER_RBRC,
  UI_MINUS,
  UI_EQUAL
};

const uint16_t PROGMEM rbrck_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM lbrck_combo[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM dash_combo[] =  {KC_I, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM equal_combo[] = {KC_Y, KC_U, KC_I, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [WE_LBRC] = COMBO(lbrck_combo, KC_LBRC),
  [ER_RBRC] = COMBO(rbrck_combo, KC_RBRC),
  [UI_MINUS] = COMBO(dash_combo, KC_MINUS),
  [UI_EQUAL] = COMBO(equal_combo, KC_EQUAL)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,      KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      HOME_TAB, HOME_A,  HOME_S,   KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,  KC_K,     KC_L,   KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,   KC_BSLASH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              MO(2), MO(1), KC_SPC,    KC_ENT, HOME_TAB, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------;;------------------------.                  ,-----------------------------------------------------.
      KC_GRV, KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TAB_MEH, KC_LCTRL, KC_LSFT, KC_LALT, KC_LGUI, KC_MINUS,                  KC_MINUS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_EQUAL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_LBRC, KC_RCBR                  XXXXXXX,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,   LSFT(KC_INS),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+vvcvccc--------+--------+--------|
                                          _______, _______,  KC_SPC,   KC_HOME,  KC_TAB, KC_END
                                      //`--------------------------'  `--------------------------=+
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F1,   KC_F2,    KC_F3,  KC_F4,    KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,
  //|--------+--------+--------+--------+--------+---------|                   |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_MODE_FORWARD, DEFAULT, GAMING, A(KC_PSCR),         KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_QUEST, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,   KC_LGUI,  KC_SPC,   KC_ENT, KC_TAB, KC_RALT
                                      //`--------------------------'  `-------------------------
  ),
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,      KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,  KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN,   KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,   TO(0),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_LCTL, KC_LSFT, KC_SPC,    KC_ENT, KC_TAB, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {


    return OLED_ROTATION_180;  // flips the drisplay 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    switch (get_highest_layer(layer_state)){
        case 0:
            oled_write_ln_P(PSTR("Working"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Special"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("Peak Performance Mode"), false);
            break;
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
}

// representation of active modifiers.

#endif // OLED_DRIVER_ENABLE