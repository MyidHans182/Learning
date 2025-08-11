//================================================================
//                    TỆP CHÍNH (.INO)
//     Điều phối hoạt động của các module khác nhau.
//================================================================

#include "config.h"
#include "globals.h"
#include "imu_sensor.h"
#include "motor_control.h"
#include "controller.h"
#include "communication.h"

#include <TimerOne.h>
#include <TimerFour.h>

// Ngắt timer chính, là nhịp đập của hệ thống
void Timer1_ISR() {
  flag_Timer1 = true;
  t_count++;
  t_send++;
  t_tp++;
}

void setup() {
  // Khởi tạo các module
  setupCommunication();
  setupMotorsAndEncoders();
  setupIMU();

  // Cấu hình timer phần cứng
  TCCR2B = TCCR2B & B11111000 | B00000001; // Tần số f cho động cơ 2 bánh

  // Khởi tạo và gắn ngắt cho các timer
  Timer1.initialize(10000); // 10ms = 100Hz
  Timer1.attachInterrupt(Timer1_ISR);
  Timer4.initialize(50);

  // Gán giá trị ban đầu từ config
  xung = qh[0];
  vitri = qh[1];
}

void loop() {
  // Vòng lặp chính chỉ chạy khi có cờ báo từ Timer1
  if (flag_Timer1) {
    flag_Timer1 = false; // Reset cờ ngay lập tức

    // 1. THU THẬP DỮ LIỆU (SENSE)
    readIMU();
    receiveData(); // Kiểm tra lệnh mới từ Serial

    // 2. TÍNH TOÁN TRẠNG THÁI (PROCESS)
    // Cập nhật các góc từ encoder và IMU
    theta = getThetaFromEncoders() * ToRad;
    psi = (mpudata + IMU) * ToRad;
    phi = (mpudata_phi) * ToRad;
    updateStateVariables(); // Tính vận tốc góc

    // 3. THỰC THI LOGIC ĐIỀU KHIỂN (CONTROL)
    runHipTrajectoryAndPID(); // Chạy quỹ đạo và PID cho động cơ hông
    calculateLQR();           // Tính toán điện áp điều khiển từ LQR

    // 4. ĐIỀU KHIỂN CƠ CẤU CHẤP HÀNH (ACTUATE)
    controlWheels();        // Điều khiển 2 bánh xe
    controlHipMotor();      // Điều khiển động cơ hông

    // 5. GỬI DỮ LIỆU (TELEMETRY)
    if (t_send >= 10) { // Gửi dữ liệu mỗi 100ms
      sendData();
      t_send = 0;
    }
  }
}