//#include "PIN_OUT.h"
//#include "Set_Orientation.h"
//Stepper Thomas
#include "Stepper_Define.h"
//#include "Stepper_Function.h"
#include "PIN_OUT2.h"
#include "Set_orientation2.h"

#include "Endrun_Functions.h"
#include "Manual_Mode.h"



//Serial Mirko
#include "Serial_Controller.h"


#define DELAY 100
#define MIN 0 // min value of speed
#define MAX 1 // max value of speed


void setup() {

  Serial.begin(9600); // BEGINNING COMUNICATION RATE: 9600 bit/s
  /*
  /*
   * ALL OF THIS PINS ARE DIGITAL
   
  // FOR SERIAL COMUNICATION
   pinMode(TX,INPUT);
   pinMode(RX,OUTPUT);
   
  // H BRIDGE PIN 
   pinMode(STANDBY_R,OUTPUT);
   pinMode(STANDBY_L,OUTPUT);
   
  // ALL THE PINS TO MOVE THE ENGINS ARE IN OUTPUT MODE

  // SET OF PINS FOR PWM TO SET SPEED FROM
   pinMode(PWM_F_R,OUTPUT);
   pinMode(PWM_F_L,OUTPUT);
   pinMode(PWM_B_R,OUTPUT);
   pinMode(PWM_B_L,OUTPUT);
  
  //THIS IS A SET TO INDICATE AND ENABLE THE ENGINES DIRECTION OF ROTATION
   pinMode(CLKW_F_R,OUTPUT);
   pinMode(ACLKW_F_R,OUTPUT);
   pinMode(CLKW_F_L,OUTPUT);
   pinMode(ACLKW_F_L,OUTPUT);
   pinMode(CLKW_B_R,OUTPUT);
   pinMode(ACLKW_B_R,OUTPUT);
   pinMode(CLKW_B_L,OUTPUT);
   pinMode(ACLKW_B_L,OUTPUT);
  
  //pin step motors

  


  
  pinMode(STEP_PIN_F, OUTPUT);
  pinMode(DIR_PIN_F, OUTPUT);

  pinMode(STEP_PIN_C, OUTPUT);
  pinMode(DIR_PIN_C, OUTPUT);

  pinMode(STEP_PIN_B, OUTPUT);
  pinMode(DIR_PIN_B, OUTPUT);

  pinMode(STEP_PIN_CG, OUTPUT);
  pinMode(DIR_PIN_CG, OUTPUT);
  
  
   
   * ALL OF THIS PINS ARE ANALOG
   */
  
  pinMode(pwm, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  
   
}


void loop() {

  pwm_function(0.5);
  dummyMovement();
  //communicationSerial();

}

void dummyMovement(){
  
  forward_mode();
  delay(1000);
  
  turn_off_orientation_mode();
  delay(100);
  
  backward_mode();
  delay(1000);
  
  turn_off_orientation_mode();
  delay(100);

  turn_left_mode();
  delay(1000);
  
  turn_off_orientation_mode();
  delay(100);

  turn_right_mode();
  delay(1000);
  
  turn_off_orientation_mode();
  delay(100);
  
}
