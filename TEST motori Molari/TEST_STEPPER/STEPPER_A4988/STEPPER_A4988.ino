/*Example sketch to control a stepper motor with A4988 stepper motor driver and Arduino without a library. More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
#define dirPin1 7
#define stepPin1 8

#define dirPin2 9
#define stepPin2 10

#define dirPin3 11
#define stepPin3 12

#define dirPin4 A0
#define stepPin4 13

#define stepsPerRevolution 200

void setup() {
  // Declare pins as output:
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(dirPin3, OUTPUT);
  pinMode(stepPin4, OUTPUT);
  pinMode(dirPin4, OUTPUT);
}

void loop() {


  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin1,HIGH);
  
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin4, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4, LOW);
    delayMicroseconds(500);
  }

/*
  //Spin the stepper motor 5 revolutions fast:
  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin4, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin4, LOW);
    delayMicroseconds(500);
  }*/

}
