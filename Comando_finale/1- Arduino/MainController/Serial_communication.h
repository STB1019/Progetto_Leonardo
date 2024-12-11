//to enable exceptions you have to manually configure the IDE
#include "Movement.h"

String default_mex = "abcd";
int timer_micro = 500;

void serialCommOpener(){
    
    //serial_movement.begin(1000);
    //serial_sonar.begin(2000);
    Serial.begin(9600);
    Serial.println("Serial comunication port opened");

}

void serialCommCloser(){

  Serial.println("Closing all serial communications");
  //serial_movement.end();
  stop_movement();
  //serial_sonar.end();

  Serial.println("All serial ports closed");
  Serial.end();

}
/*
String serialListenerEXC(){

  String serial_mex;
  try{
  if(!Serial.available()){
     serial_mex = Serial.read();
  }
  }
  catch(String error){
    Serial.println("Something's wrong, i can feel it");
    Serial.println(error);
  }
  return serial_mex;
}*/


void serialWriter(String stringa){
  

  
  if(Serial.availableForWrite()){
      Serial.println(stringa);
  }
  else{
    serialWriter(stringa);
  }
  
}

String serialListener(){
  String serial_mex = "no new messages";
  if(!Serial.available()){
    serial_mex = Serial.readStringUntil('\n');    
  }
  return serial_mex;
}

//reverses the string, for an easy access of the first 8 characters, then it takes the first 8 reversed characters to compose a 8-character message

String stringFormatter(String stringa){

  int len = stringa.length(); 
  char string_formatted[8] = {'a', 'a','a','a','a','a','a','a'};
  for(int i = 0; i<8; i++){
    string_formatted[7-i]=stringa[len-i-1];
  } 
  return string_formatted;
}



/*
Function to analyze in which direction moving and for how long 

format of the messages: MMMDDDDK

MMM : characters for movement
DDDD : timer 0 - 9999 for movement
K : key character for message

    ###   DC DIRECTION    ###

FWD  ->  Leonardo moving forward
BCK  ->  Leonardo moving backwards
LFT  ->  Leonardo turning  left
RGH  ->  Leonardo turning right

    ###   STEPPER DIRECTION   ###


S1U  ->  moving front axis up
S1D ->  moving front axis down
S2U  ->  moving middle axis up
S2D  ->  moving middle axis down
S3U  ->  moving back axis up
S3D  ->  moving back axis down
S4U  ->  moving balance axis up
S4D  ->  moving balance axis down

PWM  -> setting pwm to values between 0 and 255
*/


void serialAnalyzer_(String mex){

  Serial.println(mex+" entrato in serialAnalyzer");
  int max = 10;
  //char mex[max];
  //mex_s.toCharArray(mex, max);

  if(mex =="STACCCAH"){

    serialCommCloser();
    
  }
}

bool bool_dir = false;


void serialAnalyzer(String mex){

  Serial.println(mex+" entrato in serialAnalyzer");
  int max = 10;
  //char mex[max];
  //mex_s.toCharArray(mex, max);

  if(mex =="STACCCAH"){

    serialCommCloser();
    
  }

  //retrieving how much time to move. time between 0 and 9999 milliseconds
  //int timer = int(mex[3])*1000 + int(mex[4])*100 + int(mex[5])*10 + int(mex[6]);
  //delay(timer);
  //check if i need to move a stepper motor
  if(mex.charAt(0) == 'P'){
    set_pwm(int(mex[3])*100 + int(mex[4])*10 + int(mex[5]));
  }

  else if(mex.charAt(0) == 'O'){
    stop_movement();
  }
  else if(mex.charAt(0) == 'I'){
    default_movement();
  }

  else if(mex.charAt(0) == 'S'){
    
    bool_dir = false;

    if(mex.charAt(2) == 'U'){
      bool_dir = true;
    }
    
    switch(mex.charAt(1)){
      case 1:

          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
          moveAxis(dir_dc1, step1, bool_dir, timer_micro);
          delay(500);

      break;

      case 2:

          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
            moveAxis(dir_dc2, step2, bool_dir, timer_micro);
            delay(500);  
  
      break;

      case 3:

          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
          moveAxis(dir_dc3, step3, bool_dir, timer_micro);
          delay(500);  

      break;

      case 4:

          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
            moveAxis(dir_dc4, step4, bool_dir, timer_micro);
            delay(500); 

      break;

      default:

        serialWriter("Something's wrong, i can feel it");
        stop_movement();
  
      break;
    }
  }
  else{
    serialWriter(mex+" entrato in gestione dc");
    switch(mex.charAt(0)){
      case 'F':

          forward_mov();
          serialWriter("avanti");

      break;

      case 'B':

          back_mov();
          serialWriter("indietro");

      break;

      case 'L':

          left_mov();
          serialWriter("sinistra");

      break;

      case 'R':

          right_mov();
          serialWriter("destra");

      break;

      default:
      //default block everything
        serialWriter("Something's wrong, i can feel it");
        serialWriter(mex);
        stop_movement();

        
  
      break;
    }
  } 

  
}


