// Inclusione della libreria stopper
#include <Stepper.h>
#include "PIN_OUT_FINAL.h"

// Numero di step (passi) per effettuare una rotazione completa
const int stepPerRotazione = 200;

// Creazione dell’istanza dello Stepper

Stepper mioStepper(stepPerRotazione, A0,13);

void setup_roba()
{
  //pinMode(A0 , OUTPUT);
    // impostazione della rotazione a 60 rpm:
    mioStepper.setSpeed(60);
    // inizializzazione della porta seriale:
    Serial.begin(9600);
}

void moveAxis(Stepper stepper_motor, int how_much_to_rotate) 
{
    // una rotazione in una direzione
    Serial.println("Rotazione in corso");
    stepper_motor.step(how_much_to_rotate);
    delay(1000);

    
}