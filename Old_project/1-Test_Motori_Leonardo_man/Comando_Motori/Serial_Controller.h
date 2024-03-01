/*

message format: 

0 stop
1 forward movement
2 back movement
3 left turn
4 right turn

5/6 up/down back axis
7/8 up/down middle axis
9/a up/down front axis
b/c forward/backward middle axis

d autonomous drive mode
e manual drive mode



*/
 
void controller(int nr, int vel){
    
        switch(nr){
          case 0:{
            stop_leonardo();
          }
          break;
            case 1:{
           stop_leonardo();
      forward_mode();
      start_leonardo(vel);
      digitalWrite(13, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      }break;
            
            case '2':{
           stop_leonardo();
      backward_mode();
      start_leonardo(vel);
            }break;

            case '3':{
           stop_leonardo();
      turn_left_mode();
      start_leonardo(vel);
            }break;

            case '4':{
           stop_leonardo();
      turn_right_mode();
      start_leonardo(vel);
            }break;

            /*case '5':{
              moveMotor(bool rotDir, const int dirPin, const int stepPin, int delayMicr, int stepPRevMult, int currentPos);
            }break;

            case '6':{
           moveMotor(bool rotDir, const int dirPin, const int stepPin, int delayMicr, int stepPRevMult, int currentPos);
            }break;

            case '7':{
           moveMotor(bool rotDir, const int dirPin, const int stepPin, int delayMicr, int stepPRevMult, int currentPos);
            }break;

            case '8':{
           moveMotor(bool rotDir, const int dirPin, const int stepPin, int delayMicr, int stepPRevMult, int currentPos);
            }break;

            case '9':{
           moveMotor(bool rotDir, const int dirPin, const int stepPin, int delayMicr, int stepPRevMult, int currentPos);
            }break;

            case 'a':{
           moveMotor(bool rotDir, const int dirPin, const int stepPin, int delayMicr, int stepPRevMult, int currentPos);
            }break;

            case 'b':{
           moveMotor(bool rotDir, const int dirPin, const int stepPin, int delayMicr, int stepPRevMult, int currentPos);
            }break;

            case 'c':{
           moveMotor(bool rotDir, const int dirPin, const int stepPin, int delayMicr, int stepPRevMult, int currentPos);
            }break;
            */
            default:
            Serial.println("ERROR: value unexpected");
            
            break;
        }
        
 }
