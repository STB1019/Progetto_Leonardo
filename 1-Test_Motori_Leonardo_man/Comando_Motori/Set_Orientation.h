#include "PIN_OUT.h"
#define ALTO LOW
#define BASSO HIGH

/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the clokwise for the left motors and the anticlkwise for the right 
 * engines they have opposite rotation in order to perform a forward move
 */
void forward_mode(){

  digitalWrite(IN2_CLKW_FB_R,ALTO);
  digitalWrite(IN2_CLKW_FB_L,BASSO);
  
}


/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the anticlokwise for the left motors and the clkwise for the right 
 * engines, they have opposite rotation in order to perform a backward move
 */
void backward_mode(){

  digitalWrite(IN2_CLKW_FB_R,BASSO);
  digitalWrite(IN2_CLKW_FB_L,ALTO);
  
}


/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the clokwise for the left motors and the clkwise for the right 
 * engines, so they have the same rotation in order to performe a right turn
 */
void turn_right_mode(){

  digitalWrite(IN2_CLKW_FB_R,BASSO);
  digitalWrite(IN2_CLKW_FB_L,BASSO);
  
}


/*
 * this function sets the rotation mode direction of the pins of the h bridge
 * turns on the anticlokwise for the left motors and the anticlokwise for the right 
 * engines, so they have the same rotation in order to performe a left turn
 */
void turn_left_mode(){

  digitalWrite(IN2_CLKW_FB_R,ALTO);
  digitalWrite(IN2_CLKW_FB_L,ALTO);
  
}
