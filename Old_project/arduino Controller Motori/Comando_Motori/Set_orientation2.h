
/*
 * this function turns on the h bridges to enable you to do all the other
 * things
 */
void turn_on_bridges(){

  for(int i = 0, i < 21, i++){
    delay_milliseconds(100);
    analogWrite(pwm, i*10);
  }

}

void modify_pwm(int value){
  // setting the pwm to a value  
}


/*
 * this function turns off the h bridges so you will not be able to 
 * send signals from microcontroller
 */
void turn_off_bridges(){
  for(int i = 0, i < pwm_value, i++){
    delay_milliseconds(100);
    analogWrite(pwm, pwm_value - i*10);
  }
  
}


/*
 * this function turns off the modality of the orientation of all the pins
 * remembeer to call this function before calling a setup modality.
 */
void full_stop(){
    digitalWrite(dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(dir3,LOW);
    digitalWrite(dir4,LOW);
}

/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the clokwise for the left motors and the anticlkwise for the right 
 * engines they have opposite rotation in order to perform a forward move
 */
 
void forward_mode(){

  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,HIGH);
  
  digitalWrite(dir3,LOW);
  digitalWrite(dir4,LOW);
  
}


/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the anticlokwise for the left motors and the clkwise for the right 
 * engines, they have opposite rotation in order to perform a backward move
 */
void backward_mode(){

  digitalWrite(dir3,HIGH);
  digitalWrite(dir4,HIGH);
  
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);
  
}


/*
 5* this function sets the rotation mode direction of the pins of the h bridge
 * turns on the clokwise for the left motors and the clkwise for the right 
 * engines, so they have the same rotation in order to performe a right turn
 */
void turn_right_mode(){

  digitalWrite(dir1,HIGH);
  digitalWrite(dir3,HIGH);
  
  digitalWrite(dir2,LOW);
  digitalWrite(dir4,LOW);
  
}


/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the anticlokwise for the left motors and the anticlokwise for the right 
 * engines, so they have the same rotation in order to performe a left turn
 */
void turn_left_mode(){

  digitalWrite(dir2,HIGH);
  digitalWrite(dir4,HIGH);
  
  digitalWrite(dir1,LOW);
  digitalWrite(dir3,LOW);  
  
}
