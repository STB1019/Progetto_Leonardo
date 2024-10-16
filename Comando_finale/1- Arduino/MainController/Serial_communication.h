//to enable exceptions you have to manually configure the IDE

void serialCommOpener(){
    
    //serial_movement.begin(1000);
    //serial_sonar.begin(2000);
    Serial.begin(9600);
    Serial.println("Serial comunication port opened");

}

void serialCommCloser(){

  Serial.println("Closing all serial communications");
  //serial_movement.end();
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

  int len = stringa.length()-1; //cropping the \n character
  String string_formatted = "";
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
*/

void serialAnalyzer(String mex){

  Serial.println(mex+" entrato in serialAnalyzer");
  int max = 10;
  //char mex[max];
  //mex_s.toCharArray(mex, max);

  if(mex =="12345678"){

    serialCommCloser();
    
  }

  //retrieving how much time to move. time between 0 and 9999 milliseconds
  //int timer = int(mex[3])*1000 + int(mex[4])*100 + int(mex[5])*10 + int(mex[6]);
  //delay(timer);
  //check if i need to move a stepper motor
  if(mex.charAt(0) == 'S'){
    
    bool bool_dir = false;

    if(mex.charAt(2) == 'U'){
      bool_dir = true;
    }
    
    switch(mex.charAt(1)){
      case 1:
          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
          //moveAxis(,,bool_dir,);
          
      break;

      case 2:
          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
          //moveAxis(,,bool_dir,);
      break;

      case 3:
          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
          //moveAxis(,,bool_dir,);
      break;

      case 4:
          //moveAxis gets as input parameters (int dir_pin_axis, int step_pin_axis, bool direction, int timer_microseconds)
          //moveAxis(,,bool_dir,);
      break;

      default:
        Serial.println("Something's wrong, i can feel it");
  
      break;
    }
  }
  else{
    Serial.println(mex+" entrato in gestione dc");
    switch(mex.charAt(0)){
      case 'F':
          //forward();

          serialWriter("avanti");
      break;

      case 'B':
          //back();
          serialWriter("indietro");
      break;

      case 'L':
          //left();
          serialWriter("sinistra");
      break;

      case 'R':
          //right();
          serialWriter("destra");
      break;

      default:
        Serial.println("Something's wrong, i can feel it");
        Serial.println(mex);

        //default block everything
  
      break;
    }
  } 

  
}



void serialByte(int bytemess){
  if(bytemess){
    if(bytemess & 128){

    }
  }
  else{
    Serial.println("Fermati");
  }

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









