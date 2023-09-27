/*
 * PIN ATMEGA 1284P
 */

/*
 * Tutti i pin sono definiti con il numero dell'atmega non con il numero ordinaro
 * di pin quindi serve usare la libreria con il numero come la GPIO di rapberry.
 * accanto ho messo il numero ordinato di pin
 */

#define IN2_CLKW_FB_R  2 // CLOKWISE PIN FRONT and BACK RIGHT MOTORS (FOR ANTICLOCKWISE DEACTIVATE IT)
#define IN2_CLKW_FB_L 3 // CLOKWISE PIN FRONT and BACK LEFT MOTORS (FOR ANTICLOCKWISE DEACTIVATE IT)

// ALL THE PINS STRUCTURE FOR THE MOVEMENT MODE FOR DC MOTORS

#define PWM_F_R 6  // PWM FRONT RIGHT MOTOR
#define PWM_F_L 6  // PWM FRONT LEFT MOTOR
#define PWM_B_R 6  // PWM BACK RIGHT MOTOR
#define PWM_B_L 6  // PWM BACK LEFT MOTOR
