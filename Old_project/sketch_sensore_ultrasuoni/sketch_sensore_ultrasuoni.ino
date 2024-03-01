//Definizione dei pin
static int trig_SR = ; //Side Right
static int echo_SR = ;

static int trig_SL = ; //Side Left
static int echo_SL = ;

static int trig_FR = ; //Front Right
static int echo_FR = ;

static int trig_FL = ; //Front Left
static int echo_FL = ;

//variabili utilizzate per calcolare la distanza
float durata; //tempo che impieghera' il suono a percorrere una certa distanza
float distanza;  //la distanza che ha percorso il suono

void setup() {
  //abilito la comunicaizone seriale per rendermi conto di cio' che accade
  Serial.begin(9600);

  //settiamo il funzionamento dei pin
  pinMode(trig_SR, OUTPUT);
  pinMode(echo_SR, INPUT);
  pinMode(trig_SL, OUTPUT);
  pinMode(echo_SL, INPUT);
  pinMode(trig_FR, OUTPUT);
  pinMode(echo_FR, INPUT);
  pinMode(trig_FL, OUTPUT);
  pinMode(echo_FL, INPUT);

  //metto a LOW l'ingresso del PIN echo e del PIN trigger
  digitalWrite(echo_SR, LOW);
  digitalWrite(trig_SR, LOW);
  digitalWrite(echo_SL, LOW);
  digitalWrite(trig_SL, LOW);
  digitalWrite(echo_FR, LOW);
  digitalWrite(trig_FR, LOW);
  digitalWrite(echo_FL, LOW);
  digitalWrite(trig_FL, LOW);
  
}

void loop() {

  float dist_SR = distanceCalculator(trig_SR, echo_SR);
  float dist_SL = distanceCalculator(trig_SL, echo_SL);
  float dist_FR = distanceCalculator(trig_FR, echo_FR);
  float dist_FL = distanceCalculator(trig_FL, echo_FL);

  if(abs(dist_FR - dist_FL) < 0.001){
    liftChassis();
  }
  else{
    alignFront();
  }
}

float distanceCalculator(int trigger, int echo){

  durata = 0;
  distanza = 0;

  //Invio un impulso HIGH sul pin del trigger
  digitalWrite(trigger, HIGH);
  //lo lascio al valore HIGH per 10 microsecondi
  delayMicroseconds(10);
  //lo riporto allo stato LOW
  digitalWrite(trigger, LOW);

  //ottengo il numero di microsecondi per i quali il PIN echo e' rimasto allo stato HIGH
  //per fare questo utilizzo la funzione pulseIn()
  durata = pulseIn(echo, HIGH);

  // La velocita' del suono e' di 340 metri al secondo, o 29 microsecondi al centimetro.
  // il nostro impulso viaggia in andata e ritorno, quindi per calcoalre la distanza
  // tra il sensore e il nostro ostacolo occorre fare:
  distanza = durata / 29 / 2;

  //invio i dati alla porta seriale cosi' da poterli vedere con il Monitor Seriale
  Serial.print("Durata : ");
  Serial.print(durata);
  Serial.print(" - Distanza : ");
  Serial.println(distanza);

  return distanza;
}

void alignFront(){
  //function to align sensor Front Right and Front Left
}

void liftChassis(){
  //lifting chassis function
}
