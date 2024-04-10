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

/*
void moveAxis(Stepper stepper_motor, int how_much_to_rotate) 
{
    // una rotazione in una direzione
    Serial.println("Rotazione in corso");
    stepper_motor.step(how_much_to_rotate);
    delay(1000);

    
}*/
