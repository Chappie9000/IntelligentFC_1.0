


/* ============================================
ClassicalController.h is placed under the MIT license
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
#ifndef _CLASSICALCONTROLLER_H_INCLUDED_
#define _CLASSICALCONTROLLER_H_INCLUDED_

#include "Controller_Templates.h"


class P_Controller: public Controller{
 public:

 float Input;// Member memory for input.
 
 float Setpoint;// Member memory for setpoint.
 
 float Gain;// Member memory for gain.
 
 float Error;// Member memory for error.
 
 float Output;// Member memory for output.

 
 
 void Build(float gain){


  
  Gain = gain;// set member Gain
  
 }
 void Compute(float input, float setpoint){//Compute output
  
  Input = input;//Set member Input for reference
  
  Setpoint = setpoint;//Set member Setpoint for reference
  
  Error = Setpoint - Input;//Compute error. Difference between setpoint and input (P control)
  
  Output = Error*Gain;//Compute output. Error scaled by gain.
  
 }

 
};

class Classical_P_Controller_3Axis: public Controller_3Axis{//Fuse 3 independent P controllers into a single class for code efficiency.
 public:
 
  P_Controller Axis1, Axis2, Axis3;// Declare 3 P controllers, one for each axis.

  void Build(float gain1, float gain2, float gain3){//Build each P controler, define gain constant.
    
    Axis1.Build(gain1);//Build axis 1
    
    Axis2.Build(gain2);//Build axis 2
    
    Axis3.Build(gain3);//Build axis 3
    
  }
  
  void Compute(float input1, float setpoint1, float input2, float setpoint2, float input3, float setpoint3){//Compute output values for each axis
   
   Axis1.Compute(input1, setpoint1);//Compute output for axis 1
  
   Axis2.Compute(input2, setpoint2);//Compute output for axis 2
   
   Axis3.Compute(input3, setpoint3);//Compute output for axis 3
   
  }

};

#endif

