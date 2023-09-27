/*
 * MoveMotor:
 * function used to move stepper motor
 * - rotDir: indicates if the rotation is clockwise (True) or anticlockwise (False)
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
