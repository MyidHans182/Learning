#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h> // Để sử dụng PI

// ================================================================
//                       CẤU HÌNH ROBOT
//         Tất cả các thông số cần thay đổi đều ở đây.
// ================================================================

// Hằng số chuyển đổi
#define ToDeg 180 / PI
#define ToRad PI / 180

// --- Tham số động cơ hông và quỹ đạo ---
// {xung_ban_dau, vitri_ban_dau, Kp_hip, Kd_hip, vitri_dich}
const double qh[5] = { 9, 8, 0.035, 0.0084, 60 };

// --- Tham số bộ điều khiển PID/LQR mặc định ---
const float LQR_default[6] = { 20.6, 38.8, 915, 510, 40, 45 };
const float PID_default[3] = { -15, 0.3, 0.01 };
const float T_sample = 0.01; // Chu kỳ lấy mẫu (giây), tương ứng Timer1

// --- Cấu hình chân (PIN) ---
// {PWM_hip, DIR1_hip, DIR2_hip, PWM_left, DIR1_left, DIR2_left, PWM_right, DIR1_right, DIR2_right}
const int chan_out[9] = { 8, 7, 23, 9, 27, 26, 10, 24, 25 };
// {ENCA_hip, ENCB_hip, ENCA_left, ENCB_left, ENCA_right, ENCB_right}
const int chan_in[6] = { 2, 31, 3, 30, 19, 33 };

// --- Cấu hình MPU9250 ---
// Các giá trị offset này cần được hiệu chỉnh cho cảm biến của bạn
#define MPU_X_ACCEL_OFFSET -6172
#define MPU_Y_ACCEL_OFFSET 5458
#define MPU_Z_ACCEL_OFFSET 9386
#define MPU_X_GYRO_OFFSET -102
#define MPU_Y_GYRO_OFFSET -22
#define MPU_Z_GYRO_OFFSET -66

#endif