#include "controller.h"
#include "globals.h"
#include "config.h"

// --- Hàm cập nhật trạng thái ---
void updateStateVariables() {
  uint32_t static timerloop = 0;
  double dt = (float)((micros() - timerloop)) / 1000000.0;
  if (dt <= 0) dt = T_sample; // Tránh chia cho 0
  timerloop = micros();

  thetadot = (theta - thetaold) / dt;
  psidot = gy.y * ToRad; // Dùng trực tiếp từ gyro cho độ chính xác cao hơn
  phidot = gy.z * ToRad;

  // Tích phân cho bộ điều khiển vị trí (nếu cần)
  theta_p += (theta + thetaold) * 3 * dt;
  phi_p += (phi + phiold) * 4 * dt;
  
  thetaold = theta;
  psiold = psi;
  phiold = phi;
}

// --- Hàm quỹ đạo và logic hông ---
float trajectory_cubic(float start_pos, float end_pos, float t_run, float t_final) {
  if (t_run >= t_final) return end_pos;
  float t = t_run;
  float a0 = start_pos;
  float a1 = 0;
  float a2 = 3 * (end_pos - start_pos) / (t_final * t_final);
  float a3 = -2 * (end_pos - start_pos) / (t_final * t_final * t_final);
  return (a0 + a1 * t + a2 * (t * t) + a3 * (t * t * t));
}

void runHipTrajectoryAndPID() {
  if (t_count >= 500) {
    float loc = 500;
    tf = 20; // Thời gian thực hiện quỹ đạo
    vitridat = trajectory_cubic(qh[1], qh[4], (float)(t_count - loc) * T_sample, (float)tf);
  }
  
  if (mode_t == 2) {
    if (t_tp <= (tf / 2) * 100) {
      addtheta_ = addtheta;
    } else {
      addtheta_ = 0;
    }
    if (t_tp >= tf * 100) {
      t_tp = 0;
    }
  }
}

// --- Hàm tính toán LQR ---
void updateLQRParameters() {
  // Cập nhật các thông số IMU và LQR dựa trên chiều cao 'vitri'
  cap_xung = 185;
  IMU = -6.3; // Giá trị mặc định
  
  // Tạm thời dùng bộ LQR mặc định. Có thể mở rộng với logic Fuzzy ở đây.
  for(int i=0; i<6; i++) {
    LQR[i] = LQR_default[i];
  }
}

void calculateLQR() {
  updateLQRParameters();

  float term_theta = LQR[0] * (theta - addtheta_);
  float term_thetadot = LQR[1] * thetadot;
  float term_psi = LQR[2] * psi;
  float term_psidot = LQR[3] * psidot;
  float term_phi = LQR[4] * (phi - addphi_);
  float term_phidot = LQR[5] * phidot;

  righvolt = term_theta + term_thetadot + term_psi + term_psidot + term_phi + term_phidot + theta_p + phi_p;
  leftvolt = term_theta + term_thetadot + term_psi + term_psidot - term_phi - term_phidot + theta_p - phi_p;
  
  float max_volt = (LQR[2] * PI * 5 / cap_xung);
  
  PWML = map(leftvolt, -max_volt, max_volt, -cap_xung, cap_xung);
  PWMR = map(righvolt, -max_volt, max_volt, -cap_xung, cap_xung);
  
  PWML = constrain(PWML, -cap_xung, cap_xung);
  PWMR = constrain(PWMR, -cap_xung, cap_xung);
}

void applyReceivedCommands() {
  // Logic của hàm checkdata() cũ được chuyển vào đây
  // Nó sẽ được gọi trong hàm receiveData() của module communication
}