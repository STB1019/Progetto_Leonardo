#include <PIN_OUT_FINAL.h>

void move(int motor; bool direction){
  digitalWrite(motor, direction);
}

//automatic setter of the pwm value in decreasing and increasing pwm value modes
void set_pwm(int pwm_value, int pwm_pin, int pwm_actual_value){
  if(pwm_value > pwm_actual_value){
    for(int i=pwm_actual_value; i<=pwm_value; i++){
      delay(10);
      analogWrite(pwm_pin, i);
    }
  }
  else{
    for(int i=pwm_actual_value; i>=pwm_value; i--){
      delay(10);
      analogWrite(pwm_pin, i);
    }
  }
  
}


//method to stop the movement of the DC mothors
void stop_movement(){
  set_pwm(0; PWM_PIN);
}

//default value of the PWM signal controlling the DC motors
void default_movement(){
  set_pwm(200, PWM_PIN);
}



void move_axis(){

}