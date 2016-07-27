
/* ============================================
READ_PWM.h is placed under the MIT license
Copyright (c) 2016 Eric LoPrete

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#include <Arduino.h>//import standard arduino library
#include <Wire.h>//import i2c library
#include "PWM_Input_10CH_1v1v0.h"//import PWM handling code.
#include "MPU6050_Reader_1v1v0.h"//import MPU6050 handling code.

using namespace std;

AccelerometerGyro_MPU6050 MPU_Device;//Declare MPU6050 handling class.

void setup(){//initializations. Runs once at startup
  
 Serial.begin(250000);//Begin serial usb at 250000 baud.
 
 Wire.begin();//Begin i2c bus for MPU6050 communication.
 
 PWM_Input_10CH_1v1v0::Build_All(52, 50, 48, 46, 44, 42, 40, 38, 36, 34);//Declare pins for PWM and attach interrupt routines.
 
 MPU_Device.Build();//Initialize MPU6050.
 
}//end of setup



long loopTime = 0;//global variable for holding loop time.

void loop(){// Main control loop. Runs forever until power loss.

 //Calculate loop time. loops / second. 
  
 long nowT = micros();//Get current clock time in microseconds.
 
 loopTime = nowT - loopTime;//Get difference from last loop clock time.
 
 float LoopsPerSec = 1000000.0/loopTime;//Calculate how many loops are in a second.
 
 loopTime = nowT;//Set current time to last time for next loop timing.
 
 //done calculating loops / second.

 

 PWM_Input_10CH_1v1v0::GatherResults();//Get radio controls from reciever.
 
 MPU_Device.CalculateMotion();//Get motion measurements from MPU6050.
 
 



//Print data to serial usb.

Serial.print("loops/s:"); Serial.print(LoopsPerSec); Serial.print("\t");//Print loops per secons.

Serial.print(MPU_Device.Pitch); Serial.print(",\t");// Print calculated Pitch.

Serial.print(MPU_Device.Roll); Serial.print(",\t");// Print calculated Roll.

Serial.print(MPU_Device.PitchDelta); Serial.print(",\t");// Print pitch rotation.

Serial.print(MPU_Device.RollDelta); Serial.print(",\t");// Print roll rotation.

Serial.print(MPU_Device.YawDelta); Serial.print(",\t");//Print yaw rotation.

Serial.print(PWM_Input_10CH_1v1v0::Time_1);Serial.print(",\t");//Print channel 1. Futuba = roll = aileron.

Serial.print(PWM_Input_10CH_1v1v0::Time_2);Serial.print(",\t");//Print channel 2. Futuba = pitch = elevator.

Serial.print(PWM_Input_10CH_1v1v0::Time_3);Serial.print(",\t");//Print channel 3. Futuba = throttle.

Serial.print(PWM_Input_10CH_1v1v0::Time_4);Serial.print(",\t");//Print channel 4. Futuba = yaw = rudder.

Serial.print(PWM_Input_10CH_1v1v0::Time_5);Serial.print("\n");//Print channel 5. Futuba = toggle binary switch = landing gear

}//end of main loop

