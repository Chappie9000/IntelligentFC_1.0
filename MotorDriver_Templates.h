


/* ============================================
MotorDriver_Templates.h is placed under the MIT license
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
#ifndef _MOTORDRIVER_TEMPLATES_H_INCLUDED_
#define _MOTORDRIVER_TEMPLATES_H_INCLUDED_


class Motor_Driver{
 public:

 int Pin;
 float Input;
 
 void Build(int pin);
 void Compute(float input);
  
};


class MultiRotor_X4_Motor_Driver{


  Motor_Driver Motor_1;// Motor controller for motor 1. Front Left

  Motor_Driver Motor_2;// Motor controller for motor 2. Front Right

  Motor_Driver Motor_3;// Motor controller for motor 3. Back Right

  Motor_Driver Motor_4;// Motor controller for motor 4. Back Left
  
  void Build(int pin_1, int pin_2, int pin_3, int pin_4);
  void Drive(float pitch, float roll, float yaw, float throttle);
  
};

  
#endif



