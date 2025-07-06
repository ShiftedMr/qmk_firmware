#pragma once
#define DEBUG_ENABLE yes
#define POINTING_DEVICE_DEBUG

#define MATRIX_ROWS 1
#define MATRIX_COLS 2

// Encoder
#define ENCODER_RESOLUTION 1

// 🔧 Required for I2C to work on STM32
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
// #define POINTING_DEVICE_DRIVER pimoroni_trackball
// Trackball (Pointing Device)
#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define PIMORONI_TRACKBALL_SCALE 3


