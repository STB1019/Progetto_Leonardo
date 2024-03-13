//#include "Serial_communication.h"
#include "PIN_OUT_FINAL.h"
#include "Stepper2.h"
//#include "Sonar_Completo_Leonardo.h"
#include "SoftwareSerial.h"
#include "Movement.h"



Stepper Stepper1(stepsPerRevolution, dir_step1,step1);
Stepper Stepper2(stepsPerRevolution, dir_step2,step2);
Stepper Stepper3(stepsPerRevolution, dir_step3,step3);
Stepper Stepper4(stepsPerRevolution, dir_step4,step4);

void setup(){
  default_movement();
  
}
void loop(){

  dummyMovement();

}

//TO BE TESTED THE MOTOR MAPPING
void dummyMovement(){
  move(dir_dc1, false);
  move(dir_dc2, false);
  move(dir_dc3, true);
  move(dir_dc4, true);

  delay(1000);
  stop_movement();
  delay(100);
  default_movement();

  move(dir_dc1, true);
  move(dir_dc2, true);
  move(dir_dc3, false);
  move(dir_dc4, false);

  delay(1000);
  stop_movement();
  delay(100);
  default_movement();



}