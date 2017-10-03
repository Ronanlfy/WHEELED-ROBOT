#!/usr/bin/env python
import sys
import RPi.GPIO as GPIO
import serial
import time
from collections import Counter
import math
import arduinoCom
import pprint,os

#Variable to enable or disable code on Pi, this variable can be triggered from switch later.
Run = True
#Pin configuration type BCM
GPIO.setmode(GPIO.BCM)

#Close Serial Connections to Raspberry Pi
def Close_connection():
    GPIO.cleanup()
    robot.closeSerial()
    sys.exit('Empty Sear Found - Task finished')

#Create an Arduino Object which has base code for communication between Pi and Arduino
arduino = arduinoCom.Arduino()

time.sleep(2)

#Try connecting to Ardunio from any of the USB ports 
for i in range (10):
    if arduino.connect() == 1:
        print 'connection established'
        break
    else:
        print 'Connection failed'

#Sample code for using the set get protocol
while True:
   while Run is True:
       print arduino.set_value('lin_vel', 26)
       time.sleep(0.5)
       print arduino.set_value('ang_vel', 25)
       time.sleep(0.5)
