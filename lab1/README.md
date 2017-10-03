##Skeleton Code
This is skeleton code for Arduino and Communication between Arduino and Raspberry Pi. 

The code is written in c++ and Python. Basic knowledge of c++ and [python](https://learnxinyminutes.com/docs/python/) is needed for comfortable coding experince. 

#####Workshop 1:
During Workshop 1 you will only use 'Pi_Arduino' portion written in c++. It has skeleton code for Arduino. 

####Pi_Arduino
It includes skeleton for implemnting PID and Communication Protocol between Arduino and RaspberryPi(needed for Workshop 2).

'Pi_Arduino.ino' is the main file which includes declaration and initializations. Here objects to left and right motor are initialized from Motor class. Interrupts are attached for encoders. 

'motors.h' has the declarations of motor class, functions which need to be filled up for implementing PID. 

Rpi Arduino Communication
readSerialCmd() and 'raspberryCom.ino' are needed to establish communication between Rpi and Arduino. We will look into it later. 

####Workshop 2:

####Rpi
This folder includes sample code for raspberry Pi to communicate with Arduino with Arduino connected to raspberry Pi with USB. 

'pi_main.py' is the main python which includes declarations and main. An object to Arduino class(defined in 'arduinoCom.py') is created and method to connect to Arduino is called. 

Once the Connection is established, commands can be sent to Arduino to set angular and linear velocity. 

Communication protocol:

 There is a initial Handshake to check communication and later Rpi sends information to set linear and angular velocities, Arduino returns the set values.  The below image shows the same.

![](https://github.com/KTH-EL2222/code/blob/master/Communication_Arduino_Rpi.JPG)
