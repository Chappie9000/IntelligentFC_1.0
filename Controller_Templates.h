


/* ============================================
Controller_Templates.h is placed under the MIT license
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
#ifndef _CONTROLLER_TEMPLATES_H_INCLUDED_
#define _CONTROLLER_TEMPLATES_H_INCLUDED_

class Controller{
 public:

 float Input;
 float Setpoint;
 float Gain;
 float Error;
 float Output;

 
 void Build(float gain);
 void Compute(float input, float setpoint);

  
};


class Controller_3Axis{
 public:

  Controller Axis1, Axis2, Axis3;
 
  void Build(float gain1, float gain2, float gain3);// Build 3 Classical_Controllers
  void Compute(float input1, float setpoint1, float input2, float setpoint2, float input3, float setpoint3);
  
  
};


  
#endif



