/*
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

#include <math.h>

enum layer_names
{
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST,
};

const unsigned int LOWER = MO(_LOWER);
const unsigned int RAISE = MO(_RAISE);
const unsigned int ADJUST = LT(3, KC_SPC);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  ADJUST,     KC_ENT,   LOWER, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),
	
    [_RAISE] = LAYOUT_split_3x6_3(
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                         KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,                      KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  ADJUST,     KC_ENT,   LOWER, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  
    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_LABK, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,       XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9,KC_KP_PLUS,KC_KP_MINUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LEFT,   KC_UP, KC_RABK, KC_LPRN, KC_RPRN,                      XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6,KC_KP_ASTERISK,KC_KP_SLASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,                      KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3,KC_EQUAL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   RAISE,  ADJUST,     KC_ENT,   LOWER, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

/*
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
*/
    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,  QK_RBT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_RMOD, RGB_M_P, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER,  ADJUST,     KC_ENT,   RAISE, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

bool rgb_matrix_indicators_kb(void) {
    // Defer to the keymap if they want to override
    if (!rgb_matrix_indicators_user()) { return false; }

	// solid color ?
    if(rgb_matrix_get_mode() == 1) 
	{	
		const uint8_t layer = get_highest_layer(layer_state);

		for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= 0 
				 && index < RGB_MATRIX_LED_COUNT 
				 && index != NO_LED) {
				    const uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col,row});

enum keys_group
{
	_ARROW_KEYS, 		// purple
	_NUMERIC_KEYS,		// light green
	_FUNCTION_KEYS,		// pink
	_SYSTEM_KEYS,		// yellow
	_COMBINATION_KEYS,  // orange
	_ALPHA_KEYS			// light blue
};

					switch(keycode)
					{
						case KC_LSFT:	case KC_RSFT:
						case KC_LCTL:	case KC_RCTL:
						case KC_LALT:	case KC_RALT:						
							rgb_matrix_set_color(index, RGB_GREEN);
							break;
						
						case KC_ENT:
						case KC_BSPC:
						case KC_TAB:
						case KC_ESC:
							rgb_matrix_set_color(index, RGB_YELLOW);
							break;	

						case KC_F1:		case KC_F2:		case KC_F3:
						case KC_F4:		case KC_F5:		case KC_F6:
						case KC_F7:		case KC_F8: 	case KC_F9:	
						case KC_F10:	case KC_F11: 	case KC_F12:							
							rgb_matrix_set_color(index, RGB_PINK);
							break;			
						
						//case KC_1:	case KC_2:	case KC_3:
						//case KC_4:	case KC_5:	case KC_6:
						//case KC_7:	case KC_8: 	case KC_9:	
						//case KC_0:							
						case KC_EXLM:	case KC_AT: 	case KC_HASH:
						case KC_DLR:	case KC_PERC: 	case KC_CIRC:
						case KC_AMPR:	case KC_ASTR: 	case KC_LPRN:
						case KC_RPRN:
						case KC_KP_1:	case KC_KP_2:	case KC_KP_3:
						case KC_KP_4:	case KC_KP_5:	case KC_KP_6:
						case KC_KP_7:	case KC_KP_8:	case KC_KP_9:
						case KC_KP_0:
							rgb_matrix_set_color(index, RGB_ORANGE);
							break;	

						case KC_LEFT:	case KC_RIGHT:							
						case KC_UP:		case KC_DOWN:	
							rgb_matrix_set_color(index, RGB_PURPLE);
							break;							
						
						case XXXXXXX:
							rgb_matrix_set_color(index, RGB_BLACK);
							break;
							
						case RAISE:		case LOWER:
							rgb_matrix_set_color(index, RGB_WHITE);
							break;
						
						default:
							rgb_matrix_set_color(index, RGB_TEAL);
					}
                }
            }
        }
/*
		switch (get_highest_layer(layer_state))
		{
		case _RAISE:
			//rgb_matrix_sethsv(HSV_BLUE);
			//rgb_matrix_set_color_all(RGB_BLUE);
			break;
		case _LOWER:
			//rgb_matrix_sethsv(HSV_RED);	
			//rgb_matrix_set_color_all(RGB_RED);
			break;
		case _QWERTY:
			//rgb_matrix_set_color_all(RGB_GREEN);
			//rgb_matrix_sethsv(HSV_GREEN);
	//		rgb_matrix_set_color_all(RGB_GREEN);
			break;
		case _ADJUST:
			//rgb_matrix_sethsv(HSV_PURPLE);
			//rgb_matrix_set_color_all(RGB_PURPLE);
			break;
		default: //  for any other layers, or the default layer
			//rgb_matrix_sethsv(HSV_TURQUOISE);
			//rgb_matrix_set_color_all(RGB_TURQUOISE);
			break;
		}
		*/
	}
	
	//static uint8_t rrr=0;
	//rgb_matrix_set_color(0, 0, 0, rrr);
	//rgb_matrix_set_color(1, rrr, 0, 0);
	//rrr++;
	return true;
}

