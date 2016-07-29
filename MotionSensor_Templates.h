


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

#ifndef _MOTIONSENSORS_TEMPLATES_H_INCLUDED_
#define _MOTIONSENSORS_TEMPLATES_H_INCLUDED_


class MotionSensor_6DOF{//Prototype for deriving 6DOF motion-sensor-device handling classes.
  
 public:
 
 float Pitch;//Absolute pitch
 
 float Roll;//Absolute roll
 
 float Yaw;//Absolute yaw. Not allways supported
 
 float PitchDelta;// Rotational velocity around pitch / x axis
 
 float RollDelta;// Rotational velocity around roll / y axis
 
 float YawDelta;// Rotational velocity around yaw / z axis
 
 void Build();// Prototype function for building and initializing device
 
 void Read();// Prototype function for reading data from device 
 
 void CalculateMotion();// Prototype function for calculating motion data from raw data
 
};

#endif