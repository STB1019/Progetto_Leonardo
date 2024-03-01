bool check_endrun(int min_pin, int max_pin, int dirPin, int stepPin, int currentPos){
  
  int value_min = digitalRead(min_pin);
  int value_max = digitalRead(max_pin);

  //checks which endrun sensor is active, and moves to the middle of the axis
  
  if(value_min == 1|| value_max == 1){
    if(value_min == 1){
      
      currentPos = moveMotor(counter_rot, dirPin, stepPin, microDelay, stepsPerRevolution, currentPos);
    }
    else{
      currentPos = moveMotor(clock_rot, dirPin, stepPin, microDelay, stepsPerRevolution, currentPos);
    }
    return true;
  }
  return false;
}

void endrun_checker(){
  
  check_endrun(ENDRN_F_MIN, ENDRN_F_MAX, DIR_PIN_F, STEP_PIN_F, current_pos_f);
  check_endrun(ENDRN_C_MIN, ENDRN_C_MAX, DIR_PIN_C, STEP_PIN_C, current_pos_c);
  check_endrun(ENDRN_B_MIN, ENDRN_B_MAX, DIR_PIN_B, STEP_PIN_B, current_pos_b);
  check_endrun(ENDRN_CG_MIN, ENDRN_CG_MAX, DIR_PIN_CG, STEP_PIN_CG, current_pos_cg);

}
