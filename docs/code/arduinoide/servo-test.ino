#include <Arduino.h>
#include <Servo.h>

Servo motor; 
const int motorPin = 5;

/*
SIGNAUX POUR LES SERVOMOTEURS

1500 us = 1.5ms -> position centrale (ou vitesse nulle)

2000 us = 2.0 ms -> position (vitesse) extrême dans le sens des aiguilles
  ... mais certains servos se limitent à 2300 (1700)

1000 us = 1.0 ms -> position (vitesse) extrême dans le sens opposé des aiguilles
  ... mais certains servos se limitent à 700 (1300)

Si c'est un servo standard, ces signaux spécifient des positions
Si c'est un servo à rotation continue, ces signaux spécifient 
    la vitesse et la direction de rotation

Il faut 
  1) lire les spécifications pour le servo
  2) et tester le servo 
pour connaître son comportement exact avant de l'intégrer dans un projet.

Cela élimine les incertitudes concernant le contrôle du servo. S'il y a des problèmes
après ces tests, on peut savoir que c'est causé par quelque chose d'autre (connexions
électriques, source d'énergie ou logique du programme)
*/
const int STOPPED = 1500;
const int RIGHT = 2300;
const int LEFT = 700;

// Variables d'état - seront changés durant le programme
int counter = 0;

/*
emballer les commandes moteur avec des noms plus descriptifs
*/ 
void turnRight() {
  motor.writeMicroseconds(RIGHT);

}

void turnLeft() {
  motor.writeMicroseconds(LEFT);
}

void stopMotor() {
  motor.writeMicroseconds(STOPPED);
}

void setup() {
  // put your setup code here, to run once:
  motor.attach(motorPin);

  // tester une fois chaque instruction
  turnRight();
  delay(5000);
  stopMotor();
  delay(1000);
  turnLeft();
  delay(5000);
  stopMotor();
  delay(1000);
}

void loop() {
  // donne un signal de position/vitesse pendant 10000 itérations
  // puis arrête/revient à la position centrale
  if (counter < 10000){
    // turnRight();
    turnLeft();
    counter++;
  } else {
    stopMotor();
  }
  delay(1); // attend 1 milliseconde
}

