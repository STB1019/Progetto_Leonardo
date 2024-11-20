#include "Serial_communication.h"
//#include "PIN_OUT_FINAL.h"
//#include "Stepper2.h"
//#include "Sonar_Completo_Leonardo.h"
//#include "SoftwareSerial.h"
//#include "Movement.h"


/*
Stepper Stepper1(stepsPerRevolution, dir_step1,step1);
Stepper Stepper2(stepsPerRevolution, dir_step2,step2);
Stepper Stepper3(stepsPerRevolution, dir_step3,step3);
Stepper Stepper4(stepsPerRevolution, dir_step4,step4);  */


String stringa = "aaaaa";
String stringaold = "";
//int lenght = 10;
//char mess[lenght] = "";

void setup(){

  
  pinMode(dir_dc1, OUTPUT);
  pinMode(dir_dc2, OUTPUT);
  pinMode(dir_dc3, OUTPUT);
  pinMode(dir_dc4, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);

  pinMode(dir_step1, OUTPUT);
  pinMode(dir_step2, OUTPUT);
  pinMode(dir_step3, OUTPUT);
  pinMode(dir_step4, OUTPUT);
  
  pinMode(step1, OUTPUT);
  pinMode(step2, OUTPUT);
  pinMode(step3, OUTPUT);
  pinMode(step4, OUTPUT);
  
  //security measure
  analogWrite(PWM_PIN, 0);

  //serialCommCloser();
  delay(1000);
  serialCommOpener();
    
}
void loop(){

  //TODO:  fixing the loop, leonardo stops for a moment between cycles

  stringa = serialListener();
    
    //stringa = Serial.readStringUntil('\n');

      if(String(stringa) != "no new messages"){
        stringaold = stringa;
        //stringaold.toCharArray(mess, lenght);
        
        
      }
  
  serialAnalyzer(stringFormatter(stringaold));



//delay(1000);
  
}

void serialWriteTest(){
  
  serialCommOpener();
  for(int i=0; i<10; i++){
    serialWriter("ciao");
    delay(100);
  }
  serialCommCloser();
  
}

void serialReadTest(String stringa){
  Serial.println(stringa+" entrato in serialReadTest");
  if(stringa =="12345678"){

    serialCommCloser();
    
  }
  serialAnalyzer(stringa);
    delay(1000);
  
}



void dummyMovement2(){
  int delay_time = 300;
  forward_mov();

  
  //default_movement();
  set_pwm(200);
  delay(delay_time);
  //stop_movement();
  set_pwm(0);
  delay(delay_time);

  delay(1000);
  back_mov();
  
  //default_movement();
  set_pwm(200);
  delay(delay_time);
  //stop_movement();
  set_pwm(0);
  delay(delay_time);

  delay(1000);

  left_mov();
  
  //default_movement();
  delay(delay_time);
  stop_movement();
  delay(delay_time);

  right_mov();

  //default_movement();
  delay(delay_time);
  stop_movement();
  delay(delay_time);

}


//TO BE TESTED THE MOTOR MAPPING
/*
void dummyMovement(){
  digitalWrite(dir_dc1, LOW);
  digitalWrite(dir_dc2, LOW);
  digitalWrite(dir_dc3, HIGH);
  digitalWrite(dir_dc4, HIGH);
  analogWrite(6, 200);
  //default_movement();

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
  
}

*/



void dummyStepper(){
  
  moveAxis(dir_dc1, step1, true, timer_micro);
  delay(500);
  
  moveAxis(dir_dc1, step1, false, timer_micro);
  delay(500);
  
  moveAxis(dir_dc2, step2, true, timer_micro);
  delay(500);
  
  moveAxis(dir_dc2, step2, false, timer_micro);
  delay(500);
  
  moveAxis(dir_dc3, step3, true, timer_micro);
  delay(500);
  
  moveAxis(dir_dc3, step3, false, timer_micro);
  delay(500);
  
  moveAxis(dir_dc4, step4, true, timer_micro);
  delay(500); 
  
  moveAxis(dir_dc4, step4, false, timer_micro);
  delay(500);
}
