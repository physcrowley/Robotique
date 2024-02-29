#include <Arduino.h>

/*
Code produit durant un atelier à La Cité Collégial
Adapté par Charles Norminton et M. Crowley
2024-02
*/

/* 
 définir les broches utilisées
*/

// capteur ultrason
const int trig = 12;
const int echo = 11;

// DEL
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

/*
 déclarer les fonctions personnalisées
*/
bool setLedByDistance(int, int, int);

/*
 setup et loop
*/

void setup() {
  // spécifier le mode d'utilisation de chaque broche
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  // démarrer la communication série
  Serial.begin(9600);
}

void loop() {
  // prendre une lecture de distance
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int echoTime = pulseIn(echo, HIGH);
  int distance = echoTime / 58;
  Serial.println(distance);

  /*
   décider quelles DEL à activer
  */

  // tenir compte de la dernière DEL allumée (ou 0 si aucun ne s'allume)
  int lastLed = 0;
  lastLed = setLedByDistance(led1, distance, 50) ? led1 : lastLed;
  lastLed = setLedByDistance(led2, distance, 40) ? led2 : lastLed;
  lastLed = setLedByDistance(led3, distance, 30) ? led3 : lastLed;
  lastLed = setLedByDistance(led4, distance, 20) ? led4 : lastLed;
  lastLed = setLedByDistance(led5, distance, 10) ? led5 : lastLed;

  // clignoter la dernière DEL
  // (ou attendre le temps équivalent si aucune DEL n'est allumée)
  if (lastLed != 0) {
    digitalWrite(lastLed, HIGH);
    delay(250);
    digitalWrite(lastLed, LOW);
    delay(250);
  } else {
    delay(500);
  }


  // TODO - activer les autre DEL à des distances variées afin de donner
  // un effet de progression : 1 del vert si c'est très loin (plus loin que 150cm)
  // jusqu'à tous les DEL allumés quand c'est moins que 10cm
}

/*
 définir les fonctions personnalisées
*/

// allume la DEL sur ledPin si distanceValue <= distanceLimit; retourne true si la DEL est allumée
// étient la DEL sur ledPin si distanceValue > distanceLimit; retourne false dans ce cas
bool setLedByDistance(int ledPin, int distanceValue, int distanceLimit) {
  if (distanceValue <= distanceLimit) {
    digitalWrite(ledPin, HIGH);
    return true;
  } else {
    digitalWrite(ledPin, LOW);
    return false;
  }
}