//--------------------
// OLED_DISPLAY_WIDTH 128
// OLED_DISPLAY_HEIGHT 32
unsigned int backbuffer[OLED_DISPLAY_WIDTH * (OLED_DISPLAY_HEIGHT / 32)];

void bb_clear(void)
{
	memset(&backbuffer[0], 0, OLED_DISPLAY_WIDTH * (OLED_DISPLAY_HEIGHT / 8));
}
 
uint32_t min(const uint32_t a, const uint32_t b)
{
	return a < b ? a : b;
}

uint8_t max(const uint8_t a, const uint8_t b)
{
	return a > b ? a : b;
}
 
bool bb_get(const uint8_t x, const uint32_t y)
{
	const uint32_t sy = y * (OLED_DISPLAY_HEIGHT / 32);
	const uint32_t sx = x / 32;
	const uint32_t bsx = x % 32;
	
	uint32_t index = sy + sx;

	// security
	index = min(index, (OLED_DISPLAY_WIDTH * (OLED_DISPLAY_HEIGHT / 32)) - 1);

	return (backbuffer[index] & (1u << bsx)) != 0;
}

void bb_set_on(const uint8_t x, const uint32_t y)
{
	const uint32_t sy = y * (OLED_DISPLAY_HEIGHT / 32);
	const uint32_t sx = x / 32;
	const uint32_t bsx = x % 32;
	
	uint32_t index = sy + sx;
	
	// security
	index = min(index, (OLED_DISPLAY_WIDTH * (OLED_DISPLAY_HEIGHT / 32)) - 1);	
	
	backbuffer[index] |= 1u << bsx;
}

void bb_copy_to_oled(void)
{
	for (uint8_t y = 0; y < OLED_DISPLAY_WIDTH; ++y)
	{
	    for (uint8_t x = 0; x < OLED_DISPLAY_HEIGHT; ++x)
		{
			if(bb_get(x, y))
				oled_write_pixel(x, y, true);
			
			//oled_write_pixel(0, OLED_DISPLAY_HEIGHT-1, true);
			//oled_write_pixel(OLED_DISPLAY_WIDTH - 1, OLED_DISPLAY_HEIGHT-1, true);
			//oled_write_pixel(y, x, bb_get(x, y));
        }
    }
}

void bb_draw_progress_bar(const uint8_t type, const uint8_t x, const uint8_t y, uint8_t size, uint8_t progress)
{
	size = max(5u, size);
	
	switch(type)
	{
		case 2:
			for(uint16_t i = x + 1; i < (x + size); i++)
			{
				bb_set_on(i, y);
				bb_set_on(i, y - 5);
			}
			
			for(uint16_t i = y - 1; i > (y - 5); i--)
			{
				bb_set_on(x, i);
				bb_set_on(x + size, i);
			}
			
			if(progress > 0)
			{
				for(uint16_t i = x + 2; i < (x + progress - 1); i++)
				{
					bb_set_on(i, y - 2);
					bb_set_on(i, y - 3);
				}
			}
			break;
		
		default:
		for(uint16_t i = x; i < (x + size); i++)
		{
			bb_set_on(i, y);
			bb_set_on(i, y - 5);
		}
		
		for(uint16_t i = y; i > (y - 5); i--)
		{
			bb_set_on(x, i);
			bb_set_on(x + size, i);
		}
		
		if(progress > 0)
		{
			for(uint16_t i = x + 2; i < (x + progress - 1); i++)
			{
				bb_set_on(i, y - 2);
				bb_set_on(i, y - 3);
			}
		}		
	}
}

