
 
void serial_comm_opener(){
    
    serial_movement.begin(1000);
    serial_sonar.begin(2000);
    Serial.begin(9800);
    Serial.println("Serial comunication port opened");

}

void serial_comm_closer(){

  Serial.println("Closing all serial communications");
  serial_movement.end();
  serial_sonar.end();

  Serial.println("All serial ports closed");
  Serial.end();

}

String movement_listener(){
  
}

void sonar_writer(String sonar_values){
  try{
  if(serial_sonar.available()){
      serial_sonar.write(sonar_values);
  }
  }
  catch(...){
    Serial.println("Something's wrong, i can feel it");
  }

  
}










