#include "PIN_OUT.h"
#include "Set_Orientation.h"

#define MIN 0 // min value of speed
#define MAX 10 // max value of speed
#define WAIT 250

/*
 * writes the value in all the four pwm pins
 */
void write_pwm(int pwm_value){

  analogWrite(PWM_F_R,pwm_value);
  analogWrite(PWM_F_L,pwm_value);
  analogWrite(PWM_B_L,pwm_value);
  analogWrite(PWM_B_R,pwm_value);
  
}

float interpolation(float x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*
 * activates the orientation mode forward and calls the function to write the pwm values
 * LEONARDO GOES FORWARD
 */
void start_leonardo(int v){
  
  int pwm_value = 0;
  pwm_value = interpolation(v,MIN,MAX,0,255); // the MAP function returns the value in proportion of 
  //the range given in the beginning projected in the secon range
  write_pwm(pwm_value);
  
}

void stop_leonardo(){
    int pwm_value = 0;
    write_pwm(pwm_value);
    delay(WAIT);
}
