


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

#ifndef _PWM_INPUT_10CH_1V1V0_H_INCLUDED_
#define _PWM_INPUT_10CH_1V1V0_H_INCLUDED_

#include "Arduino.h"



namespace PWM_Input_10CH_1v1v0{//namespace for 10 channel PWM-input version 1.1.0

 
// PWM_Input namespace is primarily for creating and handling PWM inputs from radio recievers.
// It uses a pin interupt to calculate the pulse width in microseconds.
// The values are available as namespac static local variables
// The interrupt functions need to be static with no arguments.
// I don't know how to make some polymorphic object for dynamically creating static interrupt tasks.
// So unfortunatelly this namespace is static.
// I made 10 channels/interrupts to leave some room for extra functionality.
// Having unused pin interrupts build and running doesn't significantly reduce performance. 
// The next step is probably making a serial reader protocol.
// Contribution to this would be welcome.


 volatile int StartTime_1, StartTime_2, StartTime_3, StartTime_4, StartTime_5, StartTime_6, StartTime_7, StartTime_8, StartTime_9, StartTime_10;//memory space for state change times
 
 volatile int EndTime_1, EndTime_2, EndTime_3, EndTime_4, EndTime_5, EndTime_6, EndTime_7, EndTime_8, EndTime_9, EndTime_10;//memory space for state change times
 
 int Time_1, Time_2, Time_3, Time_4, Time_5, Time_6, Time_7, Time_8, Time_9, Time_10;//PWM wave state-change period
 
 volatile int Pin_1, Pin_2, Pin_3, Pin_4, Pin_5, Pin_6, Pin_7, Pin_8, Pin_9, Pin_10;//Board pin #


 void GatherResults(){//Syncronize updating of all channel values. Prevent values from changing mid loop.
  
  int tTime_1 = (EndTime_1 - StartTime_1);//calculate time difference = pulse width in microseconds. Value accessable through member variable.
  
  if(tTime_1 < 2080){// Check if value is in RC range, 1000-2000 micro sec
    
   Time_1 = tTime_1;// If so, set time to that. If not, time remains from previous loop.
   
  }
  
  int tTime_2 = (EndTime_2 - StartTime_2);//repeat static declarations for all channels
  
  if(tTime_2 < 2080){
    
   Time_2 = tTime_2;
   
  }
  int tTime_3 = (EndTime_3 - StartTime_3);//repeat static declarations for all channels
  
  if(tTime_3 < 2080){
    
   Time_3 = tTime_3;
   
  }
  
  int tTime_4 = (EndTime_4 - StartTime_4);//repeat static declarations for all channels
  
  if(tTime_4 < 2080){
    
   Time_4 = tTime_4;
   
  }
  
  int tTime_5 = (EndTime_5 - StartTime_5);//repeat static declarations for all channels
  
  if(tTime_5 < 2080){
    
   Time_5 = tTime_5;
   
  }
  
  int tTime_6 = (EndTime_6 - StartTime_6);//repeat static declarations for all channels
  
  if(tTime_6 < 2080){
    
   Time_6 = tTime_6;
   
  }
  
  int tTime_7 = (EndTime_7 - StartTime_7);//repeat static declarations for all channels
  
  if(tTime_7 < 2080){
    
   Time_7 = tTime_7;
   
  }
  
  int tTime_8 = (EndTime_8 - StartTime_8);//repeat static declarations for all channels
  
  if(tTime_8 < 2080){
    
   Time_8 = tTime_8;
   
  }
  
  int tTime_9 = (EndTime_9 - StartTime_9);//repeat static declarations for all channels
  
  if(Time_9 < 2080){
    
   Time_9 = tTime_9;
   
  }
  
  int tTime_10 = (EndTime_10 - StartTime_10);//repeat static declarations for all channels
  
  if(tTime_10 < 2080){
    
   Time_10 = tTime_10;
   
  }
  
 }
 
 void Task_1(){//function to execute at interupt. 
  
  StartTime_1 = EndTime_1;//use previous time as last state change
  
  EndTime_1 = micros();//get current time
  
 }

