#include QMK_KEYBOARD_H
#include "version.h"


#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
};

enum {
	TD_K_PASTE=1,
	TD_Z_UNDO=2,
	TD_2_FN2=3,
	TD_CPL_TOG
};






qk_tap_dance_action_t tap_dance_actions[] = {
	// d is d, held d is copy
	[TD_K_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_K, LCTL(KC_V) ),
	[TD_Z_UNDO] = ACTION_TAP_DANCE_DOUBLE(KC_Z, LCTL(KC_Z)),
	[TD_2_FN2] = ACTION_TAP_DANCE_DOUBLE(KC_2,KC_F2),
	[TD_CPL_TOG] = ACTION_TAP_DANCE_DOUBLE(KC_Y,KC_CAPSLOCK)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_LGUI,        KC_1,           TD(TD_2_FN2),   KC_3,           KC_4,           KC_5,   TG(2),                      TG(3),					KC_6,			KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_DELETE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,   LCTL(KC_C),					LCTL(KC_V),				TD(TD_CPL_TOG), KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    TG(1),          KC_A,           KC_S,           KC_D,           LSFT_T(KC_F),	KC_G,														KC_H,           RSFT_T(KC_J),	KC_K,           KC_L,           KC_SCOLON,      KC_EQUAL,
    KC_QUOTE,       KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,   KC_TAB,                     LALT_T(KC_APPLICATION),	KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          OSL(4),
    LCTL(KC_C),          KC_GRAVE,       ST_MACRO_0,  ST_MACRO_1,     ST_MACRO_10,																				KC_SLASH,       KC_APPLICATION, KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                                                    LALT_T(KC_ESCAPE),        KC_END,             KC_PGUP,       RCTL_T(KC_ESCAPE),
                                                                                                                    KC_HOME,              KC_PGDOWN,
                                                                                    LSFT_T(KC_SPACE),KC_ENTER,		KC_LCTRL,  			 KC_RCTRL,KC_BSPACE,	KC_SPACE
		  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        LALT(KC_PSCR),  KC_F12,        TO(0),                                          TO(0),          KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,			KC_RIGHT,       KC_PSCR,                                                                       KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_TRANSPARENT,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_0,           KC_DOT,         KC_TRANSPARENT,           KC_TRANSPARENT,       KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_F2,          KC_TRANSPARENT, KC_F9,          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SLASH,       KC_ASTR,        KC_MINUS,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TO(0),                                          TO(0),          KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_EQUAL,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_0,           KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_MS_ACCEL2,   KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_MS_WH_UP,    TO(0),                                          TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_ACCEL1,   KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_MS_ACCEL2,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_MS_BTN3,                                                                                                     KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_MS_BTN1,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
  [4] = LAYOUT_ergodox_pretty(
    ST_MACRO_2,     KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        RESET,
    KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   LSFT(RALT(KC_TAB)),RALT(KC_TAB),   ST_MACRO_3,     TO(0),                                          TO(0),          KC_TRANSPARENT, ST_MACRO_4,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_A),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_9,     ST_MACRO_8,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {85,203,158}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {85,203,158}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151}, {127,243,151} },

    [1] = { {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {141,255,233}, {141,255,233}, {141,255,233}, {0,240,244}, {0,240,244}, {141,255,233}, {141,255,233}, {141,255,233}, {0,240,244}, {0,240,244}, {141,255,233}, {141,255,233}, {141,255,233}, {0,240,244}, {0,240,244}, {141,255,233}, {141,255,233}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244}, {0,240,244} },

    [2] = { {163,234,242}, {163,234,242}, {141,255,233}, {141,255,233}, {141,255,233}, {163,234,242}, {0,205,155}, {0,205,155}, {0,205,155}, {141,255,233}, {163,234,242}, {0,205,155}, {0,205,155}, {0,205,155}, {141,255,233}, {163,234,242}, {0,205,155}, {0,205,155}, {0,205,155}, {163,234,242}, {0,205,155}, {0,205,155}, {163,234,242}, {163,234,242}, {163,234,242}, {33,255,255}, {163,234,242}, {33,255,255}, {163,234,242}, {163,234,242}, {163,234,242}, {163,234,242}, {163,234,242}, {163,234,242}, {163,234,242}, {163,234,242}, {249,228,255}, {163,234,242}, {163,234,242}, {163,234,242}, {249,228,255}, {249,228,255}, {249,228,255}, {163,234,242}, {163,234,242}, {163,234,242}, {163,234,242}, {163,234,242} },

    [3] = { {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {255,220,201}, {205,255,255}, {0,205,155}, {205,255,255}, {15,166,195}, {255,220,201}, {0,205,155}, {0,205,155}, {0,205,155}, {15,166,195}, {187,235,244}, {187,235,244}, {187,235,244}, {187,235,244}, {15,166,195}, {0,183,238}, {0,183,238}, {187,235,244}, {187,235,244} },

    [4] = { {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {250,159,255}, {36,231,240}, {36,231,240}, {36,231,240}, {250,159,255}, {250,159,255}, {250,159,255}, {36,231,240}, {36,231,240}, {205,255,255}, {205,255,255}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {250,159,255}, {154,255,255}, {154,255,255}, {205,255,255}, {205,255,255}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240}, {205,255,255}, {36,231,240}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {36,231,240}, {36,231,240}, {36,231,240}, {36,231,240} },


};



void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_LBRACKET)) SS_DELAY(10) SS_LSFT(SS_TAP(X_RBRACKET)) SS_DELAY(10) SS_TAP(X_LEFT));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(10) SS_TAP(X_RBRACKET) SS_DELAY(10) SS_TAP(X_LEFT));

    }
    break;
    case ST_MACRO_2:
	if (record->event.pressed) {
      SEND_STRING("chrome" );

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_APPLICATION) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_D)  SS_DELAY(100) SS_TAP(X_ENTER));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING("cd .." );

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING("| grep -i ");

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING("ls -la ");

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING("ps -ef |grep -i ");

    }
    break;
	case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING("turing");

    }
    break;
	case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING("firefox");

    }
    break;
	case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING("()" SS_DELAY(10) SS_TAP(X_LEFT));

    }
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};