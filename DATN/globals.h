#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include "MPU9250_6Axis_MotionApps20.h"

// ================================================================
//                  KHAI BÁO BIẾN TOÀN CỤC
//      Sử dụng 'extern' để báo cho trình biên dịch biết
//         các biến này được định nghĩa ở một nơi khác.
// ================================================================

// --- Cờ (Flags) ---
extern bool flag_Timer1;
extern bool falldown;

// --- Biến đếm thời gian và trạng thái ---
extern unsigned long t_count;
extern float t_send;
extern float t_tp;
extern int mode;
extern int mode_t;

// --- Biến động cơ hông (Hip) ---
extern volatile long long xung;
extern double vitri, vitridat, goc_dat;
extern float E, E1, E2;
extern double Output;

// --- Biến động cơ bánh xe ---
extern volatile long leftencoder;
extern volatile long righencoder;
extern long PWML, PWMR;
extern float leftvolt, righvolt;

// --- Biến trạng thái LQR ---
extern float theta, psi, phi;
extern float thetadot, psidot, phidot;
extern float thetaold, psiold, phiold;
extern float theta_p, phi_p;
extern float addtheta, addphi;
extern float addtheta_, addphi_;
extern float IMU;
extern int cap_xung;

// --- Biến nhận/gửi dữ liệu ---
extern float xt, yt, tf, tr;
extern float LQR[6], PID[3];

// --- Đối tượng MPU9250 ---
extern MPU9250 mpu;
extern bool dmpReady;
extern uint8_t mpuIntStatus;
extern uint16_t packetSize;
extern uint8_t fifoBuffer[64];
extern Quaternion q;
extern VectorInt16 gy;
extern VectorFloat gravity;
extern float ypr[3];
extern double mpudata, mpudata_phi;
extern double accumulatedHeading;
extern bool reset_heading;

#endif