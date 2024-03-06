void move(int motor; bool direction){
  digitalWrite(motor, direction);
}

void set_pwm(int pwm_value, int pwm_pin, int pwm_actual_value){
  if(pwm_value > pwm_actual_value){
    for(int i=pwm_actual_value; i<=pwm_value; i++){
      analogWrite(pwm_pin, i);
    }
  }
  else{
    for(int i=pwm_actual_value; i>=pwm_value; i--){
      analogWrite(pwm_pin, i);
    }
  }
  
}


void move_axis(){

}