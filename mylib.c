#include "I2Cdev.h"
#include "MPU9250_6Axis_MotionApps20.h"
#include "Wire.h"
#include <TimerOne.h>
#include<TimerThree.h>
#include <TimerFour.h>
#define ToDeg 180 / PI
#define ToRad PI / 180
