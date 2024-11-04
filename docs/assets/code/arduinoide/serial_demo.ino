#include <Arduino.h>

int age = 14;

void setup() {
  Serial.begin(9600); // démarrer la communication

  /*
  Serial.print() --> affiche des choses sans passer à la ligne suivante
  Serial.println() --> affiche des choses et ajoute un retour de ligne
  \n --> caractère spéciale qui peut être insérer dans un texte pour ajouter un retour
          de ligne
  */
  Serial.print("Bonjour \n");
  Serial.println("Younes");
  Serial.print("fin");

}

void loop() {
  // put your main code here, to run repeatedly:

}
