[Accueil](./index.md) > [4M](./acceuil4M.md#projet-2--circuits-électroniques-et-programmation)

# Projet 2 - Activité 3 : pourquoi utiliser un microcontrôleur comme l'Arduino?

## Objectif

- Utiliser le capteur de distance HC-SR04 pour contrôler la position d'un servomoteur.
- Utiliser la fonction `map()` pour convertir l'intervalle de lectures d'un capteur vers un intervalle approprié de sorties pour un servomoteur.
- Compléter un schéma électrique pour le projet à partir d'un gabarit.

## Matériel

* 1 carte Arduino Uno
* 1 fil USB pour relier la carte à l'ordinateur
* 1 capteur de distance à ultrasons HC-SR04
* 1 servomoteur SG90
* 1 plaque d'essai
* fils de raccordement
* carton / papier / ciseaux et ruban adhésif pour construire le cadran pour l'indicateur

## Code de démarrage

Ouvrir le code de démarrage dans votre environnement de développement Arduino.
* Version Arduino IDE : [distance-servo.ino](./code/arduinoide/distance-servo.ino)
* Version PlatformIO : [distance-servo-pio.zip](./code/platformio/distance-servo-pio.zip)

Le code devrait fonctionner correctement à l'état initial pour fournir des lectures de distance valides.

Constatez les éléments suivants :
* Le code utilise la bibliothèque `Servo.h` pour contrôler le servomoteur.
* Les valeurs des broches utilisés pour les différents composants
* Les commentaires `TODO` pour indiquer où ajouter du code pour compléter le projet.

## Schéma

Compléter un schéma des connections électriques pour le projet. Utiliser le gabarit suivant qui utilise le site [Circuit Diagram](https://www.circuit-diagram.org/).

* [Gabarit pour le schéma](./images/p2/distance-servo.cddx)



