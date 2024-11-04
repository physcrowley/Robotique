/*
  Projet :  Contrôler un servomoteur avec un capteur de distance
  Description :  Un servomoteur est contrôlé par un capteur de distance HC SR04.
  Un bouton-poussoir permet de désactiver/activer le mécanisme.
  Le servomoteur est positionné selon la distance mesurée par le capteur mais
  réserve aussi une position d'arrêt pour indiquer quand le mécanisme est 
  désactivé.
  Date :  2024-02-28
  Auteur :  David Crowley
*/
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

// broche pour l'état du bouton-poussoir
const int button = 7;

/*
 Constantes obtenues durant le calibrage
*/
const int maxDistance = 200; // en cm
const int offSignal = 700; // en microsecondes
const int minSignal = 1000; // en microsecondes
const int maxSignal = 2300; // en microsecondes

/*
 Variables globales
*/

// indique si le mécanisme est actif ou non
bool showDistance = false;

// temps documentés au lieu de delay() pour éviter de bloquer le programme
long lastServoSignalTimeMs;
long lastButtonPressTimeMs;

/*
 Objets
*/
Servo indicator;

void setup() {
  // spécifier le mode d'utilisation de chaque broche
  indicator.attach(servoPin);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(button, INPUT);
  // initialiser les composants
  indicator.writeMicroseconds(offSignal); // position initiale
  lastServoSignalTimeMs = millis(); // documenter le temps du dernier signal au servo
  lastButtonPressTimeMs = millis(); // initialiser le temps du dernier appui sur le bouton
  Serial.begin(9600); // pour le déboggage
}

void loop() {
  // changer l'état de showDistance si le bouton-poussoir est appuyé
  // seulement si au moins 50 millisecondes se sont écoulées depuis le dernier appui
  bool buttonPressed = false;
  if (digitalRead(button) == HIGH
      && millis() - lastButtonPressTimeMs > 50){
    buttonPressed = true;
    showDistance = !showDistance; // inverser l'état
    lastButtonPressTimeMs = millis(); // réinitialiser le temps du dernier appui
  }

  // si showDistance est faux
  if (!showDistance) {
    // si on vient de pousser le bouton, bouger le servo à la position d'arrêt
    if (buttonPressed) {
      indicator.writeMicroseconds(offSignal);
      lastServoSignalTimeMs = millis();
    }
    // dans tous les cas finir cet appel de loop() et passer à la prochaine
    return; 
  }

  // sinon, faire le code pour indiquer la distance

  // prendre une lecture de distance
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int echoTime = pulseIn(echo, HIGH);
  int distance = echoTime / 58; 
  Serial.println(distance);

  // convertir la distance en valeur appropriée pour le signal du servo
  int servoSignal = map(distance, 0, maxDistance, minSignal, maxSignal);

  // envoyer le signal au servomoteur
  // seulement si au moins 500 millisecondes se sont écoulés depuis le dernier changement
  // pour laisser le servo se positionner correctement
  if (millis() - lastServoSignalTimeMs > 500) {
    indicator.writeMicroseconds(servoSignal);
    lastServoSignalTimeMs = millis();
  }
}
