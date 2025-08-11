#include "imu_sensor.h"
#include "globals.h"
#include "config.h"
#include "I2Cdev.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

void setupIMU() {
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    Wire.setClock(400000);
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(200, true);
  #endif

  mpu.initialize();
  uint8_t devStatus = mpu.dmpInitialize();

  mpu.setXAccelOffset(MPU_X_ACCEL_OFFSET);
  mpu.setYAccelOffset(MPU_Y_ACCEL_OFFSET);
  mpu.setZAccelOffset(MPU_Z_ACCEL_OFFSET);
  mpu.setXGyroOffset(MPU_X_GYRO_OFFSET);
  mpu.setYGyroOffset(MPU_Y_GYRO_OFFSET);
  mpu.setZGyroOffset(MPU_Z_GYRO_OFFSET);

  if (devStatus == 0) {
    mpu.CalibrateAccel(6);
    mpu.CalibrateGyro(6);
    mpu.setDMPEnabled(true);
    mpuIntStatus = mpu.getIntStatus();
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  } else {
    // Xử lý lỗi nếu không khởi tạo được DMP
    Serial.print(F("DMP Initialization failed (code "));
    Serial.print(devStatus);
    Serial.println(F(")"));
  }
}

void readIMU() {
  static unsigned long startTime = 0;
  unsigned long currentMillis = millis();

  if (startTime == 0) {
    startTime = currentMillis;
  }
  // Tự động reset góc yaw về gần 0 sau 20s để hiệu chỉnh drift
  if (currentMillis - startTime >= 20000 && !reset_heading) {
    accumulatedHeading = 0.8 * (M_PI / 180.0);
    reset_heading = true;
  }

  if (!dmpReady) return;

  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    q.y = -q.y; // Hiệu chỉnh trục nếu cần
    q.z = -q.z;
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    mpu.dmpGetGyro(&gy, fifoBuffer);
    
    // Hiệu chỉnh drift của góc Yaw (phi)
    accumulatedHeading += 0.0000045 * (M_PI / 180.0);
    double heading_ = ypr[0] + accumulatedHeading;

    mpudata_phi = heading_ * 180 / M_PI;
    mpudata = ypr[1] * 180 / M_PI;

    falldown = (abs(mpudata) > 40);
  }
}