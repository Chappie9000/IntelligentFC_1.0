



/* ============================================
MotorDrivers.h is placed under the MIT license
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
#ifndef _MOTORDRIVERS_H_INCLUDED_
#define _MOTORDRIVERS_H_INCLUDED_


#include "MotorDriver_Templates.h"
#include "Arduino.h"


class PWM_Motor_Driver: public Motor_Driver{
 public:

 int Pin;
 
 float Input;
 
 Servo Driver;
 
 void Build(int pin){
  
  Pin = pin;
  
  pinMode(Pin, OUTPUT);
  
  Driver.attach(Pin);
  
  Driver.writeMicroseconds(0);
  
 }
 void Drive(float input){
  
  Input = input;
  
  Driver.writeMicroseconds(input);
  
 }
  
};

class MultiRotor_X4_Motor_Driver_V1: public MultiRotor_X4_Motor_Driver{
 public:

  PWM_Motor_Driver Motor_1;// Motor controller for motor 1. Front Left

  PWM_Motor_Driver Motor_2;// Motor controller for motor 2. Front Right

  PWM_Motor_Driver Motor_3;// Motor controller for motor 3. Back Right

  PWM_Motor_Driver Motor_4;// Motor controller for motor 4. Back Left
  
  void Build(int pin_1, int pin_2, int pin_3, int pin_4){

   Motor_1.Build(pin_1);

   Motor_2.Build(pin_2);

   Motor_3.Build(pin_3);

   Motor_4.Build(pin_4);
    
  }
  
  void Drive(float pitch, float roll, float yaw, float throttle, bool armed){

   
   
   float motor_1 = throttle + pitch + roll - yaw;//mix controls to X4 quad motor layout.
   float motor_2 = throttle + pitch - roll + yaw;
   float motor_3 = throttle - pitch - roll - yaw;
   float motor_4 = throttle - pitch + roll + yaw;

   if(armed == false){

    motor_1 = 900;
    motor_2 = 900;
    motor_3 = 900;
    motor_4 = 900;
    
   }

   if(motor_1 < 1000){

     motor_1 = 1000;
      
   }else if(motor_1 > 2000){

     motor_1 = 2000;
    
   }

   if(motor_2 < 1000){

     motor_2 = 1000;
      
   }else if(motor_2 > 2000){

     motor_2 = 2000;
    
   }

   if(motor_3 < 1000){

     motor_3 = 1000;
      
   }else if(motor_3 > 2000){

     motor_3 = 2000;
    
   }

   if(motor_4 < 1000){

     motor_4 = 1000;
      
   }else if(motor_4 > 2000){

     motor_4 = 2000;
    
   }

   if(armed == true){

    Motor_1.Drive(motor_1);
   
    Motor_2.Drive(motor_2);
   
    Motor_3.Drive(motor_3);
   
    Motor_4.Drive(motor_4);

   }else{

    Motor_1.Drive(0);
   
    Motor_2.Drive(0);
   
    Motor_3.Drive(0);
   
    Motor_4.Drive(0);
    
   }
   
  }
  
};



  
#endif



