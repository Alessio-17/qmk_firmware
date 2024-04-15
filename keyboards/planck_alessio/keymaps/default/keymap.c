/* Copyright 2020 GiorgioCampiotti 3D Printed Planck
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

//#include "keymap_italian.h"


extern keymap_config_t keymap_config;

enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _FUNCTION,
  _ESC
};

// Servono per rendere più leggibile lo swith statement in process_record_user 
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT(// default layer
        LT(_ESC, KC_ESC), KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, 
        LT(_LAYER4, KC_TAB), KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, MT(MOD_LSFT, KC_ENT), 
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT, 
        _______, KC_LCTL, KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

[_QWERTY] = LAYOUT( // QWERTY layer
        _______, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, _______, 
        _______, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, _______, 
        _______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, _______, _______, _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

[_LOWER] = LAYOUT( // lower level
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, 
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, 
        KC_CAPS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCA(KC_BSPC), KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

[_RAISE] = LAYOUT( //reaise level 
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, 
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_UNDERSCORE, KC_EQL, KC_AT, KC_GRAVE, 
        KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_MINUS, KC_PLUS, KC_BSLS, KC_TRNS, 
        TG(_QWERTY), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

[_ADJUST] = LAYOUT( //mouse and other functions level, also activable with rasie+lower

        // KC_TRNS, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_7, KC_8, KC_9, KC_SLSH, KC_TRNS, 
        // KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_4, KC_5, KC_6, KC_MS_WH_UP, KC_TRNS, 
        // KC_CAPSLOCK, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_MS_WH_DOWN, KC_TRNS, 
        // KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MEDIA_PLAY_PAUSE, KC_0, KC_0, KC_DOT, KC_COMM, KC_TRNS),


    _______, RGB_MODE_KNIGHT,   UC_NEXT,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, _______,  _______, KC_TRANSPARENT, KC_SYSTEM_SLEEP ,
    _______, _______, _______, _______, _______, _______, _______, RGB_TOG,  RGB_VAD,  RGB_VAI, RGB_MODE_KNIGHT, QK_BOOT,
    _______, _______, _______, _______, _______, _______, _______, RGB_MOD,  RGB_HUD,  RGB_HUI, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, RGB_SAD,  RGB_SAI, _______, _______
),

[_LAYER4] = LAYOUT( //TAB
    LT(_FUNCTION,KC_ESCAPE),KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_MS_WH_UP,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_MS_WH_DOWN,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT, KC_0,           KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT
  ),

[_FUNCTION] = LAYOUT( //Function Key

        TO(_QWERTY), RGB_TOG, RGB_MOD, RGB_HUI, KC_TRNS, RGB_MODE_PLAIN, KC_TRNS, KC_TRNS, SGUI(KC_R), KC_TRNS, KC_PSCR, KC_SLEP, 
        TG(_ADJUST), AU_TOGG, MU_TOGG, MU_NEXT, CK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MODE_KNIGHT, KC_TRNS, KC_PGUP, KC_WAKE, 
        KC_TRNS, _______, _______, RCS(KC_C), LCTL(KC_V), KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAGE_DOWN, QK_BOOT, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_LOWER), KC_MEDIA_PLAY_PAUSE, TG(_RAISE), KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT),

[_ESC] = LAYOUT( //ESC Key used for accent and some special key/functions

        KC_TRNS, UC_NEXT, UC_WINC, UC(0x000E8), _______, KC_TILDE, KC_TRNS, UC(0x000F9), UC(0x000EC), UC(0x000F2), KC_TRNS, KC_TRNS, 
        KC_TRNS, UC(0x000E0), UC(0x020AC), UC(0x000B0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UC_LINX, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, UC(0x30C4), _______, KC_TRNS, KC_TRNS, _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_LOWER), KC_TRNS, TG(_RAISE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, HSV_RED}       // Light 4 LEDs, starting with LED 6
  //  {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
const rgblight_segment_t PROGMEM my_QWERTY_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_ORANGE}       // Light 4 LEDs, starting with LED 6
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_LOWER_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_RAISE_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_PURPLE}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active

const rgblight_segment_t PROGMEM my_ADJUST_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_GREEN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active

const rgblight_segment_t PROGMEM my_LAYER4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_FUNCTION_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_YELLOW}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_QWERTY_layer,
    my_LOWER_layer,    // Overrides caps lock layer
    my_RAISE_layer,    // Overrides other layers
    my_ADJUST_layer,    // Overrides other layers
    my_LAYER4_layer,     // Overrides other layers
    my_FUNCTION_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(5, layer_state_cmp(state, _LAYER4));
    rgblight_set_layer_state(6, layer_state_cmp(state, _FUNCTION));


 //return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        //    PLAY_SONG(s1);
        #endif //AUDIO_ENABLE
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
      
    case RAISE:
      if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
         //   PLAY_SONG(s2);
        #endif //AUDIO_ENABLE
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;    
  }
  return true;
}

