
#define PWM 6
#define driver1_DC1 2
#define driver1_DC2 3
#define driver2_DC1 4
#define driver2_DC2 5

int BBB=1;
int AAA=0;

void setup() {

  pinMode(driver1_DC1,OUTPUT);
  pinMode(driver1_DC2,OUTPUT);
  pinMode(driver2_DC1,OUTPUT);
  pinMode(driver2_DC2,OUTPUT);
  pinMode(PWM,OUTPUT);
  
}

void loop() {
  BBB=0;
  AAA=1;
  analogWrite(PWM,200);
  digitalWrite(driver1_DC1,BBB);
  digitalWrite(driver1_DC2,BBB);
  
  digitalWrite(driver2_DC1,AAA);
  digitalWrite(driver2_DC2,AAA);
  delay(1000);
  
  analogWrite(PWM,0);
  digitalWrite(driver1_DC1,BBB);
  digitalWrite(driver1_DC2,BBB);
  digitalWrite(driver2_DC1,AAA);
  digitalWrite(driver2_DC2,AAA);
  delay(1000);
  
  BBB=1;
  AAA=0;
  analogWrite(PWM,200);
  digitalWrite(driver1_DC1,BBB);
  digitalWrite(driver1_DC2,BBB);
  digitalWrite(driver2_DC1,AAA);
  digitalWrite(driver2_DC2,AAA);
  delay(1000);
  
  analogWrite(PWM,0);
  digitalWrite(driver1_DC1,BBB);
  digitalWrite(driver1_DC2,BBB);
  digitalWrite(driver2_DC1,AAA);
  digitalWrite(driver2_DC2,AAA);
  delay(1000);  
  

  
}
