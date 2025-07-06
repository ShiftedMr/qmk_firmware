#include QMK_KEYBOARD_H

#include "pointing_device.h"
#include "drivers/sensors/pimoroni_trackball.h"
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  debug_mouse=true;
}
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     dprintf("X: %d, Y: %d, H: %d, V: %d, buttons: %d\n",
//             mouse_report.x,
//             mouse_report.y,
//             mouse_report.h,
//             mouse_report.v,
//             mouse_report.buttons);
//     return mouse_report;
// }

// Custom keycodes
enum custom_keycodes {
    ENCODER_SWITCH = SAFE_RANGE,
};

// User mode state
enum user_states {
    MODE_NORMAL,
    MODE_RGB
};

static uint8_t user_mode = MODE_NORMAL;

// DPI setting
static uint8_t dpi = 1;
// DEBUGGING
#include "print.h"

void matrix_init_user(void) {
    dprintf("Trackball matrix init\n");
    dprintf("HELLO FROM MATRIX INIT!\n");
}

void pointing_device_init_user(void) {
    dprintf("Trackball driver init\n");
}

// Helper Functions
void cycle_dpi(void) {
    dpi++;
    if (dpi > 5) dpi = 1;
    pimoroni_trackball_set_cpi(dpi);
}

void next_rgb_mode(void) {
    // Example: cycle through RGB modes (customize as needed)
    static uint8_t rgb_mode = 0;
    rgb_mode = (rgb_mode + 1) % 4;
    switch (rgb_mode) {
        case 0: pimoroni_trackball_set_rgbw(255, 0, 0, 0); break; // Red
        case 1: pimoroni_trackball_set_rgbw(0, 255, 0, 0); break; // Green
        case 2: pimoroni_trackball_set_rgbw(0, 0, 255, 0); break; // Blue
        case 3: pimoroni_trackball_set_rgbw(255, 255, 255, 0); break; // White
    }
}

void prev_rgb_mode(void) {
    static uint8_t rgb_mode = 0;
    rgb_mode = (rgb_mode == 0) ? 3 : rgb_mode - 1;
    switch (rgb_mode) {
        case 0: pimoroni_trackball_set_rgbw(255, 0, 0, 0); break;
        case 1: pimoroni_trackball_set_rgbw(0, 255, 0, 0); break;
        case 2: pimoroni_trackball_set_rgbw(0, 0, 255, 0); break;
        case 3: pimoroni_trackball_set_rgbw(255, 255, 255, 0); break;
    }
}

// Keymap Layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        { ENCODER_SWITCH, KC_NO }
    }
};

// Trackball button handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENCODER_SWITCH:
            if(record->event.pressed){
                user_mode = user_mode==MODE_NORMAL? MODE_RGB : MODE_NORMAL;
                dprintf("encoder pushed");
            }
            return false;
    }
    return true;
}

// // Check for hold
// void matrix_scan_user(void) {
//     if (readPin(A0) == false && timer_elapsed(trackball_timer) > 200) {
//         user_mode = MODE_RGB;
//     }
// }

// Encoder behavior
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (user_mode == MODE_RGB) {
        if (clockwise) {
            dprintf("NextColor\n");
            next_rgb_mode();
        } else {
            dprintf("PrevColor\n");
            prev_rgb_mode();
        }
    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
            dprintf("VolUpt\n");

        } else {
            tap_code(KC_VOLD);
            dprintf("VolDown\n");
        }
    }
    return false; // if this is set to true the default encoder behavior runs as well as the items in this. e.g it would change volume as well as lights when in rgb mode
}


/*
Example code to remap trackball button
static bool trackball_pressed = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Read the raw button state from the Pimoroni trackball
    uint8_t buttons = pimoroni_trackball_buttons();

    // Detect press/release edge
    if (buttons & 0x01) {
        if (!trackball_pressed) {
            trackball_pressed = true;
            tap_code(KC_ESC);  // Change this to any keycode or custom macro
            dprintf("Trackball button -> KC_ESC\n");
        }
    } else {
        trackball_pressed = false;
    }

    // Clear default mouse button behavior
    mouse_report.buttons = 0;

    return mouse_report;
}

*/