/*
serialMovement, but implementing a bitwise logic

byte format: ssddxxxx

ss: couple bit for selection of the movement

00:   dc movement
01:   stepper movement up
10:   stepper movement down
11:   stop

dd: couple bits for direction 

dc movement mode: 

00:   forward
01:   right
10:   left
11:   backward

stepper movement mode: 

00:   move stepper motor 1
01:   move stepper motor 2
10:   move stepper motor 3
11:   move stepper motor 4

*/

bool movement_dc = false;
int movement_selector = 0;
void serialBinaryMove(int movement){

  
  movement = movement && -15;
  if(movement && 192){
    stop_movement();
    serialWriter("Leonardo stopped moving");
  }
  else{
      if(movement && 0){
        movement_dc = true;
      }
      else{
          if(movement && 64){
              bool_dir = true;
          }
          else{
              bool_dir = false;
          }
      }
  }

  movement_selector = (movement && 48);

  switch(movement_selector){
  
    case 0:
      if(movement_dc){
        forward_mov();
        serialWriter("avanti");
        }

      else{
        moveAxis(dir_dc1, step1, bool_dir, timer_micro);
        delay(500);
      }
      break;

    case 16:
      if(movement_dc){
        right_mov();
        serialWriter("avanti");
      }

      else{
        moveAxis(dir_dc2, step2, bool_dir, timer_micro);
        delay(500);
      }
    break;

    case 32:
    if(movement_dc){
      left_mov();
      serialWriter("avanti");
    }

    else{
      moveAxis(dir_dc3, step3, bool_dir, timer_micro);
      delay(500);
    }
    break;

    case 48: 
    if(movement_dc){
      back_mov();
      serialWriter("avanti");
    }

    else{
      moveAxis(dir_dc4, step4, bool_dir, timer_micro);
      delay(500);
    }
    break;
      
    default:  
    serialWriter("Something's wrong, i can feel it");
    stop_movement();

    break;
  }
  movement_dc = false;

}






/*
void serialWriterEXC(String sonar_values){
  try{
  if(Serial.available()){
      Serial.write(String(sonar_values));
  }
  }
  catch(String error){
    Serial.println("Something's wrong, i can feel it");
    Serial.println(error);
  }

  
}
*/


/*
Function to analyze in which direction moving and for how long 

format of the messages: MMM

MMM : characters for movement


    ###   DC DIRECTION    ###

FWD  ->  Leonardo moving forward
BCK  ->  Leonardo moving backwards
LFT  ->  Leonardo turning  left
RGH  ->  Leonardo turning right

    ###   STEPPER DIRECTION   ###


S1U  ->  moving front axis up
S1D ->  moving front axis down
S2U  ->  moving middle axis up
S2D  ->  moving middle axis down
S3U  ->  moving back axis up
S3D  ->  moving back axis down
S4U  ->  moving balance axis up
S4D  ->  moving balance axis down

PWM  -> setting pwm to values between 0 and 255
*/

void serialAnalyzer_FSM(String mex){

  Serial.println(mex+" entrato in serialAnalyzer_FSM");

  if(mex =="1149"){

    serialCommCloser();
    
  }

  if(mex.charAt(0) == 'P'){
    set_pwm(int(mex[3])*100 + int(mex[4])*10 + int(mex[5]));
  }

  else if(mex.charAt(0) == 'S'){
    
    bool bool_dir = false;

    if(mex.charAt(2) == 'U'){
      bool_dir = true;
    }
    
    switch(mex.charAt(1)){
      case 1:
          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
          moveAxis(dir_dc1, step1, bool_dir, timer_micro);
          delay(500); 
          
      break;

      case 2:
          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
          
            moveAxis(dir_dc2, step2, bool_dir, timer_micro);
            delay(500);

      break;

      case 3:
          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
          
          moveAxis(dir_dc3, step3, bool_dir, timer_micro);
          delay(500);

      break;

      case 4:
          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
            moveAxis(dir_dc4, step4, bool_dir, timer_micro);
            delay(500); 

      break;

      default:

        serialWriter("Something's wrong, i can feel it");
  
      break;
    }
  }
  else{
    serialWriter(mex+" entrato in gestione dc");
    switch(mex.charAt(0)){
      case 'F':

          forward_mov();
          serialWriter("avanti");

      break;

      case 'B':

          back_mov();
          serialWriter("indietro");

      break;

      case 'L':

          left_mov();
          serialWriter("sinistra");

      break;

      case 'R':

          right_mov();
          serialWriter("destra");

      break;

      default:

        serialWriter("Something's wrong, i can feel it");
        serialWriter(mex);

        stop_movement();
  
      break;
    }
  } 

  
}









