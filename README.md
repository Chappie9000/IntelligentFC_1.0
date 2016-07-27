# IntelligentFC_1.0
Author notes:
If you stumble upon this project and are interested in developing, I am open to colaboration on the code and vision/use. Feel free to offer edits to the README.md.

I am building this repository for anyone who wishes they had a simple method for uploading to their Arduino board existing code for a multi-rotor quad-copter. My goal is the only downloads are the Arduino IDE and this repository and all code necessary is contained in included source files. I also try to comment on every possible line I write to give an english narraration of the code to help developers and tinkerers. I will also provide dynamic controllers that eliminate the majority of the PID tuning effort. Instead of a GUI, I plan on making this system's setup a text file where the user can change the values of various variables, affecting features, while also giving the user full access to the control loop code so they can make any modifications. Yet, if the user just wants to fly, no setup is necessary.

Current hardware: 
Arduino Due, MPU6050

Abstract:
A racing/performance multi-rotor flight controller software, built to piggy-back on Arduino IDE and hardware, primarily employing artificial intelligence to minimize user tuning. Heavily focused on transparency, portability, and independence.
This is intended to be flash and fly for the user, requiring minimal user preferences and/or knowledge of control dynamics and PID tuning. Most multi-rotor builds have achievable optima in rotational performance and the goal is to make systems that find optima automatically as quickly as possible. I also want this to have educational value, allowing a curious beginner full access to the entire stack of an AI UAV system.

User Operation:
For a user to use this software, they must download Arduino IDE, install Due board driver through Arduino IDE, clone this repository, open the main .ino file with Arduino IDE, specify user preferences in a particular header file, and upload the code to the proper board. I will eventually provide schematics for a shield to provide easy hobbyist accessability to the board.

Developer Guidelines:
All functionality must exist either in the standard Arduino IDE c/c++ libraries, or be fully expressed in committed source code. No 3rd party intallations can be required. MIT License prefered. Hardware additions are welcome, please include hardware documentation and follow all developer guidelines.
