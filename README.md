# IntelligentFC_1.0
Author notes:
If you stumble upon this project and are interested in developing, I am open to colaboration on the code and vision/use. Feel free to offer edits to the README.md.

When I first started experimenting with multi-rotors, I wanted to build my own from scratch. However, I had a lot of trouble finding working versions that could upload to an Arduino via Arduino IDE without errors. There was allways some library I didn't have and couldn't find, and was often times cluttered with hard to read infinitely inherrited code making it a very time consuming to back-track through the #include paths to find and understand the code. After spending at least a week trying to piece together my own code, I hit another hurdle, PID tuning.

I am building this repository for anyone who wishes they had a simple method for uploading to their Arduino board existing code for a multi-rotor quad-copter. My goal is the only downloads are the Arduino IDE and this repository and all code necessary is contained in included source files. I also try to comment on every possible line I write to give an english narraration of the code to help developers and tinkerers. I will also provide dynamic controllers that eliminate the majority of the PID tuning effort. I also don't prefer most of the existing multi-rotor setup GUIs, so I plan on making this system's setup a text file where the user can change the values of various variables, effecting features, while also giving the user full access to the control loop code so they can make any modifications. Yet, if the user just wants to fly, no setup is necessary.

Current hardware: 
Arduino Due
MPU6050

Abstract:
A racing/performance multi-rotor flight controller software, built to piggy-back on Arduino IDE and hardware, primarily employing artificial intelligence to minimize user tuning. Heavily focused on transparency, portability, and independence.
This is intended to be flash and fly for the user, requiring minimal user preferences and/or knowledge of control dynamics and PID tuning. Most multi-rotor builds have achievable optima in rotational performance and the goal is to make systems that find optima automatically as quickly as possible, preferablyonline and from nothing but source code at launch. I also want this to have educational value, allowing a curious beginner full access to the entire stack of an AI UAV system.


For a user to use this software, they must download Arduino IDE, install Due board driver through Arduino IDE, clone this repository, open the main .ino file with Arduino IDE, specify user preferences in a particular header file, and upload the code to the proper board. I will eventually provide schematics for a shield to provide easy hobbyist accessability to the board.

All functionality must exist either in the standard Arduino IDE c/c++ libraries, or be fully expressed in committed headder files. No 3rd party intallations can be required. MIT License prefered. No deprecations or removals only additions and fixes.
