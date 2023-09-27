#define IN1 5
#define IN2 4
#define ENA 3
#define STBY 2
#define ALTO LOW
#define BASSO HIGH

int i=150;


void setup() {

  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (STBY, OUTPUT);
  digitalWrite(STBY, ALTO);
  digitalWrite(IN2, ALTO);  //CONFIGURAZIONE ORARIA
  digitalWrite(IN1, BASSO); 
  

}

void loop() {

//control speed
  analogWrite(ENA, i);
  //digitalWrite(IN1, ALTO);
  //digitalWrite(IN2, BASSO);
  if(i>100){
    
    i = 100;
    //control direction 
  digitalWrite(IN2, ALTO); //CONFIGURAZIONE ORARIA
  digitalWrite(IN1, BASSO);  
  }
  else{
    i = 150;
    digitalWrite(IN2, BASSO); //CONFIGURAZIONE ANTIORARIA
    digitalWrite(IN1, ALTO);
  }
  delay(1000);
  
}
