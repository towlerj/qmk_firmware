/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MEDIA,
    _NUMPAD,
    _ADJUST,
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    BACKLIT
};

// JT additions
#define JT_SP1 LT(_MEDIA, KC_SPC)       // Media layer while held, otherwise space
#define JT_SP2 LT(_NUMPAD, KC_SPC)      // NumPad layer while held, otherwise space
#define JT_SP3 LT(_RAISE, KC_SPC)       // Raise while held, space on tap
#define JT_SP4 LT(_LOWER, KC_SPC)       // Raise while held, space on tap

#define JT_EN1 LT(_LOWER, KC_ENT)       // Lower while held, enter on tap
#define JT_EN2 LT(_MEDIA, KC_ENT)       // Lower while held, enter on tap

#define JT_AP1 LT(_ADJUST, KC_APP)      // Ádjust while held, app/menu on tap

#define JT_CAD C(A(KC_DEL))             // Control Alt Delete
#define JT_CSL C(S(KC_LEFT))            // Control Shift Left
#define JT_CSR C(S(KC_RIGHT))           // Control Shift Right
#define JT_CLF C(KC_LEFT)               // Control Left
#define JT_CRT C(KC_RIGHT)              // Control Right
#define JT_CHM C(KC_HOME)               // Control Home
#define JT_CND C(KC_END)                // Control End
#define JT_SUP S(KC_UP)                 // Shift Up
#define JT_SDN S(KC_DOWN)               // Shift Down
#define JT_ES1 LT(_MEDIA, KC_ESC)       // Escape when tapped, otherwise switch to numpad
#define JT_ES2 LT(_NUMPAD, KC_ESC)      // Escape when tapped, otherwise switch to numpad

#define JT_MN1 LT(_MEDIA, KC_MINUS)     // Minus when tapped, otherwise media
#define JT_MN2 LT(_NUMPAD, KC_MINUS)    // Minus when tapped, otherwise numpad

//#define JT_SVU C(S(A(KC_F23)))          // Control, shift, alt F23 - triggers vol up on sonos script
//#define JT_SVD C(S(A(KC_F22)))          // Control, shift, alt F22 - triggers vol up on sonos script

#define JT_SVU MEH(KC_F23)              // Control, shift, alt F23 - triggers vol up on sonos script
#define JT_SVD MEH(KC_F22)              // Control, shift, alt F22 - triggers vol up on sonos script

#define JT_GBP RALT(RSFT(KC_4))          // Should send £ symbol for us int keyboard

/*
// these didn't work (first won't work, second gives me a momentary control, which is no use())
#define JT_CNP MT(MOD_LCTL, TG(_NUMPAD))// Left control held, otherwise switch to numpad
#define JT_CT1 LT(_NUMPAD, )            // Left control held, otherwise switch to numpad
*/

/*
#define JT_SHIFT_TAP_TERM  500;
#define JT_TAP_TERM  200;
*/

