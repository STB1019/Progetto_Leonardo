#include "Stepper_Function.h"


/*Example sketch to control a stepper motor with A4988 stepper motor driver and Arduino without a library. More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
#define dirPin1 7
#define stepPin1 8

#define dirPin2 9
#define stepPin2 10

#define dirPin3 11
#define stepPin3 12

#define dirPin4 13
#define stepPin4 A0
#define stepsPerRevolution 200
bool done = false;

/*
  4mm per revolution
*/


void setup() {
  // Declare pins as output:
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
}

void loop() {
  
  if(!done){
    //true verso motore
    moveMotor(false, dirPin1, stepPin1, 1000, 25, 0);
    moveMotor(true, dirPin1, stepPin1, 1000, 25, 0);
    done = true;
  }

  /*if(!done){
    //true verso motore
    moveMotorAcc(false, dirPin, stepPin, 1500, 1000, 200, 10, 0);
    moveMotorAcc(true, dirPin, stepPin, 1500, 1000, 200, 10, 0);
    done = true;
  }*/
  
}
