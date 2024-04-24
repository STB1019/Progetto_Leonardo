#include "PIN_OUT_FINAL.h"

int pwm_value = pwm_start_value;

int tmp_pwm = 0; 

void move(int motor, bool direction){
  digitalWrite(motor, direction);
}

//automatic setter of the pwm value in decreasing and increasing pwm value modes
void set_pwm(int pwm_v, int pwm_pin){
  if(pwm_v > pwm_value){
    for(int i=pwm_value; i<=pwm_v; i++){
      delay(10);
      analogWrite(pwm_pin, i);
      tmp_pwm = i;
    }
    pwm_value = tmp_pwm;

  }
  else{
    for(int i=pwm_value; i>=pwm_v; i--){
      delay(10);
      analogWrite(pwm_pin, i);
      tmp_pwm = i;
    }
    pwm_value = tmp_pwm;
  }
  
}


//method to stop the movement of the DC mothors
void stop_movement(){
  set_pwm(0, PWM_PIN);
}

//default value of the PWM signal controlling the DC motors
void default_movement(){
  set_pwm(200, PWM_PIN);
}


void forward(){
  move(dir_dc1, LOW);
  move(dir_dc2, LOW);
  move(dir_dc3, HIGH);
  move(dir_dc4, HIGH);
}

void back(){
  move(dir_dc1, HIGH);
  move(dir_dc2, HIGH);
  move(dir_dc3, LOW);
  move(dir_dc4, LOW);

}

void left(){
  
  move(dir_dc1, LOW);
  move(dir_dc2, LOW);
  move(dir_dc3, LOW);
  move(dir_dc4, LOW);

}

void right(){
  
  move(dir_dc1, HIGH);
  move(dir_dc2, HIGH);
  move(dir_dc3, HIGH);
  move(dir_dc4, HIGH);
  
}


/*
void moveAxis(Stepper stepper_motor, int how_much_to_rotate) 
{
    // una rotazione in una direzione
    Serial.println("Rotazione in corso");
    stepper_motor.step(how_much_to_rotate);
    delay(1000);

    
}*/

/*
Example sketch to control a stepper motor with A4988 stepper motor driver and Arduino without a library. More info: https://www.makerguides.com 

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
*/
void moveAxis(int dir_pin_axis, int step_pin_axis, bool direction) {
  digitalWrite(dir_pin_axis , HIGH);

  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
  
      digitalWrite(step_pin_axis, direction);
      delayMicroseconds(500);
    
  }
  
}  
  


