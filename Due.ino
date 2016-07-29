
/* ============================================
Due.ino is placed under the MIT license
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

#include <Servo.h>//import servo library for MotorDrivers.h
#include <Arduino.h>//import standard arduino library
#include <Wire.h>//import i2c library
#include "PWM_Input_10CH_1v1v0.h"//import PWM handling code.
#include "MPU6050_Reader_1v1v0.h"//import MPU6050 handling code.

#include "ClassicalController.h"// import controller class
//#include "NeuralController.h"
#include "RadioInterpreters.h"
#include "MotorDrivers.h"

using namespace std;



//User prefered type declarations.
//Only advanced users should modify.

bool Print_Data = true;// If true, data is printed through usb.              false: for flying.         true: if developing via usb and wish to monitor data.


Classical_P_Controller_3Axis Controller_3Axis;//Declare 3 axis controller for Pitch, Roll, Yaw. Gain and learning rate declaration ~ line 54

PWM_Interpreter_FullAcro Radio_Interpreter;// Declare 

AccelerometerGyro_MPU6050 MPU_Device;//Declare MPU6050 handling class.

MultiRotor_X4_Motor_Driver_V1 QuadCopter;//Declare class for converting radio and controlls to quadcopter motor layout

//End of user prefered type declarations.
//Mega advanced users only beyond this point.





void setup(){//initializations. Runs once at startup

   Wire.begin();//Begin i2c bus for MPU6050 communication.

  if(Print_Data == true){
   
   Serial.begin(250000);//Begin serial usb at 250000 baud.
  
  }
 






 //Edit build values for classes

 QuadCopter.Build(2, 3, 4, 5);//Build quadcopter pin and motor layout. (front-left, front-right, back-right, back-left)


 Radio_Interpreter.Build(2000, 1500, (float)180.0);// Build radio interpreter. (Max signal = 2000uS, middle = 1500uS, Full-stick = 30 degrees/second control target) 


 Controller_3Axis.Build(0.2, 0.2, 0.2);//Build 3 axis controller with a gain of for each axis. (Pitch, Roll, Yaw) = (axis 1, axis 2, axis 3). For neural controllers, these are learning rates.


 PWM_Input_10CH_1v1v0::Build_All(52, 50, 48, 46, 44, 42, 40, 38, 36, 34);//Declare pins for PWM and attach interrupt routines. (aileron, elevator, throttle, rudder, ch5, ch6, ch7, ch8, ch9, ch10).

 
 MPU_Device.Build();//Initialize MPU6050.

 
}//end of setup





void loop(){// Main control loop. Runs forever until power loss.
 long loopTime = micros();//variable for holding loop time.







 //Primary control tasks
 
 MPU_Device.CalculateMotion();//Get motion measurements from MPU6050.
 

 Radio_Interpreter.InterperateSignals();// Read PWM signals and mix with controllers to generate rotational targets deg/sec

 if(Radio_Interpreter.Armed == true){
 
 Controller_3Axis.Compute(MPU_Device.PitchDelta, Radio_Interpreter.Elevator, MPU_Device.RollDelta, Radio_Interpreter.Aileron, MPU_Device.YawDelta, Radio_Interpreter.Rudder);//Pass motion data to 3 axis controller

 }
 
 QuadCopter.Drive( Controller_3Axis.Axis1.Output, Controller_3Axis.Axis2.Output, Controller_3Axis.Axis3.Output, Radio_Interpreter.Throttle, Radio_Interpreter.Armed);// Mix thrust signals with into X4 quadcopter motor layout and generate pwm signals at motor pins

 

//Print data to serial usb.

if(Print_Data == true){

 //Calculate loop time. loops / second. 
  
 
 loopTime = micros() - loopTime;//Get difference from start of loop clock time until now.
 
Serial.print(QuadCopter.Motor_1.Input,7); Serial.print(",\t");//Print motor throttle signal. Lists clock-wise starting front left.

Serial.print(QuadCopter.Motor_2.Input, 7); Serial.print(",\t");//Print motor throttle signal

Serial.print(QuadCopter.Motor_3.Input, 7); Serial.print(",\t");//Print motor throttle signal

Serial.print(QuadCopter.Motor_4.Input, 7); Serial.print(",\t");//Print motor throttle signal

Serial.print(Controller_3Axis.Axis1.Output); Serial.print(",\t");// Print pitch P controller output.

Serial.print(Controller_3Axis.Axis2.Output); Serial.print(",\t");// Print roll P controller output.

Serial.print(Controller_3Axis.Axis3.Output); Serial.print(",\t");// Print yaw P controller output.

Serial.print(PWM_Input_10CH_1v1v0::Time_1);Serial.print(",\t");//Print channel 1. Futuba = roll = aileron.

Serial.print(PWM_Input_10CH_1v1v0::Time_2);Serial.print(",\t");//Print channel 2. Futuba = pitch = elevator.

Serial.print(PWM_Input_10CH_1v1v0::Time_3);Serial.print(",\t");//Print channel 3. Futuba = throttle.

Serial.print(PWM_Input_10CH_1v1v0::Time_4);Serial.print(",\t");//Print channel 4. Futuba = yaw = rudder.

Serial.print(PWM_Input_10CH_1v1v0::Time_5);Serial.print("\t");//Print channel 5. Futuba = toggle binary switch = landing gear

Serial.print(Radio_Interpreter.Aileron); Serial.print(",\t");//Print aileron target rotation.

Serial.print(Radio_Interpreter.Elevator); Serial.print(",\t");//Print elevator target rotation.

Serial.print(Radio_Interpreter.Rudder); Serial.print(",\t");//Print rudder target rotation.

Serial.print(MPU_Device.Pitch); Serial.print(",\t");// Print calculated Pitch.

Serial.print(MPU_Device.Roll); Serial.print(",\t");// Print calculated Roll.

Serial.print(MPU_Device.PitchDelta); Serial.print(",\t");// Print pitch rotation.

Serial.print(MPU_Device.RollDelta); Serial.print(",\t");// Print roll rotation.

Serial.print(MPU_Device.YawDelta); Serial.print(",\t");//Print yaw rotation.

Serial.print(Radio_Interpreter.Armed); Serial.print(",\t");//Print yaw rotation.

Serial.print("loopTime:"); Serial.print(loopTime); Serial.print(" micros\n");//Print loops per secons.

}

}//end of main loop

