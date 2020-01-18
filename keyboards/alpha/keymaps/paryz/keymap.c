// Paryz's keymap
#include QMK_KEYBOARD_H

#define HOME 0
#define NUM_PUNC 1
#define MEDIA 2
#define OTHER 3

enum custom_keycodes {
	MACRO1 = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
			case MACRO1:
				SEND_STRING("This is an alternative keymap for Alpha by Pyrol.");
				return false;
		}
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(MEDIA, KC_ENT),
		KC_Z, KC_X, KC_C, KC_V, LT(NUM_PUNC, KC_SPC), KC_B, KC_N, KC_M),

	[NUM_PUNC] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_BSPC, KC_ESC, KC_TAB, KC_SCLN, KC_QUOT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TO(MEDIA),
		KC_LCTL, KC_LGUI, KC_LALT, TO(HOME), MT(MOD_LSFT, KC_ENT), KC_COMM, KC_DOT, KC_SLSH),

	[MEDIA] = LAYOUT(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_LSFT, KC_F11, KC_F12, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, TO(OTHER),
		RGB_VAI, RGB_VAD, RGB_HUI, TO(HOME), RGB_MOD, KC_MPLY, KC_VOLD, KC_VOLU),

	[OTHER] = LAYOUT(
		RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, TO(HOME), MACRO1, KC_NO, KC_NO, KC_NO),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void send_key(uint16_t keycode) {
  register_code(keycode);
  unregister_code(keycode);
}

void keyboard_post_init_user(void) {
	send_key(VLK_TOG);
}
