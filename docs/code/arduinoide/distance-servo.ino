#include <Arduino.h>
#include <Servo.h>

/*
 Broches physiques
*/
// broches du capteur de distance HC SR04
const int trig = 12;
const int echo = 11;
// broche pour le signal du servomoteur
const int servoPin = 6; // broche avec modulation de la largeur de pulsations

/*
 Objets
*/
Servo indicator;

void setup() {
  indicator.attach(servoPin);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600); // pour le déboggage
}

void loop() {
  // prendre une lecture de distance
  // voir une fiche de spécification HC SR04 pour la technique 
  // et pour le calcul détaillé de la distance
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int echoTime = pulseIn(echo, HIGH);
  int distance = echoTime / 58; 
  Serial.println(distance);

  // TODO utiliser la fonction map() pour convertir la distance en valeur appropriée pour le signal du servo
  int servoSignal;

  // TODO contrôler la position du servo avec le signal calculé


  delay(500); // laisser le temps au servo de se positionner correctement
}
