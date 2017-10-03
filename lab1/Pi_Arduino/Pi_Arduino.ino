#include "motors.h"

const double DEG_PER_TIC = (double)360/(double)192;
const double RAD_PER_DEG = (double)3.141/(double)180;
const double WHEEL_RADIUS = 0.06425/2;
const double ROBOT_BASE = 0.13;
const double TICS_PER_ROTATION = 192;
unsigned int left_enc_count, right_enc_count;
unsigned long time_prev, time_now;
double left_angular_vel, right_angular_vel, left_vel, right_vel;
//Create motor objects with connections and  parameters
//arguements: encoder pin, to motor : out1, out2, enable pin,inverse direction,Kp,Ki,Kd
Motor left_motor(3,8,9,5,false,15,0.5,0.3);
Motor right_motor(2,11,10,6,true,7,0.5,0.3);

void setup() {
  //Serial communication initialization
  Serial.begin(9600);
  left_vel = 0.2;
  right_vel = 0.2;
  //Configure interrupt pins for encoders
  attachInterrupt(digitalPinToInterrupt(left_motor.ENCODER_PIN), left_tic_counter, RISING);
  attachInterrupt(digitalPinToInterrupt(right_motor.ENCODER_PIN), right_tic_counter, RISING);
}

void loop() {
  //function to read and intrepret the serial data received from raspberrypi
  readSerialCmd();
  //move Robot - Use below functions to set reference speed and direction of motor.
  left_motor.rotate(left_vel/WHEEL_RADIUS/(RAD_PER_DEG * DEG_PER_TIC * TICS_PER_ROTATION), 1);
  right_motor.rotate(right_vel/WHEEL_RADIUS/(RAD_PER_DEG * DEG_PER_TIC * TICS_PER_ROTATION), 1);
  left_angular_vel = left_motor.get_angular_vel();
  right_angular_vel = right_motor.get_angular_vel();

  //Serial.print(left_angular_vel);Serial.print(",");
  Serial.print(left_angular_vel * WHEEL_RADIUS * (RAD_PER_DEG * DEG_PER_TIC * TICS_PER_ROTATION));Serial.print(", ");
  Serial.println(right_angular_vel * WHEEL_RADIUS * (RAD_PER_DEG * DEG_PER_TIC * TICS_PER_ROTATION));//Serial.print(", ");
  //Serial.print(left_motor.tic_count);//Serial.print(", ");//Serial.println(right_motor.tic_count);
  delay(50);//Defines control loop frequency  
}

//Callback functions when interrupt are triggered by encoders
void left_tic_counter(){
  //call motor tick counter
  left_motor.tic_counter();
}
void right_tic_counter(){
  //call motor tick counter
  right_motor.tic_counter();
}

