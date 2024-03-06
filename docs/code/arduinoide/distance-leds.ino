/*
Code de démarrage pour créer un indicateur lumineux de distance avec
un capteur ultrason HC-SR04 avec la bibliothèque NewPing et des DEL
de différentes couleurs.

Ce code bâti sur NewPingExample.ino de la bibliothèque NewPing et sur
un projet fait par Charles Norminton durant un atelier à La Cité Collégiale
à Ottawa, ON, Canada.

Créé : 2024-02
Mis à jour : 2024-02
Auteur : David Crowley
*/

#include <Arduino.h>
#include <NewPing.h> // ajouter la bibliothèque via le menu Libraries

/*
définir les broches utilisées et les constantes physiques
*/

// capteur ultrason
const int trig = 12;
const int echo = 11;
const int maxDistance = 250; //cm
NewPing sonar(trig, echo, maxDistance); // créer un objet NewPing pour gérer le capteur

// DEL
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

void setup() {
  // spéficier le mode d'utilisation de chaque broche
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
  delay(50); //ms; le délai minimal entre lectures est 29ms
  int distance = sonar.ping_cm(); // lire le capteur et convertir la réponse en cm
  
  // afficher le résultat de la lecture
  Serial.print("Distance : ");
  if (distance == 0 ){
    // la valeur 0 indique que la réponse a pris plus de temps que nécessaire pour maxDistance
    Serial.println("hors limites"); 
  } else {
    // les autres valeurs sont valides
    Serial.print(distance);
    Serial.println("cm");
  }

  // activer le led1 selon la valeur
  if (distance <= 10) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }

  // TODO - activer les autre DEL à des distances variées afin de donner
  // un effet de progression : 1 del vert si c'est très loin (plus loin que 150cm)
  // jusqu'à tous les DEL allumés quand c'est moins que 10cm

}
