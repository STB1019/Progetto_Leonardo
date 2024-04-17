//#include "Serial_communication.h"
#include "PIN_OUT_FINAL.h"
//#include "Stepper2.h"
//#include "Sonar_Completo_Leonardo.h"
#include "SoftwareSerial.h"
#include "Movement.h"


/*
Stepper Stepper1(stepsPerRevolution, dir_step1,step1);
Stepper Stepper2(stepsPerRevolution, dir_step2,step2);
Stepper Stepper3(stepsPerRevolution, dir_step3,step3);
Stepper Stepper4(stepsPerRevolution, dir_step4,step4);  */

void setup(){
  
  pinMode(dir_dc1, OUTPUT);
  pinMode(dir_dc2, OUTPUT);
  pinMode(dir_dc3, OUTPUT);
  pinMode(dir_dc4, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  
}
void loop(){

  dummyMovement();

}

//TO BE TESTED THE MOTOR MAPPING
void dummyMovement(){
  move(dir_dc1, LOW);
  move(dir_dc2, LOW);
  move(dir_dc3, HIGH);
  move(dir_dc4, HIGH);
  analogWrite(6, 200);
  //default_movement();
/*
  delay(2000);
  stop_movement();
  delay(2000);

  move(dir_dc1, HIGH);
  move(dir_dc2, HIGH);
  move(dir_dc3, LOW);
  move(dir_dc4, LOW);
  
  default_movement();

  

  delay(2000);
  stop_movement();
  delay(2000);
  


*/
}