void bb_draw_radio_button(const uint8_t type, const uint8_t x, const uint8_t y, const bool value)
{
	switch(type)
	{
		case 1:
			// ******
			// *     *
			// * (**) *
			// * (**) *
			// *     *
			// ******
			for(uint8_t i = 0; i < 6; i++)
				bb_set_on(x + i, y);

			bb_set_on(x, y - 1);
			bb_set_on(x + 5, y - 1);		
			
			bb_set_on(x, y - 2);
			bb_set_on(x + 5, y - 2);
			
			bb_set_on(x, y - 3);
			bb_set_on(x + 5, y - 3);	

			bb_set_on(x, y - 4);
			bb_set_on(x + 5, y - 4);			
			
			for(uint8_t i = 0; i < 6; i++)
				bb_set_on(x + i, y - 5);
			
			if(value)
			{
				bb_set_on(x + 2, y - 2);
				bb_set_on(x + 3, y - 2);
				bb_set_on(x + 2, y - 3);
				bb_set_on(x + 3, y - 3);
			}
			break;
		
		case 2:
			//  **** 
			// *     *
			// * (**) *
			// * (**) *
			// *     *
			//  **** 
			for(uint8_t i = 1; i < 5; i++)
				bb_set_on(x + i, y);

			bb_set_on(x, y - 1);
			bb_set_on(x + 5, y - 1);		
			
			bb_set_on(x, y - 2);
			bb_set_on(x + 5, y - 2);
			
			bb_set_on(x, y - 3);
			bb_set_on(x + 5, y - 3);	

			bb_set_on(x, y - 4);
			bb_set_on(x + 5, y - 4);			
			
			for(uint8_t i = 1; i < 5; i++)
				bb_set_on(x + i, y - 5);
			
			if(value)
			{
				bb_set_on(x + 2, y - 2);
				bb_set_on(x + 3, y - 2);
				bb_set_on(x + 2, y - 3);
				bb_set_on(x + 3, y - 3);
			}
			break;		
		
		case 0:
		default:
			// *****
			// *     *
			// * (*) *
			// *     *
			// *****
			for(uint8_t i = 0; i < 5; i++)
				bb_set_on(x + i, y);

			bb_set_on(x, y - 1);
			bb_set_on(x + 4, y - 1);		
			
			for(uint8_t i = 0; i < 5; i+=4)
				bb_set_on(x + i, y - 2);
			
			bb_set_on(x, y - 3);
			bb_set_on(x + 4, y - 3);			
			
			for(uint8_t i = 0; i < 5; i++)
				bb_set_on(x + i, y - 4);
			
			if(value)
				bb_set_on(x + 2, y - 2);
	}
}

void bb_draw_frame(void)
{
	bb_clear();
	
	const uint8_t current_layer = get_highest_layer(layer_state);
	bb_draw_radio_button(2, 5 + 6 * 0, 6/*OLED_DISPLAY_WIDTH - 1*/, current_layer == 1);
	bb_draw_radio_button(2, 5 + 6 * 1, 6/*OLED_DISPLAY_WIDTH - 1*/, current_layer == 0);
	bb_draw_radio_button(2, 5 + 6 * 2, 6/*OLED_DISPLAY_WIDTH - 1*/, current_layer == 2);
	bb_draw_radio_button(2, 5 + 6 * 3, 6/*OLED_DISPLAY_WIDTH - 1*/, current_layer == 3);
	
	if(current_layer == _ADJUST)
	{
		// RGB layer
		const uint8_t hue = rgblight_get_hue();
		const uint8_t sat = rgblight_get_sat();
		const uint8_t val = rgblight_get_val();
		const uint8_t speed = rgb_matrix_get_speed();
		
		const uint8_t txt_spce = 10;
		const uint8_t bar_spce = 6;
		
		float values[4] = { speed, val, sat, hue };
		const char strings[] = "Hue\0Sat\0Val\0Spd\0";
		for(int i = 0; i < 4; i++) 
		{
			//const uint16_t y = (OLED_DISPLAY_WIDTH - 1) - (txt_spce + bar_spce) * i;
			bb_draw_progress_bar(2, 1, (OLED_DISPLAY_WIDTH - 1) - 2 - (txt_spce + bar_spce) * i, 30, floor((values[i] / 255.0f) * 30.0f));
			//oled_set_cursor((i+8) * 6, 0);
			oled_set_cursor(1/*43 + i * 11*/, 8 + i * 2);
			//oled_set_cursor(16,16);
			oled_write(&strings[i*4], false);
		}
		
		oled_set_cursor(0, 7);	
		char rgb_mode[]=" 0/44\0";
		const uint8_t rgb_matrix_mode = rgb_matrix_get_mode();
		rgb_mode[1] = '0' + (rgb_matrix_mode % 10);
		if(rgb_matrix_mode > 9)
		{
			rgb_mode[0] = '0' + (rgb_matrix_mode / 10);
		}
		//rgb_matrix_get_mode()		
		oled_write(rgb_mode, false);
	}
	
	bb_copy_to_oled();
}

//--------------------
void keyboard_pre_init_kb(void) {
    oled_clear();
}

void keyboard_post_init_kb(void) {
	oled_clear();
		
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
	rgb_matrix_set_color_all(RGB_BLACK);
	//rgb_matrix_sethsv_noeeprom(HSV_OFF);
	//rgb_matrix_sethsv(0, 0, 255);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

//is_keyboard_master()
//#    define SHOW_LOGO 5000
bool oled_task_user(void) {
	//update_rgb_matrix_layer_color();
	//if (is_keyboard_master()) 
	//{
		//if ((timer_elapsed32(oled_logo_timer) < SHOW_LOGO)){
		//    render_logo();
		//}else{
		  //clear_screen();
	oled_clear();

	bb_draw_frame();
	
    return false;
}
#endif
