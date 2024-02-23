[Accueil](./index.md) > [4M](./acceuil4M.md#projet-2--circuits-électroniques-et-programmation)

# Projet 2, Activité 3 : Servomoteurs, moteurs à courant continu et moteurs pas-à-pas

## Objectif

* Comprendre les différences concrètes entre les servomoteurs, les moteurs à courant continu et les moteurs pas-à-pas.
* Apprendre à contrôler ces moteurs avec un microcontrôleur.

## Servomoteurs

### Introduction aux servomoteurs
Consultez la vidéo d'introduction suivante :

> 🚧 à ajouter

### Activité

#### Matériel 

* 1 servomoteur 9g
* 1 bras de servomoteur (pour voir la position/le mouvement)
* 3 fils de raccordement
* 1 carte Arduino Uno
* 1 fil USB pour relier la carte à l'ordinateur

#### Schéma

Connectez le servomoteur à la carte Arduino Uno selon le schéma suivant (le utilisé pour le servo contient les même connexions que le servomoteur 9g mais est le symbole pour un capteur infrarouge) :

![Schéma de connexion pour un servomoteur](./images/p2/schematic-act3_servo.png)

#### Instructions

1. Ouvrir l'exemple servo-test dans votre environnement de développement Arduino. 
* Version Arduino IDE : [servo-test.zip](./code/arduinoide/servo-test.zip)
* Version PlatformIO : [servo-test-pio.zip](./code/platformio/servo-test-pio.zip)
1. Attachez le bras de servomoteur au servomoteur afin qu'il soit parallèle au corps du servomoteur quand le servomoteur est à 90° (le signal `STOPPED`).
1. Ajustez les valeurs pour les signaux `STOPPED`, `LEFT` et `RIGHT` pour que le bras de servomoteur soit à 90°, 0° (limite de rotation anithoraire) et 180° (limite de rotation horaire) respectivement.
1. Filmez le comportment du servomoteur quand il tourne jusqu'à ses limites avec les signaux programmés.


## Moteurs à courant continu

### Introduction aux moteurs à courant continu et à la puce L293D

### Activité

🚧 Suivre ces instructions :

[tiré du manuel pour notre trousse de pièces](https://www.manualslib.com/manual/1810234/Uctronics-Ultimate-Starter-Kit-For-Arduino.html?page=38#manual)

#### Matériel


#### Schéma


#### Instructions

## Moteurs pas-à-pas

### Introduction aux moteurs pas-à-pas et au module de contrôle ULN2003

### Activité
🚧 Suivre ces instructions :

[tiré du manuel pour notre trousse de pièces](https://www.manualslib.com/manual/1810234/Uctronics-Ultimate-Starter-Kit-For-Arduino.html?page=40#manual)

#### Matériel


#### Schéma


#### Instructions