// Tap dance
enum {
	TD_CPL_TOGY,
    TD_CPL_TOGJ,
    TD_UND_U
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CPL_TOGY] = ACTION_TAP_DANCE_DOUBLE(KC_Y,KC_CAPSLOCK),
    [TD_CPL_TOGJ] = ACTION_TAP_DANCE_DOUBLE(KC_J,KC_CAPSLOCK),
    [TD_UND_U]   = ACTION_TAP_DANCE_DOUBLE(KC_U,KC_UNDS)
};
// chording
// I don't actually like this - it's a solution to a porblem I don't have...
/*
enum combos {
    HOME_DK,
    END_LS,
    DOC_HOME,
    DOC_END,
};

const uint16_t PROGMEM home_kd[]  = {KC_K, KC_D, COMBO_END};
const uint16_t PROGMEM doc_home[] = {KC_K, KC_S, COMBO_END};
const uint16_t PROGMEM end_ls[]   = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM doc_end[]  = {KC_L, KC_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [HOME_DK]  = COMBO(home_kd,  KC_HOME),
    [DOC_HOME] = COMBO(doc_home, C(KC_HOME)),
    [END_LS]   = COMBO(end_ls,   KC_END),
    [DOC_END]  = COMBO(doc_end,  C(KC_END)),
};
*/
// End JT additions

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | -/NP |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Menu |Space/Lower  | Space/Raise |  /   | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_2x2u(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,    KC_6,            KC_7,            KC_8,     KC_9,     KC_0,     KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    TD(TD_CPL_TOGY), TD(TD_UND_U),    KC_I,     KC_O,     KC_P,     KC_BSPC,
    JT_MN2,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,            TD(TD_CPL_TOGJ), KC_K,     KC_L,     KC_SCLN,  SFT_T(KC_QUOT),
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,            KC_M,            KC_COMM,  KC_DOT,   KC_UP,    JT_EN2,
    KC_LCTL, KC_LALT, KC_LGUI, JT_AP1,     JT_SP4,                JT_SP3,                 KC_SLSH,  KC_LEFT,  KC_DOWN,  KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |   F1 |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F2  |  F4  |  F9  |  F12 |      |      |   _  |   =  |   [  |   ]  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   -  |   +  |   {  | PgUp |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |   ?  | Home | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_2x2u(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,      KC_F10,  KC_F11,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,    KC_RPRN, KC_MINS,
    KC_DEL,  KC_F2,   KC_F4,   KC_F9,   KC_F12,  _______, _______, KC_UNDS, KC_EQL,  KC_LBRC,    KC_RBRC, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_PLUS, S(KC_LBRC), KC_PGUP, KC_BSLS,
    _______, _______, _______, _______, _______,          _______,          KC_QUES, KC_HOME,    KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |  GBP |      |      |      |      |AlPrSc|PrntSn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |      |CtrlW |      |CtrlR |CtrlT |      | ShHm | ShNd |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |CtrlA |CtrlS |      |      |      |      | Alt  | TAB  | Ctrl |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |CtrlZ |CtrlX |CtrlC |CtrlV |      |CtrlN |      |      |      | CtHm |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | RAlt |      |      |             |             |      | CtLft| CtEnd| CtRgt|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_2x2u(
    KC_TILD, _______, _______, _______, JT_GBP,  _______,  _______, _______,    _______,   A(KC_PSCR), KC_PSCR, _______,
    KC_GRV,  _______, C(KC_W), _______, C(KC_R), C(KC_T),  _______, S(KC_HOME), S(KC_END), _______,    _______, _______,
    KC_ESC,  C(KC_A), C(KC_S), _______, _______, _______,  _______, KC_LALT,    KC_TAB,    KC_LCTL,    _______, _______,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______,  C(KC_N), _______,    _______,   _______,    JT_CHM, _______,
    _______, KC_RALT, _______, _______, _______,           _______, _______,               JT_CLF,     JT_CND, JT_CRT
),
/* Media
 * ,-----------------------------------------------------------------------------------.
 * | F12  |      |  F2  |  F4  |  F5  |      |      |      |      |      |  F9  |CtAlDe|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|   w  |   e  |  r   |   t  |  y   |  u   |  i   |  o   |  p   |Sleep |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |SonPrv|SonNxt|      |      |SonPly|SonStp|SonV+ |SonV- |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_preonic_2x2u(
    KC_F12,   _______, KC_F2,   _______, KC_F4,    KC_F5,   _______, _______, _______, KC_F9,     _______,      JT_CAD,
//              q        w        e        r         t       y        u        i         o          p
    _______, RESET,   _______, _______, _______,  _______, _______, _______, _______, _______,    _______,    KC_SLEP,
    _______, _______, _______, KC_MPRV, KC_MNXT,  _______, _______, KC_MPLY, KC_MSTP, JT_SVU,     JT_SVD,     _______,
    _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,    JT_SUP,     _______,
    _______, _______, _______, _______, _______,           _______, _______,          JT_CSL,     JT_SDN,     JT_CSR
),

/* NumPad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |  =   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |  5   |  6   |   -  |  /   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |  2   |  3   |  +   |   *  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   0  |  .   |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | CtLft|      | CtRgt|
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_2x2u(
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    KC_EQL,  _______,
    _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_MINS, KC_SLSH,
    _______, KC_F2,    KC_F4,  KC_F9,   KC_F12,  _______, _______, KC_1,    KC_2,    KC_3,    KC_PLUS, KC_ASTR,
    _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  _______, JT_SUP,  _______,
    _______, _______, _______, _______, _______,          _______,          _______, JT_CSL,  JT_SDN,  JT_CSR
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | OutQw|  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Numpad|      |Aud on|AudOff|      |      |Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |qwqwe
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_2x2u(
    _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
    _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF, _______, _______, KC_DEL,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______,          _______,          _______,  _______, _______, _______
)


};

/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_F):
            return 500;
        case SFT_T(KC_J):
            return 500;
        default:
            return JT_TAP_TERM;
    }
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case LOWER:
            if (record->event.pressed) {
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
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
                #ifdef BACKLIGHT_ENABLE
                    backlight_step();
                #endif
                #ifdef __AVR__
                    writePinLow(E6);
                #endif
            } else {
                unregister_code(KC_RSFT);
                #ifdef __AVR__
                writePinHigh(E6);
                #endif
            }
            return false;
            break;
    }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
    }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
