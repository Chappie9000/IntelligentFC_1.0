


/* ============================================
RadioInterpreters.h is placed under the MIT license
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
#ifndef _RADIOINTERPRETERS_H_INCLUDED_
#define _RADIOINTERPRETERS_H_INCLUDED_


#include "RadioInterpreter_Templates.h"
#include "MotorDrivers.h"

class PWM_Interpreter_FullAcro: public PWM_Interpreter{//Template for class which interpretes radio PWM signals into flight control signals.
  
 public:

 bool Armed;

 float Aileron;

 float Elevator;

 float Throttle;

 float Rudder;

 int Radio_CH5;
 
 int Radio_CH6;
 
 int Radio_CH7;
 
 int Radio_CH8;
 
 int Radio_CH9;
 
 int Radio_CH10;
 
 int Pitch;//Absolute pitch
 
 int Roll;//Absolute roll
 
 int Yaw;//Absolute yaw. Not allways supported
 
 int PitchDelta;// Rotational velocity around pitch / x axis
 
 int RollDelta;// Rotational velocity around roll / y axis
 
 int YawDelta;// Rotational velocity around yaw / z axis

 float ChannelScale;// Scales normalized channel signal to create degrees/second target for motors

 int ChannelWidth;//Set min value for channels

 int ChannelMaximum;// Set max value for channels 

 int ChannelMiddle;// Set middle value for channels

 long ArmingTimer;//Counts how long stick is in arm position

 long DisarmingTimer;//Counts how long stick is in disarm position
 
 void Build(int ch_max, int ch_mid, float scale){// Prototype function for building and initializing device

   ArmingTimer = 0;

   DisarmingTimer = 0;

   Armed = false;
   
   ChannelMaximum = ch_max;// Set channel maximum micros

   ChannelMiddle = ch_mid;// Set channel middle micros

   ChannelScale = scale;// set scale deg/sec

   ChannelWidth = (ChannelMaximum - ChannelMiddle);
  
 }
 void Read(){// Prototype function for reading data from device 
  
  PWM_Input_10CH_1v1v0::GatherResults();//Get radio controls from reciever.

 }
 void InterperateSignals(){;// Prototype function for calculating motion data from raw data (pitch, roll, yaw)

  Read();// Gather results from PWM reader.

  
  

 if(PWM_Input_10CH_1v1v0::Time_3 < 1150 && PWM_Input_10CH_1v1v0::Time_4 < 1180){
  ArmingTimer += 2;
 }
 if(PWM_Input_10CH_1v1v0::Time_3 < 1150 && PWM_Input_10CH_1v1v0::Time_4 > 1850){
  DisarmingTimer += 2;
 }

  if(ArmingTimer > 0){
    ArmingTimer -=1;
  }
  if(DisarmingTimer > 0){
    DisarmingTimer -=1;
  }
  if(ArmingTimer > 100){
    Armed = true;
    ArmingTimer = 0;
  }
  if(DisarmingTimer > 50){
    Armed = false;
    DisarmingTimer = 0;
  }
  
  
  float aileronControl = PWM_Input_10CH_1v1v0::Time_1 - ChannelMiddle;// Get aileron (roll) stick value relative to middle position. stick at 1000, middle 1500. 1000-1500 = -500

  aileronControl = aileronControl / (float)(ChannelWidth);// Normalize stick value (-1.0, 1.0). = 500 / (500)

  Aileron = aileronControl * ChannelScale;// Scale normalized stick value to degrees/second

  if(Aileron < 3 && Aileron > -3){
    
    Aileron = 0.0;
    
  }

  float elevatorControl = PWM_Input_10CH_1v1v0::Time_2 - ChannelMiddle;// Get elevator (pitch) stick value relative to middle position. stick at 1000, middle 1500. 1000-1500 = -500

  elevatorControl = elevatorControl / (float)(ChannelWidth);// Normalize stick value (-1.0, 1.0). = 500 / (500)

  Elevator = elevatorControl * ChannelScale;// Scale normalized stick value to degrees/second

  if(Elevator < 3 && Elevator > -3){
    
    Elevator = 0.0;
    
  }

  float rudderControl = PWM_Input_10CH_1v1v0::Time_4 - ChannelMiddle;// Get elevator (pitch) stick value relative to middle position. stick at 1000, middle 1500. 1000-1500 = -500

  rudderControl = rudderControl / (float)(ChannelWidth);// Normalize stick value (-1.0, 1.0). = 500 / (500)

  Rudder = rudderControl * ChannelScale;// Scale normalized stick value to degrees/second

  if(Rudder < 3 && Rudder > -3){
    
    Rudder = 0.0;
    
  }


  Throttle = PWM_Input_10CH_1v1v0::Time_3;// Scale normalized stick value to degrees/second

  
  
 }
 
};

#endif


