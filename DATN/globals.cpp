#include "globals.h"
#include "config.h"

// ================================================================
//                  ĐỊNH NGHĨA BIẾN TOÀN CỤC
//        Đây là nơi các biến toàn cục được khởi tạo giá trị.
// ================================================================

// --- Cờ (Flags) ---
bool flag_Timer1 = false;
bool falldown = false;

// --- Biến đếm thời gian và trạng thái ---
unsigned long t_count = 0;
float t_send = 0;
float t_tp = 0;
int mode = 0;
int mode_t = 0;

// --- Biến động cơ hông (Hip) ---
volatile long long xung = 0;
double vitri = 0, vitridat = 0, goc_dat = 0;
float E = 0, E1 = 0, E2 = 0;
double Output = 0;

// --- Biến động cơ bánh xe ---
volatile long leftencoder = 0;
volatile long righencoder = 0;
long PWML = 0, PWMR = 0;
float leftvolt = 0, righvolt = 0;

// --- Biến trạng thái LQR ---
float theta = 0, psi = 0, phi = 0;
float thetadot = 0, psidot = 0, phidot = 0;
float thetaold = 0, psiold = 0, phiold = 0;
float theta_p = 0, phi_p = 0;
float addtheta = 0, addphi = 0;
float addtheta_ = 0, addphi_ = 0;
float IMU = 0;
int cap_xung = 0;

// --- Biến nhận/gửi dữ liệu ---
float xt = 0, yt = 0, tf = 0, tr = 0;
float LQR[6];
float PID[3];

// --- Đối tượng MPU9250 ---
MPU9250 mpu;
bool dmpReady = false;
uint8_t mpuIntStatus;
uint16_t packetSize;
uint8_t fifoBuffer[64];
Quaternion q;
VectorInt16 gy;
VectorFloat gravity;
float ypr[3];
double mpudata = 0, mpudata_phi = 0;
double accumulatedHeading = 0.0;
bool reset_heading = false;