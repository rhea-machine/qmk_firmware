/* Copyright (C) 2024  Rhéa Santos
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include "keymap_swiss_fr.h"

enum planck_layers {
    _QWERTZ,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    RH_QUES = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define QWERTZ PDF(_QWERTZ)
#define GAMING PDF(_GAMING)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTZ
     * ,-----------------------------------------------------------------------------------.
     * |TAB   |  Q   |  W   |  E   |  R   |  T   |  Z   |  U   |  I   |  O   |  P   |BKSP  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |ESC   |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ?   |  $   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |SHIFT |  Y   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  -   |SHIFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |CTRL  |  <   |GUI   |ALT   |LOWER |ENTER |SPACE |RAISE |ALT   |GUI   |      |CTRL  |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTZ] = LAYOUT_planck_grid(
        KC_TAB,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,    CH_Z,    CH_U,    CH_I,    CH_O,    CH_P,    KC_BSPC,
        KC_ESC,  CH_A,    CH_S,    CH_D,    CH_F,    CH_G,    CH_H,    CH_J,    CH_K,    CH_L,    RH_QUES, CH_DLR,
        KC_LSFT, CH_Y,    CH_X,    CH_C,    CH_V,    CH_B,    CH_N,    CH_M,    CH_COMM, CH_DOT,  CH_MINS, KC_RSFT,
        KC_LCTL, CH_LABK, KC_LGUI, KC_LALT, LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_RALT, KC_RGUI, _______, KC_RCTL
    ),

    /* GAMING
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |  7   |  8   |  9   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  4   |  5   |  6   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |  0   |  1   |  2   |  3   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |SPACE |SPACE |      |      |      |      |      |QWERTZ|      |
     * `-----------------------------------------------------------------------------------'
     */
    [_GAMING] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
        _______, _______, _______, _______, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   _______, _______,
        _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______, QWERTZ,  _______
    ),

    /* LOWER
     * ,-----------------------------------------------------------------------------------.
     * |      |      |  #   |  |   |  %   |      |      |  7   |  8   |  9   |      |DEL   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  /   |  *   |  -   |  +   |      |      |  4   |  5   |  6   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |  =   |      |  0   |  1   |  2   |  3   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |ADJUST|      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_grid(
        _______, _______, CH_HASH, CH_PIPE, CH_PERC, _______, _______, CH_7,    CH_8,    CH_9,    _______, KC_DEL,
        _______, CH_SLSH, CH_ASTR, CH_MINS, CH_PLUS, _______, _______, CH_4,    CH_5,    CH_6,    _______, _______,
        _______, _______, _______, _______, CH_EQL,  _______, CH_0,    CH_1,    CH_2,    CH_3,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* RAISE
     * ,-----------------------------------------------------------------------------------.
     * |      |  '   |  "   |  ~   |  `   |      |      |  [   |  ]   |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  @   |  &   |  ^   |  ´   |      |      |  (   |  )   |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |  ç   |  ¨   |      |      |  {   |  }   |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |ADJUST|      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        _______, CH_QUOT, CH_DQUO, CH_TILD, CH_GRV , _______, _______, CH_LBRC, CH_RBRC, _______, _______, _______,
        _______, CH_AT,   CH_AMPR, CH_CIRC, CH_ACUT, _______, _______, CH_LPRN, CH_RPRN, _______, _______, _______,
        _______, _______, _______, CH_CCED, CH_DIAE, _______, _______, CH_LCBR, CH_RCBR, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* ADJUST
     * ,-----------------------------------------------------------------------------------.
     * |      |RESET |DEBUG |RGB   |      |SAT-  |SAT+  |HUE-  |HUE+  |BRGHT-|BRGHT+|      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |AUDON |AUDOFF|      |      |GAMING|      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        _______, QK_BOOT, DB_TOGG, UG_TOGG, _______, UG_SATD, UG_SATU, UG_HUED, UG_HUEU, UG_VALD, UG_VALU, _______,
        _______, _______, _______, AU_ON,   AU_OFF,  _______, _______, GAMING,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // Custom behaviour for `?` (SHIFT + `?` -> `!`)
        case RH_QUES:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    register_code(CH_DIAE);
                } else {
                    register_mods(MOD_BIT(KC_LSFT));
                    register_code(CH_QUOT);
                }
            } else {
                unregister_mods(MOD_BIT(KC_LSFT));
                unregister_code(CH_DIAE);
                unregister_code(CH_QUOT);
            }
            return false;
            break;

    }
    return true;
};

