#include "PIN_OUT_FINAL.h"


void move(int motor, bool direction){
  digitalWrite(motor, direction);
}

//automatic setter of the pwm value in decreasing and increasing pwm value modes
void set_pwm(int pwm_pin, int pwm_v){
  int pwm_value = analogRead(pwm_pin);
  if(pwm_v > pwm_value){
    for(int i=pwm_value; i<=pwm_v; i++){
      delay(50);
      analogWrite(pwm_pin, i);

    }
    

  }
  else{
    for(int i=pwm_value; i>=pwm_v; i--){
      delay(50);
      analogWrite(pwm_pin, i);
    }
    
  }
  
}


//method to stop the movement of the DC mothors
void stop_movement(){
  set_pwm(PWM_PIN, 0);
}

//default value of the PWM signal controlling the DC motors
void default_movement(){
  set_pwm(PWM_PIN, 200);
}


void forward(){
  move(dir_dc1, false);
  move(dir_dc2, false);
  move(dir_dc3, true);
  move(dir_dc4, true);
}

void back(){
  move(dir_dc1, true);
  move(dir_dc2, true);
  move(dir_dc3, false);
  move(dir_dc4, false);

}

void left(){
  
  move(dir_dc1, false);
  move(dir_dc2, false);
  move(dir_dc3, false);
  move(dir_dc4, false);

}

void right(){
  
  move(dir_dc1, true);
  move(dir_dc2, true);
  move(dir_dc3, true);
  move(dir_dc4, true);
  
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
  // Declare pins as output
}
*/

/*
function for automatic detection of direction and movement of the stepper motor on the linear asix
- dir_pin_axis : abilitation of the motor direction
- step_pin_axis : define direction of the
- direction : define direction of the movement. True = up, False = down
- timer_microsseconds : parameter that defines the lenght of the movement

*/

void moveAxis(int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds) {

  digitalWrite(dir_pin_axis , HIGH);

  for (int i = 0; i < 5 * stepsPerRevolution; i++) {
  
      digitalWrite(step_pin_axis, direction);
      delayMicroseconds(timer_microseconds);
      digitalWrite(step_pin_axis, !direction);
    
  }
  
  digitalWrite(dir_pin_axis, LOW);
}  
  


