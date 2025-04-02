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
String stringaoldold = "";
String mex = "H";
char state='H';
uint8_t speed=255;
String mex_read = "aaa";

uint8_t mex_to_proc = 0;    //pointer of the message to be processed
uint8_t mex_last = 0;       //pointer of the last message received
const int bit_dim_buffer = 4; //2^bit_dim_buffer sets dimension of the buffer, and pointer%2^bit_dim_buffer gives the position inside the buffer of the mex selected
const int dim_array = 2^bit_dim_buffer;
String array_mex[dim_array];
bool new_mex = false; 
//int lenght = 10;
//char mess[lenght] = "";
unsigned long timeout=5000;
unsigned long lastmillis=0;
void setup() {


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
  serialWriter("Leonardo ready");
}

/*
    ###   DC DIRECTION    ###

F   ->  Leonardo moving forward
B   ->  Leonardo moving backwards
L   ->  Leonardo turning  left
R   ->  Leonardo turning right

    ###   STEPPER DIRECTION   ###

S1U  ->  moving front axis up
S1D  ->  moving front axis down
S2U  ->  moving middle axis up
S2D  ->  moving middle axis down
S3U  ->  moving back axis up
S3D  ->  moving back axis down
S4U  ->  moving balance axis up
S4D  ->  moving balance axis down

PKKK  -> setting pwm to values between 0 and 255, managed in KKK

O     ->  pwm default value 0 
I     ->  pwm default value 255
*/


void loop() {

  //if (millis() - lastmillis > timeout) state = 'H';

  if (Serial.available()) {
    mex = Serial.readString();
    Serial.print("recived:");
    Serial.println(mex);
    //lastmillis = millis();
    
    state = mex.charAt(0);
    //serialAnalyzer(mex);
    //speed= seconda parte della stringa toInt

    switch (state) {
    case 'F':
      forward_mov();
      
      //analogWrite(PWM_PIN, speed);
      break;
    case 'R':
      right_mov();
      //analogWrite(PWM_PIN, speed);
      break;
    case 'L':
      left_mov();
      //analogWrite(PWM_PIN, speed);
      break;
    case 'B':
      back_mov();
      //analogWrite(PWM_PIN, speed);
      break;
    case 'S':
      analogWrite(PWM_PIN, 0);
      break;
    case 'X':
      analogWrite(PWM_PIN, 255);
      break;
  }
  
  //*/

  if(mex =="STACCCAH"){

    serialCommCloser();
    
  }
  
  if(mex.charAt(0) == 'P'){
    set_pwm(int(mex[1])*100 + int(mex[2])*10 + int(mex[3]));
  }

  else if(mex.charAt(0) == 'O'){
    serialWriter("not moving");
    stop_movement();
  }
  else if(mex.charAt(0) == 'I'){
    default_movement();
    serialWriter("moving");
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

          
          serialWriter("avanti");
         forward_mov();

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
}
  /*

  
      if(mex =="STACCCAH"){

      serialCommCloser();
      
    }
  
    if(mex.charAt(0) == 'P'){
      set_pwm(int(mex[1])*100 + int(mex[2])*10 + int(mex[3]));
    }

    else if(mex.charAt(0) == 'O'){
      serialWriter("not moving");
      stop_movement();
    }
    else if(mex.charAt(0) == 'I'){
      default_movement();
      serialWriter("moving");
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

            
            serialWriter("avanti");
          forward_mov();

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

  }*/




/*
void toBeTested(){

  if (Serial.available()) {
    mex_read = Serial.readString();
    Serial.print("recived:");
    Serial.println(mex_read);
    new_mex = true;
    String aux_mex = "aaa";
    if(mex_read.length()<2^bit_dim_buffer){
      for(int i = 0; i<mex_read.length(); i++){
        array_mex[(i+mex_last)%2^bit_dim_buffer] = mex_read.charAt(i); 
      }
      mex_last = mex_last + mex_read.length();
    }
    else {
      serialWriter("error: buffer overflow");
      new_mex=false; 
    }
    
    while(mex_last != mex_to_proc){
      if(!(mex_last%2^bit_dim_buffer == mex_to_proc%2^bit_dim_buffer)){
        if(mex.charAt(0) == 'P'){
          set_pwm(int(mex[1])*100 + int(mex[2])*10 + int(mex[3]));
        }

        else if(mex.charAt(0) == 'O'){
          serialWriter("not moving");
          stop_movement();
        }
        else if(mex.charAt(0) == 'I'){
          default_movement();
          serialWriter("moving");
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

                
                serialWriter("avanti");
              forward_mov();

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

      }//TODO: FINIRE
      mex_to_proc++;
    }
  }

  

  
  
  //TODO:  fixing the loop, leonardo stops for a moment between cycles

  /* stringa = Serial.readStringUntil('\n');

  //
 
    while(!stringa.equals("STACCAH")){
      

      if(stringa != stringaold){
          stringaold = stringa;

        //stringaold.toCharArray(mess, lenght);
        
        serialAnalyzer(stringaold);
      }
      
        serialAnalyzer(stringaold);
      
      
      
      stringa = Serial.readStringUntil('\n');
      

    }
    serialCommCloser();

    /*
    //stringa = Serial.readStringUntil('\n');

      if(stringa != stringaold){
        stringaold = stringa;
        //stringaold.toCharArray(mess, lenght);
        
        
      }
  
  serialAnalyzer(stringaold);

}
*/
void serialWriteTest() {

  serialCommOpener();
  for (int i = 0; i < 10; i++) {
    serialWriter("ciao");
    delay(100);
  }
  serialCommCloser();
}

void serialReadTest(String stringa) {
  Serial.println(stringa + " entrato in serialReadTest");
  if (stringa == "12345678") {

    serialCommCloser();
  }
  serialAnalyzer(stringa);
  delay(1000);
}



void dummymovement2() {
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



void dummyStepper() {

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
