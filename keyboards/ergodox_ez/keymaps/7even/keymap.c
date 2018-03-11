#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // base QWERTY layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys & mouse control
#define GMNG 3 // gaming layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox(
    KC_EQUAL,       KC_1,        KC_2,            KC_3,          KC_4,           KC_5, TG(1),
    KC_ESCAPE,      LT(1, KC_Q), KC_W,            KC_E,          KC_R,           KC_T, TG(3),
    KC_BSPACE,      LT(2, KC_A), CTL_T(KC_S),     ALT_T(KC_D),   GUI_T(KC_F),    KC_G,
    KC_LBRACKET,    KC_Z,        KC_X,            KC_C,          KC_V,           KC_B, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_GRAVE,    LALT(KC_LSHIFT), LCTL(KC_LEFT), LCTL(KC_RIGHT),

    KC_TRANSPARENT, KC_TRANSPARENT,
                                    KC_HOME,
    KC_SPACE,       KC_LSHIFT,      KC_END,

    TG(2),          KC_6, KC_7,        KC_8,        KC_9,        KC_0,             KC_MINUS,
    KC_TRANSPARENT, KC_Y, KC_U,        KC_I,        KC_O,        LT(1, KC_P),      KC_BSLASH,
                    KC_H, GUI_T(KC_J), ALT_T(KC_K), CTL_T(KC_L), LT(2, KC_SCOLON), KC_QUOTE,
    KC_TRANSPARENT, KC_N, KC_M,        KC_COMMA,    KC_DOT,      KC_SLASH,         KC_RBRACKET,
                          KC_LEFT,     KC_RIGHT,    KC_UP,       KC_DOWN,          KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_PGUP,
    KC_PGDOWN,      SFT_T(KC_TAB),  KC_ENTER
  ),
  [SYMB] = LAYOUT_ergodox(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    RGB_MOD, KC_TRANSPARENT,
                             KC_TRANSPARENT,
    RGB_VAD, RGB_VAI,        KC_TRANSPARENT,

    KC_TRANSPARENT, KC_F6,   KC_F7,          KC_F8,  KC_F9, KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_UP,   KC_7,           KC_8,   KC_9,  KC_TRANSPARENT, KC_F12,
                    KC_DOWN, KC_4,           KC_5,   KC_6,  KC_PLUS,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AMPR, KC_1,           KC_2,   KC_3,  KC_BSLASH,      KC_TRANSPARENT,
                             KC_TRANSPARENT, KC_DOT, KC_0,  KC_EQUAL,       KC_TRANSPARENT,

    RGB_TOG,        RGB_SLD,
    KC_TRANSPARENT,
    KC_TRANSPARENT, RGB_HUD, RGB_HUI
  ),
  [MDIA] = LAYOUT_ergodox(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,      KC_TRANSPARENT,
                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LGUI(KC_LEFT)), LALT(LGUI(KC_RIGHT)),

    KC_TRANSPARENT,      KC_TRANSPARENT,
                                         KC_TRANSPARENT,
    KC_MEDIA_PLAY_PAUSE, KC_LALT,        KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_MS_WH_DOWN,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                    KC_TRANSPARENT, KC_MS_BTN1,      KC_MS_WH_UP,       KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL0,    KC_MS_ACCEL1,      KC_MS_ACCEL2,   KC_TRANSPARENT, KC_TRANSPARENT,
                                    KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK
  ),
  [GMNG] = LAYOUT_ergodox(
    KC_TRANSPARENT, KC_1,           KC_2,    KC_3,    KC_4,    KC_5, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_W,    KC_E,    KC_R,    KC_T, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,    KC_D,    KC_F,    KC_G,
    KC_TRANSPARENT, KC_Z,           KC_X,    KC_C,    KC_V,    KC_B, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LCTL, KC_LALT, KC_LGUI,

                    KC_TRANSPARENT, KC_TRANSPARENT,
                                    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_6, KC_7,           KC_8,           KC_9,      KC_0,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Y, KC_U,           KC_I,           KC_O,      KC_P,      KC_TRANSPARENT,
                    KC_H, KC_J,           KC_K,           KC_L,      KC_SCOLON, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_N, KC_M,           KC_COMMA,       KC_DOT,    KC_UP,     KC_TRANSPARENT,
                          KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,   KC_DOWN,   KC_RIGHT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  )
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
