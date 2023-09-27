#include "PIN_OUT.h"
#include "Manual_Mode.h"
#include "Serial_Controller.h"
//#include "Set_Orientation.h"
#include "Stepper_Define.h"
#include "Stepper_Function.h"
#include <SoftwareSerial.h>

#define DELAY 100

#define MIN 0 // min value of speed
#define MAX 10 // max value of speed

#define forward 'F'
#define backward 'B'
#define left 'L'
#define right 'R'

String msg;
int i;
int velo=1;

void setup() {

   Serial.begin(9600); // BEGINNING COMUNICATION RATE: 9600 bit/s
  
  /*
   * ALL OF THIS PINS ARE DIGITAL
   */
   
  // ALL THE PINS TO MOVE THE ENGINS ARE IN OUTPUT MODE
  //THIS IS A SET TO INDICATE AND ENABLE THE ENGINES DIRECTION OF ROTATION
   pinMode(IN2_CLKW_FB_R,OUTPUT);
   pinMode(IN2_CLKW_FB_L,OUTPUT);

   /*
   * ALL OF THIS PINS ARE ANALOG
   */
  // SET OF PINS FOR PWM TO SET SPEED FROM
   pinMode(PWM_F_R,OUTPUT);
   pinMode(PWM_F_L,OUTPUT);
   pinMode(PWM_B_R,OUTPUT);
   pinMode(PWM_B_L,OUTPUT);
  
}


/*
 * this function reads the message in the serial port and stores the line of the message in the variable
 * msg[]. 
 */



void loop() {

  
  if (Serial.available()) {
    char nr = Serial.read();
        controller(nr, velo);
        }  
  
}
