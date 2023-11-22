/*

message format: 

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

//idk se clock o counter muovono verticalmente su o giù, basta testare   -M

const bool clock_rot = true;
const bool counter_rot = false;

int microDelay = 1000;

//variabili posizione motori stepper, servono x funzione stepper

#define current_pos_f 1;
#define current_pos_c 1;
#define current_pos_b 1;
#define current_pos_cg  1;

 
void communicationSerial(){
    if (Serial.available()) {
        char nr = Serial.read();
        switch(nr){
            case '1':{
                forward_mode();
                //digitalWrite(13,HIGH);
                delay(100);
                turn_off_bridges();
            }break;
            
            case '2':{
                backward_mode();
                //digitalWrite(13,LOW);
                delay(100);
                turn_off_bridges();
            }break;

            case '3':{
                //turn_left_mode();
            }break;

            case '4':{
                //turn_right_mode();
            }break;

            /*case '5':{
                current_pos_f = moveMotor(clock_rot, DIR_PIN_F, STEP_PIN_F, microDelay, stepsPerRevolution, current_pos_f);
            }break;

            case '6':{
                current_pos_f = moveMotor(counter_rot, DIR_PIN_F, STEP_PIN_F, microDelay, stepsPerRevolution, current_pos_f);
            }break;

            case '7':{
                current_pos_c = moveMotor(clock_rot, DIR_PIN_C, STEP_PIN_C, microDelay, stepsPerRevolution, current_pos_c);
            }break;

            case '8':{
                current_pos_c = moveMotor(counter_rot, DIR_PIN_C, STEP_PIN_C, microDelay, stepsPerRevolution, current_pos_c);
            }break;

            case '9':{
                current_pos_b = moveMotor(clock_rot, DIR_PIN_B, STEP_PIN_B, microDelay, stepsPerRevolution, current_pos_b);
            }break;

            case 'a':{
                current_pos_b = moveMotor(counter_rot, DIR_PIN_B, STEP_PIN_B, microDelay, stepsPerRevolution, current_pos_b);
            }break;

            case 'b':{
                current_pos_cg = moveMotor(clock_rot, DIR_PIN_CG, STEP_PIN_CG, microDelay, stepsPerRevolution, current_pos_cg);
            }break;

            case 'c':{
                current_pos_cg = moveMotor(counter_rot, DIR_PIN_CG, STEP_PIN_CG, microDelay, stepsPerRevolution, current_pos_cg);
            }break;*/
        
            default:
            Serial.println("ERROR: value unexpected");
            turn_off_orientation_mode();
            
            break;
        };
    }
}
