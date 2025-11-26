#include <Servo.h>
#include <math.h>

#define trigPin 8
#define echoPin 9

long duration;
int distance;

Servo myservo;

const int minAngle = 15;
const int maxAngle = 165;
const int timeoutUs = 15000; // timeout for roughly 250 cm

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, timeoutUs);

  // If no echo is received, set distance to 250 cm
  if (duration == 0) {
    return 250;
  } else {
    return duration * 0.034 / 2;
  }
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(11);
  Serial.begin(115200);
}

void loop() {
  // Sweep from minAngle to maxAngle
  for (int i = minAngle; i <= maxAngle; i++) {
    myservo.write(i);
    delay(15);  // allow the servo to reach the position
    int d = calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(d);
    
    float x = 0, y = 0;
    if (d < 250) { // Calculate only if distance is valid
      float angleRad = i * M_PI / 180.0;
      x = d * cos(angleRad);
      y = d * sin(angleRad);
    }
    Serial.print(",");
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.println();
  }
  
  // Sweep back from maxAngle to minAngle
  for (int i = maxAngle; i >= minAngle; i--) {
    myservo.write(i);
    delay(15);
    int d = calculateDistance();
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(d);
    
    float x = 0, y = 0;
    if (d < 250) { // Calculate only if distance is valid
      float angleRad = i * M_PI / 180.0;
      x = d * cos(angleRad);
      y = d * sin(angleRad);
    }
    Serial.print(",");
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.println();
  }
}
