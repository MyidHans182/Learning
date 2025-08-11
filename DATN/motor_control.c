#include "motor_control.h"
#include "globals.h"
#include "config.h"
#include <TimerFour.h>

// --- Hàm ngắt Encoder ---
void Demxung_isr() {
  if (digitalRead(chan_in[1]) == HIGH) xung++;
  else xung--;
}

void left_isr() {
  if (digitalRead(chan_in[3]) == HIGH) leftencoder++;
  else leftencoder--;
}

void righ_isr() {
  if (digitalRead(chan_in[5]) == LOW) righencoder++;
  else righencoder--;
}

// --- Hàm khởi tạo ---
void setupMotorsAndEncoders() {
  for (int i = 0; i < 9; i++) {
    pinMode(chan_out[i], OUTPUT);
  }
  for (int i = 0; i < 6; i++) {
    pinMode(chan_in[i], INPUT_PULLUP);
  }
  
  // Gắn ngắt cho các encoder
  attachInterrupt(digitalPinToInterrupt(chan_in[0]), Demxung_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(chan_in[2]), left_isr, RISING);
  attachInterrupt(digitalPinToInterrupt(chan_in[4]), righ_isr, FALLING);
}

// --- Hàm tính toán ---
float getThetaFromEncoders() {
  return 0.5 * (360.0 / (11.0 * 30.0)) * (leftencoder - righencoder);
}

// --- Các hàm điều khiển cấp thấp ---
void stopAndResetWheels() {
  // Dừng bánh trái
  analogWrite(chan_out[3], 0);
  digitalWrite(chan_out[4], LOW);
  digitalWrite(chan_out[5], LOW);
  // Dừng bánh phải
  analogWrite(chan_out[6], 0);
  digitalWrite(chan_out[7], LOW);
  digitalWrite(chan_out[8], LOW);

  leftencoder = 0;
  righencoder = 0;
  addtheta = 0;
  addphi = 0;
}

void setLeftMotor(uint8_t lpwm, bool forward) {
  analogWrite(chan_out[3], lpwm);
  if (forward) {
    digitalWrite(chan_out[4], LOW);
    digitalWrite(chan_out[5], HIGH);
  } else {
    digitalWrite(chan_out[4], HIGH);
    digitalWrite(chan_out[5], LOW);
  }
}

void setRightMotor(uint8_t rpwm, bool forward) {
  analogWrite(chan_out[6], rpwm);
  if (forward) {
    digitalWrite(chan_out[7], LOW);
    digitalWrite(chan_out[8], HIGH);
  } else {
    digitalWrite(chan_out[7], HIGH);
    digitalWrite(chan_out[8], LOW);
  }
}

// --- Các hàm điều khiển cấp cao ---
void controlWheels() {
  if (falldown) {
    stopAndResetWheels();
  } else {
    if (leftvolt != 0) {
      setLeftMotor(abs(PWML), leftvolt > 0);
    } else {
      setLeftMotor(0, true); // Dừng động cơ
    }
    
    if (righvolt != 0) {
      setRightMotor(abs(PWMR), righvolt > 0);
    } else {
      setRightMotor(0, true); // Dừng động cơ
    }
  }
}

void controlHipMotor() {
  vitri = (double)(((double)xung * 360) / 400);
  E = vitridat - vitri;

  // Tạm thời giữ logic PID cũ, có thể thay thế bằng Fuzzy hoặc PID chuẩn hơn
  // Output = ... (logic PID cũ)
  // Đây là phần tính toán PID cho động cơ hông
  float p_term = qh[2] * E;
  float d_term = qh[3] * (E - E1) / T_sample; // Đạo hàm đơn giản
  Output = p_term + d_term;
  E1 = E;

  // Giới hạn điện áp đầu ra (PWM)
  Output = constrain(Output, -972, 972);

  if (Output > 0) {
    Timer4.pwm(chan_out[0], abs(Output));
    Timer4.pwm(chan_out[1], 0);
  } else {
    Timer4.pwm(chan_out[0], 0);
    Timer4.pwm(chan_out[1], abs(Output));
  }
}