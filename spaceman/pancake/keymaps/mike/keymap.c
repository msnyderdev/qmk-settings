#include QMK_KEYBOARD_H
enum layers {
  _DEFAULT,
  _LOWER,
  _RAISE,
  _FN
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_ESC LALT_T(KC_ESC)
#define TAB_MEH MEH_T(KC_TAB)

// Right-hand home row mods
#define HOME_TAB LSFT_T(KC_TAB)

#define KC_QUEST LSFT(KC_SLSH)

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

/* Default
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   "  |  ;   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |  FN  | Lower|    Space    |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DEFAULT] = LAYOUT_ortho_4x12(
    HOME_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,       KC_O,      KC_P,     KC_BSPC,
    KC_LCTRL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,     KC_K,       KC_L,      KC_SCLN,  KC_QUOT,
    HOME_TAB, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,    KC_DOT,    KC_SLSH,  KC_BSLS,
    KC_LALT,  KC_LGUI, FN,      LOWER,   RAISE,   KC_SPC,  KC_SPC,  KC_ENT,   KC_LBRC,    KC_RBRC,   KC_MINUS, KC_EQUAL
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   _  |   +  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   {  |   }  | Vol+ |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   ?  |      | Vol- |      |   
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_UNDS,  KC_PLUS
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  -   |   =   |     |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   [  |   ]  | Vol- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      | Vol+ |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
),
 
 /* FN
 * ,-----------------------------------------------------------------------------------.
 * | Reset| F1   |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |  F11 |  F12 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | TRNS |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
),


};

