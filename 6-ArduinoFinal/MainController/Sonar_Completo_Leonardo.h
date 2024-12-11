/*LIBRERIE*/

//Includi nel progetto le librerie NewPing e Servo
#include "NewPing.h"
#include <Servo.h>

/*COLLEGAMENTI PIN*/

/*Collegare il pin 8 di Arduino al Trigger,  
  il pin 9 all' Echo del sensore HC-SR04
  e il pin 11 al pin di controllo del servo motore.*/
#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define SERVO_PIN 11

/*COSTANTI PROGETTO*/

#define MAX_DISTANCE 400                  //Distanza massima per cui vogliamo eseguire il ping (in centimetri).
#define SINISTRA 0                        //Assegnazione di un valore arbitrario alla direzione di sinistra
#define DESTRA 1                          //Assegnazione di un valore arbitrario alla direzione di destra
#define FINE_CORSA_DX_BASE 60             //Estremo di destra del sonar in condizioni normali (guarda davanti)
#define FINE_CORSA_DX_SVOLTA 0            //Estremo di destra del sonar in condizioni di svolta a destra
#define FINE_CORSA_SX_BASE 120            //Estremo di sinistra del sonar in condizioni normali (guarda davanti)
#define FINE_CORSA_SX_SVOLTA 180          //Estremo di sinistra del sonar in condizioni di svolta a sinistra
#define RANGE_SONAR 60                    //Ampiezza di lavoro del sonar (in gradi)
#define POSIZIONE_CENTRALE 90             //Lettreralmente la posizione centrale del servo motore (in gardi)
#define DELAY_SONAR 100                   //Tempo di attesa tra una scansione e l'altra (in millisecondi)
#define ITERAZIONI 5                      //Numero scansioni per passo del servo
#define PASSO 5                           //Step del servo motore coperti ad ogni movimento

/*VARIABILI GLOBALI*/

Servo MyServo;                                              //Nome del servo motore
NewPing scansione(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);     //Settaggio funzione di controllo del sensore HC-SR04
int posizione, direzione, fine_corsa_dx, fine_corsa_sx;     //Variabili per il controllo del servo motore
long tempo;                                                 //Variabile per il temporizzatore
int distanza;                                               //Variabile che indica il valore letto dal HC-SR04 (in centimetri)
int distanze[13];                                           //Array con tutte le distanze rilevate nel range attuale
int zona;                                                   //Valore che indica la zona di osservazione 0 = dx; 1 = ce; 2 = sx

/*PROTOTIPI*/
//Dichiarazione iniziale delle funzioni che si andranno ad utilizzare

void Diritto();               //Setto estremi di base e posizione centrale
void Svolta_Destra();         //Setto estremi di svolta a destra e posizione al limite destro
void Svolta_Sinistra();       //Setto estremi di svolta a sinistra e posizione al limite sinistro
void Sonar();                 //Scansione con movimento del servo
void pulisciArray();          //Reset dell'array in attesa dei nuovi dati

void setup() {
  //Associazione del servo motore al pin dedicato di Arduino
  MyServo.attach(SERVO_PIN);
  
  //Inizializzazione del monitor seriale
  Serial.begin(9600);
  
  //Inizializzo dati di partenza del servo motore
  Diritto(); //Setto i valori base degli estremi di lavoro
  MyServo.write(posizione);//Posiziono il servo in una posizione centrale
  direzione = SINISTRA; //Setto la direzione iniziale del movimento del sonar

  //Inizializzo variabile temporale
  tempo = millis();
}

void loop() {
    //Lancio una scansione ogni x millisecondi preimpostati
    if(millis() - tempo >= DELAY_SONAR) {
    Sonar();
    tempo = millis();
  }
}

void Diritto(){
  fine_corsa_dx = FINE_CORSA_DX_BASE;
  fine_corsa_sx = FINE_CORSA_SX_BASE;
  posizione = POSIZIONE_CENTRALE;
  zona = 1;
  pulisciArray();
}

void Svolta_Destra(){
  fine_corsa_dx = FINE_CORSA_DX_SVOLTA;
  fine_corsa_sx = fine_corsa_dx + RANGE_SONAR;
  posizione = fine_corsa_dx;
  zona = 0;
  pulisciArray();
}

void Svolta_Sinistra(){
  fine_corsa_sx = FINE_CORSA_SX_SVOLTA;
  fine_corsa_dx = fine_corsa_sx - RANGE_SONAR;
  posizione = fine_corsa_sx;
  zona = 2;
  pulisciArray();
}

void Sonar(){
  //Scrittura della posizione sul servo
  MyServo.write(posizione);

  //Echo rilevamento della distanza n volte e conversione in centimetri
  distanza = round(scansione.convert_cm(scansione.ping_median(ITERAZIONI)));

  //Scrittura dati sul monitor seriale
  Serial.write(posizione);                            //Invio della posizione
  Serial.write('\n');                                 //Separatore dati modificabile
  Serial.write(distanza);                             //Invio della distanza
  
  //salvataggio dati su un array
  int i = (posizione - RANGE_SONAR*zona) / PASSO;     //Calcolo indice di salvataggio
  distanze[i] = distanza;                             //Salvataggio su array

  //Decido se scorrere a destra o a sinistra in base alla posizione attuale del servo
  if(posizione == fine_corsa_dx) direzione = SINISTRA;
  else if(posizione == fine_corsa_sx) direzione = DESTRA;

  //Effettuo un passo nel verso deciso
  if(direzione == SINISTRA) posizione += PASSO;
  else if(direzione == DESTRA) posizione -= PASSO;
  else Serial.println("Errore");
}

void pulisciArray(){
  for(int i = 0; i < sizeof(distanze); i++){
    distanze[i] = 0;
  }
}
