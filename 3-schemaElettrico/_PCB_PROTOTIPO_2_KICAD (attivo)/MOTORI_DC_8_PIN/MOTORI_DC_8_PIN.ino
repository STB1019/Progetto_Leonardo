
#define IN1_FW 16
#define IN2_FW 17
#define IN3_FW 5
#define IN4_FW 18

#define IN1_BW 4
#define IN2_BW 0
#define IN3_BW 2
#define IN4_BW 15

#define PWM_EN 19


void setup() {

  pinMode(IN1_FW, OUTPUT);
  pinMode(IN2_FW, OUTPUT);
  pinMode(IN3_FW, OUTPUT);
  pinMode(IN4_FW, OUTPUT);

  pinMode(IN1_BW, OUTPUT);
  pinMode(IN2_BW, OUTPUT);
  pinMode(IN3_BW, OUTPUT);
  pinMode(IN4_BW, OUTPUT);
  pinMode(PWM_EN, OUTPUT);
}

void loop() {
    avanti();
  delay(2000);
    fermo();
  delay(1000);
    indietro();
  delay(2000);
    fermo();
  delay(1000);
    destra();
  delay(2000);
    fermo();
  delay(1000);
    sinistra();
  delay(2000);
    fermo();
  delay(1000);
}

void fermo(){
//digitalWrite(IN1_FW,0);
//digitalWrite(IN2_FW,0);
//digitalWrite(IN3_FW,0);
//digitalWrite(IN4_FW,0);

//digitalWrite(IN1_BW,0);
//digitalWrite(IN2_BW,0);
//digitalWrite(IN3_BW,0);
//digitalWrite(IN4_BW,0);
//digitalWrite(IN4_BW,0);

analogWrite(PWM_EN,0);

}

void avanti(){
digitalWrite(IN1_FW,1);
digitalWrite(IN2_FW,0);
digitalWrite(IN3_FW,1);
digitalWrite(IN4_FW,0);

digitalWrite(IN1_BW,1);
digitalWrite(IN2_BW,0);
digitalWrite(IN3_BW,1);
digitalWrite(IN4_BW,0);

analogWrite(PWM_EN,200);

}

void indietro(){
digitalWrite(IN1_FW,0);
digitalWrite(IN2_FW,1);
digitalWrite(IN3_FW,0);
digitalWrite(IN4_FW,1);

digitalWrite(IN1_BW,0);
digitalWrite(IN2_BW,1);
digitalWrite(IN3_BW,0);
digitalWrite(IN4_BW,1);

analogWrite(PWM_EN,200);
}

void destra(){
digitalWrite(IN1_FW,1);
digitalWrite(IN2_FW,0);
digitalWrite(IN3_FW,0);
digitalWrite(IN4_FW,1);

digitalWrite(IN1_BW,1);
digitalWrite(IN2_BW,0);
digitalWrite(IN3_BW,0);
digitalWrite(IN4_BW,1);

analogWrite(PWM_EN,200);
}

void sinistra(){
digitalWrite(IN1_FW,0);
digitalWrite(IN2_FW,1);
digitalWrite(IN3_FW,1);
digitalWrite(IN4_FW,0);

digitalWrite(IN1_BW,0);
digitalWrite(IN2_BW,1);
digitalWrite(IN3_BW,1);
digitalWrite(IN4_BW,0);

analogWrite(PWM_EN,200);
}