


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

#include "MPU6050.h"
#include "I2Cdev.h"
#include "MotionSensor_Prototypes.h"
using namespace std;



class AccelerometerGyro_MPU6050: public MotionSensor_6DOF{//Use 6dof Motion sensor template
  
public:
  
 MPU6050 Device;//create MPU6050 device handling class
 
 //Declare member variables for data
 
 float Pitch;//absolute pitch
 
 float Roll;//absolute roll
 
 int PitchDelta;//rotational velocity around pitch
 
 int RollDelta;//rotational velocity around roll
 
 int YawDelta;//rotational velocity around yaw
 
 int16_t ax, ay, az;//declare raw accelerometer axis variables.
 
 int16_t gx, gy, gz;//declare raw gyro axis variable.
 
 float Ax, Ay, Az;//Declare smoothed accelerometer variables.
 
 float Gx, Gy, Gz;//Declare smoothed gyro variables.
 
 
 void Build(){
  
    while(true){//Initialize MPU6050 or hang entire system
      
     Device.initialize();//initialize MPU6050
     
     Device.setDLPFMode(0);// set sample rate to 8kHz
     
     Device.setFullScaleGyroRange(2);// set gyre range to +/- 1000 deg/sec
     
     Device.setFullScaleAccelRange(3);//set accel range to +/- 16g
     
     bool success = Device.testConnection();//Test MPU6050 connection
     
     Serial.println("Attempting to connect to MPU_6050");//Print attempts
     
     if(success == true){//Check if MPU6050 connection successful.
      
        break;// If so, break initialization loop
        
     }
     
    }
    
  }

 void Read(){
  
  Device.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);//Get raw data from MPU6050

  Ax = Ax*0.9 + ax*0.1;//smooth raw data running average over 10 samples.
  
  Ay = Ay*0.9 + ay*0.1;//smooth raw data running average over 10 samples.
  
  Az = Az*0.9 + az*0.1;//smooth raw data running average over 10 samples.

  Gx = Gx*0.9 + gx*0.1;//smooth raw data running average over 10 samples.
  
  Gy = Gy*0.9 + gy*0.1;//smooth raw data running average over 10 samples.
  
  Gz = Gz*0.9 + gz*0.1;//smooth raw data running average over 10 samples.

  Gx /= 3276.8;//normalize gyro to (-1.0 , 1.0)
  
  Gy /= 3276.8;//normalize gyro to (-1.0 , 1.0)
  
  Gz /= 3276.8;//normalize gyro to (-1.0 , 1.0)
 }
 void CalculateMotion(){
  
  Read();//Read raw values from MPU6050
  
  int AccelX = (Ax*3.9);//scale raw data for angle calculations
  
  int AccelY = (Ay*3.9);//scale raw data for angle calculations
  
  int AccelZ = (Az*3.9);//scale raw data for angle calculations
  
  Pitch = atan2(AccelX, AccelZ) * 180/3.14159; //Calculate pitch in degrees. 0 = level. forward pitch -> -180.  backward pitch -> 180
  
  Roll = atan2(AccelY, AccelZ) * 180/3.14159;//Calculate roll in degrees. 0 = level. right roll -> -180.  left roll -> 180
  
  PitchDelta = (Gx*1000);//convert gyro to degrees/second. Gyro range is set to level 2 or 1000deg/sec. scaled = normalized (-1.0 , 1.0) * 1000 deg max
  
  RollDelta = (Gy*1000);//convert gyro to degrees/second. Gyro range is set to level 2 or 1000deg/sec. scaled = normalized (-1.0 , 1.0) * 1000 deg max
  
  YawDelta = (Gz*1000);//convert gyro to degrees/second. Gyro range is set to level 2 or 1000deg/sec. scaled = normalized (-1.0 , 1.0) * 1000 deg max
  
 }
 
};





