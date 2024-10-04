//to enable exceptions you have to manually configure the IDE

void serial_comm_opener(){
    
    //serial_movement.begin(1000);
    //serial_sonar.begin(2000);
    Serial.begin(9600);
    Serial.println("Serial comunication port opened");

}

void serial_comm_closer(){

  Serial.println("Closing all serial communications");
  //serial_movement.end();
  //serial_sonar.end();

  Serial.println("All serial ports closed");
  Serial.end();

}
/*
String Serial_listener_EXC(){

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


void Serial_writer(String stringa){
  
  if(Serial.available()){
      Serial.println(String(stringa));
  }
  else{
    delay(1);
    Serial_writer(stringa);
  }
  
}

String Serial_listener(){
  if(!Serial.available()){
    String serial_mex = Serial.readString();
    return serial_mex;
  }
/*
  else{
    //String serial_mex = "Something's wrong, i can feel it";
  }
  */
  
}

/*
Function to analyze in which direction moving for how long 

format of the messages: MMMMDDDD

    ###   DC DIRECTION    ###

FRWD  ->  Leonardo moving forward
BACK  ->  Leonardo moving backwards
LEFT  ->  Leonardo turning  left
RGTH  ->  Leonardo turning right

    ###   STEPPER DIRECTION   ###


S1UP  ->  moving front axis up
S1DN ->  moving front axis down
S2UP  ->  moving middle axis up
S2DN  ->  moving middle axis down
S3UP  ->  moving back axis up
S3DN  ->  moving back axis down
S4UP  ->  moving balance axis up
S4DN  ->  moving balance axis down
*/

void Serial_analyzer(String mex){

  
  //check if i need to move a stepper motor
  if(mex[0] == "S"){
    
    bool bool_dir = false;

    if(mex[2] == "U"){
      bool_dir = true;
    }
    
    switch(mex[1]){
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
    switch(mex[0]){
      case 'F':
          //forward();
      break;

      case 'B':
          //back();
      break;

      case 'L':
          //left();
      break;

      case 'R':
          //right();
      break;

      default:
        Serial.println("Something's wrong, i can feel it");
  
      break;
    }
  } 
}





/*
void Serial_writer_EXC(String sonar_values){
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









