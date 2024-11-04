/*
Code de démarrage pour créer un cadran indicatur de distance avec
un capteur ultrason HC-SR04 plus la bibliothèque NewPing et un servomoteur.

Ce code bâti sur NewPingExample.ino de la bibliothèque NewPing

Créé : 2024-02
Mis à jour : 2024-02
Auteur : David Crowley
*/

#include <Arduino.h>
#include <NewPing.h> // ajouter la bibliothèque via le menu Libraries
#include <Servo.h>

/*
définir les broches utilisées
*/

// capteur ultrason
const int trig = 12;
const int echo = 11;

// broche pour le signal du servomoteur
const int servoPin = 6; // broche avec modulation de la largeur de pulsations

/*
Constantes obtenues durant le calibrage
>>> VÉRIFIER CES VALEURS AVEC VOTRE PROPRE CAPTEUR ET SERVO <<<
*/

const int maxDistance = 200; // en cm
const int minSignal = 1300; // en microsecondes
const int maxSignal = 1700; // en microsecondes

/*
Objets pour gérer les capteurs et moteurs
*/

NewPing sonar(trig, echo, maxDistance); // capteur ultrason
Servo indicator; // servomoteur

void setup() {
  indicator.attach(servoPin);
  Serial.begin(9600); // pour le déboggage
}

void loop() {
  // prendre une lecture de distance
  int distance = sonar.ping_cm(); // lire le capteur et convertir la réponse en cm
  
  // afficher le résultat de la lecture
  Serial.print("Distance : ");
  if (distance == 0 ){
    // la valeur 0 indique que la réponse a pris plus de temps que nécessaire pour maxDistance
    Serial.println("hors limites"); 
    distance = maxDistance; // modifier la distance à utiliser pour le cadran
  } else {
    // les autres valeurs sont valides
    Serial.print(distance);
    Serial.println("cm");
  }

  // TODO utiliser la fonction map() pour convertir la distance en valeur appropriée pour le signal du servo
  // Indice : utiliser les constantes maxDistance, minSignal, maxSignal comme arguments pour map()
  int servoSignal;
  

  // TODO contrôler la position du servo avec le signal calculé


  // délai pour laisser le servo se positionner
  // le strict minimum est de 29ms pour le temps entre les lectures de distance
  // TODO minimiser cette valeur pour une meilleur réactivité sans compromettre la fiabilité
  delay(500); 
}