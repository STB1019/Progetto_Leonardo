/*
 * MoveMotor:
 * function used to move stepper motor
 * - rotDir: indicates if the rotation is clockwise (True, going to the motor) or anticlockwise (False, distancing to the motor)
 * - dirPin: direction pin
 * - stepPin: step pin
 * - delayMicr: used for changing speed, 2000 for example is slow and 500 is fast 
 * - stepPRevMult: is a multiplier, for example if you want the stepper to rotate 3 revolution, this value is 3.
 * - currentPos: current motor position
 * 
 * This function doesn't need external libreries
 * Thomas :)
*/
int moveMotor(bool rotDir, const int dirPin, const int stepPin, int delayMicr, int stepPRevMult, int currentPos){

  /*
   * I choose if the direction is clockwise or not, and calculate the currentPos
  */
  if(rotDir){
    digitalWrite(dirPin, HIGH); //clockwise
    currentPos = currentPos + (int)(stepsPerRevolution * stepPRevMult);
  }
  else{
    digitalWrite(dirPin, LOW); //anticlockwise
    currentPos = currentPos - (int)(stepsPerRevolution * stepPRevMult);
  }
  
  for (int i = 0; i < (int)(stepsPerRevolution * stepPRevMult); i++) {
    
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delayMicr);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delayMicr);
  }

  return currentPos;
}

/*
 * calibration function for stepper motors
 * 
 * initial phase of putting the stepper motors the lowest, stopping from the endun signal.
 * second phase of lifting the axis by a determined height 
 * 
 * NB the current pos returned is the same for every axis
 * 
 */
void calibrationStepper(int delayMicr, int stepPRevMult){
  
  int currentPos = 0;
 
  digitalWrite(DIR_PIN_F, HIGH); //clockwise
  digitalWrite(DIR_PIN_C, HIGH); //clockwise
  digitalWrite(DIR_PIN_B, HIGH); //clockwise
  digitalWrite(DIR_PIN_CG, HIGH); //clockwise
  
  while(checkEndrun()){
    
    digitalWrite(STEP_PIN_F, HIGH);
    digitalWrite(STEP_PIN_C, HIGH);
    digitalWrite(STEP_PIN_B, HIGH);
    digitalWrite(STEP_PIN_CG, HIGH);
    
    delayMicroseconds(delayMicr);
    
    digitalWrite(STEP_PIN_F, LOW);
    digitalWrite(STEP_PIN_C, LOW);
    digitalWrite(STEP_PIN_B, LOW);
    digitalWrite(STEP_PIN_CG, LOW);
    
    delayMicroseconds(delayMicr);
    
  }
  
  digitalWrite(DIR_PIN_F, LOW); //anticlockwise
  digitalWrite(DIR_PIN_C, LOW); //anticlockwise
  digitalWrite(DIR_PIN_B, LOW); //anticlockwise
  digitalWrite(DIR_PIN_CG, LOW); //anticlockwise
  
  currentPos = (int)(stepsPerRevolution * stepPRevMult);
  
  for (int i = 0; i < (int)(stepsPerRevolution * stepPRevMult); i++) {
    
    digitalWrite(STEP_PIN_F, HIGH);
    digitalWrite(STEP_PIN_C, HIGH);
    digitalWrite(STEP_PIN_B, HIGH);
    digitalWrite(STEP_PIN_CG, HIGH);
    
    delayMicroseconds(delayMicr);
    
    digitalWrite(STEP_PIN_F, LOW);
    digitalWrite(STEP_PIN_C, LOW);
    digitalWrite(STEP_PIN_B, LOW);
    digitalWrite(STEP_PIN_CG, LOW);
    
    delayMicroseconds(delayMicr);
    
  }
  
  return currentPos;
}