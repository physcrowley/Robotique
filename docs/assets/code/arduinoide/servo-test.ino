/*
Ce programme vous aide à vérifier indépendamment le comportement de chaque servomoteur avant de
l'intégrer dans un projet.

Chaque fois que vous utilisez un nouveau servomoteur, vous devrez :
  1) lire les spécifications pour le servo (faire une recherche en ligne ou auprès du fournisseur)
  2) et tester le servo

Cela élimine les incertitudes concernant le contrôle du servo. S'il y a des problèmes
après ces tests, on peut savoir que c'est causé par quelque chose d'autre (connexions
électriques, source d'énergie ou logique du programme)
*/

#include <Arduino.h>
#include <Servo.h>

Servo motor; 
const int motorPin = 5;

/*
SIGNAUX POUR LES SERVOMOTEURS
À vérifier/modifier durant les tests de calibrage
*/
const int CENTER_OR_STOP = 1500; // microsecondes et fixe -> calibrez le servomoteur au besoin
const int CLOCKWISE_LIMIT = 2300; // microsecondes -> à vérifier durant les tests
const int COUNTERCLOCKWISE_LIMIT = 700; // microsecondes -> à vérifier durant les tests

/*
FONCTIONS PERSONNELLES POUR LES MOTEURS
Emballer les commandes moteur avec des noms plus descriptifs
*/ 

void clockWise() {
  motor.writeMicroseconds(CLOCKWISE_LIMIT);
}

void counterClockWise() {
  motor.writeMicroseconds(COUNTERCLOCKWISE_LIMIT);
}

void centerOrStop() {
  motor.writeMicroseconds(CENTER_OR_STOP);
}

void setup() {
  motor.attach(motorPin); // initialiser l'objet Servo en spécifiant sa broche de signal

  // TODO tester d'abord cette instruction seule, puis enlever progressivement les commentaires sur les commandes de rotation. Si le servo à rotation continue n'est pas immobile avec ce signal ajuster le vis de calibrage sur le moteur
  centerOrStop();
  delay(5000);

  // TODO changer CLOCKWISE_LIMIT jusqu'à ce que la position n'augmente plus (entre 2000 et 2300) ou la vitesse de rotation n'augmente plus (près de 1700). La valeur minimale qui atteint cet état est la valeur à utiliser pour ce servomoteur.
  // clockWise(); 
  // delay(5000);

  // TODO changer COUNTERCLOCKWISE_LIMIT jusqu'à ce que la position n'augmente plus (entre 1000 et 500) ou la vitesse de rotation n'augmente plus (près de 1300). La valeur minimale qui atteint cet état est la valeur à utiliser pour ce servomoteur.
  // counterClockWise();
  // delay(5000);

  centerOrStop(); // recentrer/arrêter le moteur à la fin
  delay(1000);
}

void loop() {
  // pas utilisé 
}

