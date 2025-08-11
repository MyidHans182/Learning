#include "communication.h"
#include "globals.h"
#include "config.h"

void setupCommunication() {
  Serial.begin(115200);
  Serial3.begin(115200);
}

void checkAndApplyData() {
    float LQR_temp[6];
    float PID_temp[3];
    float angle_temp, IMU_temp;

    switch (mode) {
        case 1: // Cập nhật LQR
            for(int i=0; i<6; i++) { LQR[i] = LQR_temp[i]; }
            break;
        case 2: // Cập nhật PID và góc đặt
            vitridat = angle_temp;
            for(int i=0; i<3; i++) { PID[i] = PID_temp[i]; }
            IMU = IMU_temp;
            break;
        default:
            break;
    }
}

void receiveData() {
  if (Serial3.available() > 0) {
    int idataRx = Serial3.read();
    switch (idataRx) {
      case 'U': addtheta_ += 7.5; break;
      case 'D': addtheta_ -= 7.5; break;
      case 'R': addphi_ += PI / 4; break;
      case 'L': addphi_ -= PI / 4; break;
      case 'H': addtheta_ = 0; addphi_ = 0; break;
      case 'M': addphi_ = (2 * PI) / 4; break;
      case 'N': addphi_ = -(2 * PI) / 4; break;
      case 'T':
        mode_t = 1;
        xt = Serial3.parseFloat();
        yt = Serial3.parseFloat();
        tf = Serial3.parseFloat();
        t_tp = 0;
        break;
      case 'C':
        mode_t = 2;
        addtheta = Serial3.parseFloat();
        tr = Serial3.parseFloat();
        tf = Serial3.parseFloat();
        t_tp = 0;
        break;
      case 'P':
        mode = 1;
        // Đọc vào biến tạm, rồi áp dụng trong checkAndApplyData
        // LQR_temp[0] = Serial3.parseFloat(); ...
        break;
      case 'I':
        mode = 2;
        // Đọc vào biến tạm
        // angle_temp = Serial3.parseFloat(); ...
        break;
      default: break;
    }
    checkAndApplyData(); // Áp dụng các thay đổi
    while(Serial3.available()) Serial3.read(); // Xóa bộ đệm
  }
}

void sendData() {
  // Chuyển đổi sang số nguyên để gửi đi
  int psi_temp = psi * ToDeg * 100;
  int theta_temp = theta * ToDeg * 100;
  int phi_temp = phi * ToDeg * 100;
  int addphi_temp = addphi_ * ToDeg * 100;
  int addtheta_temp = addtheta_ * 100;
  int vitridat_temp = vitridat * 100;
  int vitri_temp = vitri * 100;

  String dataStr = "";
  dataStr += "a" + String(psi_temp);
  dataStr += "b" + String(theta_temp);
  dataStr += "c" + String(phi_temp);
  dataStr += "d" + String(vitri_temp);
  dataStr += "e" + String(addtheta_temp);
  dataStr += "f" + String(addphi_temp);
  dataStr += "g" + String(vitridat_temp);
  dataStr += "h" + String((long)PWML);
  dataStr += "i" + String((long)PWMR);
  dataStr += "j" + String((long)Output);
  dataStr += "k";

  Serial.println(dataStr);
}