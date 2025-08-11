#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Arduino.h>

void setupMotorsAndEncoders();
float getThetaFromEncoders();
void controlWheels();
void controlHipMotor();

// Các hàm ngắt (ISRs) phải được khai báo ở scope toàn cục
void left_isr();
void righ_isr();
void Demxung_isr();

#endif