#include "Arduino.h"
#include "PINOUT_ESP.h"

/*
void move(int motor, String direction){
  digitalWrite(motor, direction);
}
*/
//automatic setter of the pwm value in decreasing and increasing pwm value modes
void set_pwm(int pwm_v){
  int pwm_value = analogRead(PWM_PIN);
  if(pwm_v > pwm_value){
    for(int i=pwm_value; i<=pwm_v; i++){
      delay(1);
      analogWrite(PWM_PIN, i);

    }
    

  }
  else{
    for(int i=pwm_value; i>=pwm_v; i--){
      delay(50);
      analogWrite(PWM_PIN, i);
    }
    
  }
  
}




//method to stop the movement of the DC mothors
void stop_movement(){
  analogWrite(PWM_PIN, 0);
}

//default value of the PWM signal controlling the DC motors
void default_movement(){
  analogWrite(PWM_PIN, 255);
}


void left_mov(){
  
  
  digitalWrite(dir_dc1, LOW); 
  digitalWrite(dir_dc2, HIGH);
  digitalWrite(dir_dc3, HIGH);
  digitalWrite(dir_dc4, LOW);

  digitalWrite(dir_dc1_2, LOW);
  digitalWrite(dir_dc2_2, HIGH);
  digitalWrite(dir_dc3_2, HIGH);
  digitalWrite(dir_dc4_2, LOW);
  
}

void right_mov(){
  
  digitalWrite(dir_dc1, HIGH);
  digitalWrite(dir_dc2, LOW);
  digitalWrite(dir_dc3, LOW);
  digitalWrite(dir_dc4, HIGH);

  digitalWrite(dir_dc1_2, HIGH); 
  digitalWrite(dir_dc2_2, LOW);
  digitalWrite(dir_dc3_2, LOW);
  digitalWrite(dir_dc4_2, HIGH);
  
}

void forward_mov(){
  
  digitalWrite(dir_dc1, HIGH);
  digitalWrite(dir_dc2, LOW);
  digitalWrite(dir_dc3, HIGH);
  digitalWrite(dir_dc4, LOW);

  digitalWrite(dir_dc1_2, HIGH);
  digitalWrite(dir_dc2_2, LOW);
  digitalWrite(dir_dc3_2, HIGH);
  digitalWrite(dir_dc4_2, LOW);
  
}

void back_mov(){
  
  digitalWrite(dir_dc1, LOW);
  digitalWrite(dir_dc2, HIGH);
  digitalWrite(dir_dc3, LOW);
  digitalWrite(dir_dc4, HIGH);

  digitalWrite(dir_dc1_2, LOW);
  digitalWrite(dir_dc2_2, HIGH);
  digitalWrite(dir_dc3_2, LOW);
  digitalWrite(dir_dc4_2, HIGH);
  
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
- timer_microseconds : parameter that defines the lenght of the movement

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