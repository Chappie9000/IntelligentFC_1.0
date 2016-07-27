# IntelligentFC_1.0
If you stumble upon this project and are interested, I am open to colaboration on the code and vision/use. Feel free to offer edits to the README.md.

Current hardware: Arduino Due

Abstract:
A racing/performance multi-rotor flight controller software, built to piggy-back on Arduino IDE and hardware, primarily employing artificial intelligence to minimize user tuning. Heavily focused on transparency, portability, and independence.
This is intended to be flash and fly for the user, requiring minimal user preferences and/or knowledge of control dynamics and PID tuning. Most multi-rotor builds have achievable optima in rotational performance and the goal is to make systems that find optima automatically as quickly as possible, preferably from nothing at launch. I also want this to have educational value, allowing a curious beginner full access to the entire stack of an AI system.


For a user to use this software, they must download Arduino IDE, clone this repository, open the main file with Arduino IDE, specify user preferences in a particular header file, and upload the code to the proper board. I will eventually provide schematics for a shield to provide easy hobbyist accessability to the board.

All functionality must exist either in the standard Arduino IDE c/c++ libraries, or be fully expressed in committed headder files. No 3rd party intallations can be required.
