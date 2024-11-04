/* 
* Inclure des BIBLIOTHÈQUES - du code déjà écrit
*/
#include <Arduino.h>

/*
* DÉCLARATIONS DES VARIABLES GLOBALES ET DES CONSTANTES
*/

// constante, déclarée avec le mot-clé const
const int LED = 12; // la broche 12 est connectée à une DEL

// variables globales, déclarées en dehors des fonctions
int state;

void setup() {
  pinMode(LED, OUTPUT); // spécifier le mode de fonctionnement de la DEL
}

void loop() {
  // Alterner entre un état allumé (HIGH) et éteint (LOW)
  state = HIGH;
  digitalWrite(LED, state);
  delay(1000); // attendre 1 seconde (1000 millisecondes)
  
  state = LOW;
  digitalWrite(LED, state);
  delay(1000);
}