  void Task_2(){//function to execute at interupt
  
   StartTime_2 = EndTime_2;//use previous time as last state change
   
   EndTime_2 = micros();//get current time
  
   
 }

  void Task_3(){//function to execute at interupt
  
   StartTime_3 = EndTime_3;//use previous time as last state change
  
   EndTime_3 = micros();//get current time
  
 }

  void Task_4(){//function to execute at interupt
  
   StartTime_4 = EndTime_4;//use previous time as last state change
  
   EndTime_4 = micros();//get current time
  
 }
 
  void Task_5(){//function to execute at interupt
  
   StartTime_5 = EndTime_5;//use previous time as last state change
  
   EndTime_5 = micros();//get current time
  
 }
 
  void Task_6(){//function to execute at interupt
  
   StartTime_6 = EndTime_6;//use previous time as last state change
  
   EndTime_6 = micros();//get current time
  
 }
 
  void Task_7(){//function to execute at interupt
  
   StartTime_7 = EndTime_7;//use previous time as last state change
  
   EndTime_7 = micros();//get current time
  
 }
 
  void Task_8(){//function to execute at interupt
  
   StartTime_8 = EndTime_8;//use previous time as last state change
  
   EndTime_8 = micros();//get current time
  
 }
 
  void Task_9(){//function to execute at interupt
  
   StartTime_9 = EndTime_9;//use previous time as last state change
  
   EndTime_9 = micros();//get current time
  
 }
 
  void Task_10(){//function to execute at interupt
  
   StartTime_10 = EndTime_10;//use previous time as last state change
  
   EndTime_10 = micros();//get current time
  
 }
 
 void Build_1(int pin){//Build a pin interrupt
  
   Pin_1 = pin;//set member pin # memory
  
   pinMode(Pin_1, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_1, CHANGE);//attach Task function to the pin
 
 }
 
  void Build_2(int pin){//Build a pin interrupt
  
   Pin_2 = pin;//set member pin # memory
  
   pinMode(pin, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_2, CHANGE);//attach Task function to the pin
 
 }
 
  void Build_3(int pin){//Build a pin interrupt
  
   Pin_3 = pin;//set member pin # memory
  
   pinMode(pin, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_3, CHANGE);//attach Task function to the pin
 
 }
 
  void Build_4(int pin){//Build a pin interrupt
  
   Pin_4 = pin;//set member pin # memory
  
   pinMode(pin, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_4, CHANGE);//attach Task function to the pin
 
 }
 
  void Build_5(int pin){//Build a pin interrupt
  
   Pin_5 = pin;//set member pin # memory
  
   pinMode(pin, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_5, CHANGE);//attach Task function to the pin
 
 }
 
  void Build_6(int pin){//Build a pin interrupt
  
   Pin_6 = pin;//set member pin # memory
  
   pinMode(pin, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_6, CHANGE);//attach Task function to the pin
 
 }
 
  void Build_7(int pin){//Build a pin interrupt
  
   Pin_7 = pin;//set member pin # memory
  
   pinMode(pin, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_7, CHANGE);//attach Task function to the pin
 
 }
 
  void Build_8(int pin){//Build a pin interrupt
   
   Pin_8 = pin;//set member pin # memory
  
   pinMode(pin, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_8, CHANGE);//attach Task function to the pin
 
 }
 
  void Build_9(int pin){//Build a pin interrupt
  
   Pin_9 = pin;//set member pin # memory
  
   pinMode(pin, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_9, CHANGE);//attach Task function to the pin
 
 }
 
  void Build_10(int pin){//Build a pin interrupt
  
   Pin_10 = pin;//set member pin # memory
  
   pinMode(pin, INPUT);//ready board to read pin
  
   attachInterrupt(digitalPinToInterrupt(pin), Task_10, CHANGE);//attach Task function to the pin
 
 }

  void Build_All(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8, int pin9, int pin10){//build all pins 

   // execute all pin building funcitons
   Build_1(pin1);
   Build_2(pin2);
   Build_3(pin3);
   Build_4(pin4);
   Build_5(pin5);
   Build_6(pin6);
   Build_7(pin7);
   Build_8(pin8);
   Build_9(pin9);
   Build_10(pin10);
   
  }
 
}

#endif
