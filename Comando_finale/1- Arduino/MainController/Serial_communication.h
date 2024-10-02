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
  String serial_mex = "";
  if(!Serial.available()){
    serial_mex = Serial.readString();
  }

  else{
    serial_mex = "Something's wrong, i can feel it";
  }
  
  return serial_mex;
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









