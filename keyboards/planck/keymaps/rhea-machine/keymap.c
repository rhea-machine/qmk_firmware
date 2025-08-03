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
    _NAV,
    _ACC,
    _ADJUST,
};

enum custom_keycodes {
    RH_QUES = SAFE_RANGE,
};

// Tap Dance declarations
enum {
    TD_RAISE_ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE TD(TD_RAISE_ADJUST)
#define NAV MO(_NAV)
#define ACC MO(_ACC)

#define QWERTZ PDF(_QWERTZ)
#define GAMING PDF(_GAMING)

#define CH_EINO UC(0x0153)
#define CH_EINA UC(0x00E6)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTZ
     * ,-----------------------------------------------------------------------------------.
     * |TAB   |  Q   |  W   |  E   |  R   |  T   |  Z   |  U   |  I   |  O   |  P   |BKSP  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |NAV   |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ?   |ACC   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |SHIFT |  Y   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  -   |SHIFT |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |CTRL  |      |ALT   |GUI   |LOWER |ENTER |SPACE |RAISE |GUI   |ALT   |      |CTRL  |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTZ] = LAYOUT_planck_grid(
        KC_TAB,  CH_Q,    CH_W,    CH_E,    CH_R,    CH_T,    CH_Z,    CH_U,    CH_I,    CH_O,    CH_P,    KC_BSPC,
        NAV,     CH_A,    CH_S,    CH_D,    CH_F,    CH_G,    CH_H,    CH_J,    CH_K,    CH_L,    RH_QUES, ACC,
        KC_LSFT, CH_Y,    CH_X,    CH_C,    CH_V,    CH_B,    CH_N,    CH_M,    CH_COMM, CH_DOT,  CH_MINS, KC_RSFT,
        KC_LCTL, _______, KC_LALT, KC_LGUI, LOWER,   KC_ENT,  KC_SPC,  RAISE,   KC_RGUI, KC_RALT, _______, KC_RCTL
    ),

    /* GAMING
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |SPACE |      |      |      |      |      |      |QWERTZ|
     * `-----------------------------------------------------------------------------------'
     */
    [_GAMING] = LAYOUT_planck_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_SPC,  _______, _______, XXXXXXX, _______, _______, _______, QWERTZ
    ),

    /* LOWER
     * ,-----------------------------------------------------------------------------------.
     * |      |  %   |  #   |  [   |  ]   |      |      |  7   |  8   |  9   |      | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  /   |  *   |  -   |  +   |  =   |      |  4   |  5   |  6   |  \   |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  <   |  >   |  {   |  }   |      |      |  1   |  2   |  3   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  0   |      |  .   |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_grid(
        _______, CH_PERC, CH_HASH, CH_LBRC, CH_RBRC, _______, _______, CH_7,    CH_8,    CH_9,    _______, KC_DEL,
        _______, CH_SLSH, CH_ASTR, CH_MINS, CH_PLUS, CH_EQL,  _______, CH_4,    CH_5,    CH_6,    CH_BSLS, _______,
        _______, CH_LABK, CH_RABK, CH_LCBR, CH_RCBR, _______, _______, CH_1,    CH_2,    CH_3,    _______, _______,
        _______, _______, _______, _______, _______, _______, _______, CH_0,    _______, CH_DOT,  _______, _______
    ),

    /* RAISE
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |  &   |      |      |      |      |      |      |      | Del  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  @   |  "   |      |      |      |      |  (   |  )   |  '   |  £   |  $   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        _______, _______, _______, CH_AMPR, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
        _______, CH_AT,   CH_DQUO, _______, _______, _______, _______, CH_LPRN, CH_RPRN, CH_QUOT, CH_PND,  CH_DLR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* NAV
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      | LEFT | DOWN |  UP  |RIGHT |      | F12  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      | HOME | PDWN | PUP  | END  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_planck_grid(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_F12,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* ACCENTS
     * ,-----------------------------------------------------------------------------------.
     * |      |      |  è   |      |  é   |      |      |      |      |  œ   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  à   |      |  ¨   |  `   |      |      |  ´   |  ^   |  ~   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  æ   |      |  ç   |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ACC] = LAYOUT_planck_grid(
        _______, _______, CH_EGRV, _______, CH_EACU, _______, _______, _______, _______, CH_EINO, _______, _______,
        _______, CH_AGRV, _______, CH_DIAE, CH_GRV,  _______, _______, CH_ACUT, CH_CIRC, CH_TILD, _______, _______,
        _______, CH_EINA, _______, CH_CCED, _______, _______, _______, _______, _______, _______, _______, _______,
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


// RAISE/ADJUST tap dance functions
void raise_adjust_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // Single tap: activate raise layer
        layer_on(_RAISE);
    } else if (state->count >= 2) {
        // Double tap: activate adjust layer
        layer_on(_ADJUST);
    }
}
void raise_adjust_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        // Single tap: deactivate raise layer when released
        layer_off(_RAISE);
    } else if (state->count >= 2) {
        // Double tap: deactivate ajust layer when released
        layer_off(_ADJUST);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_RAISE_ADJUST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, raise_adjust_finished, raise_adjust_reset),
};

// Combo definitions
const uint16_t PROGMEM escape_jk_combo[] = {CH_J, CH_K, COMBO_END};
const uint16_t PROGMEM escape_df_combo[] = {CH_D, CH_F, COMBO_END};
combo_t key_combos[] = {
    COMBO(escape_jk_combo, KC_ESC),
    COMBO(escape_df_combo, KC_ESC),
};

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

