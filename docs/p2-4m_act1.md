[Accueil](./index.md) > [4M](./accueil4M.md#projet-2--circuits-électroniques-et-programmation)

# Projet 2, Activité 1 : Les environnements de développement pour Arduino

[Détails pour Arduino IDE](#arduino-ide)   |   [Détails pour PlatformIO](#platformio)

## Objectif

* Prendre connaissance des deux principaux environnements de développement pour programmer des microcontrôleurs Arduino.
* Savoir comment utiliser l'environnement choisi pour créer et gérer des projets Arduino.

## Introduction

Ce tutoriel présente les environnements de développement suivants :
* **Arduino IDE**, un environnement de développement intégré pour programmer des microcontrôleurs Arduino
* **PlatformIO**, une extension pour l'éditeur de code Visual Studio Code pour programmer une diversité de microcontrôleurs, incluant Arduino

Caractéristiques | Arduino IDE | PlatformIO
--- | --- | ---
Installation | [Télécharger](https://www.arduino.cc/en/software) la version 2.x la plus récente pour _Window 10 ou plus récent (64bits)_ | [Installer](https://docs.platformio.org/en/latest/ide/vscode.html) l'extension pour [Visual Studio Code](https://code.visualstudio.com/) _(🚧 L'installation complète de PlatformIO est impossible actuellement sur les G7 du local d'informatique)_
Avantages | Facile à créer un nouveau projet, interface utilisateur simplifiée | Connexion automatique avec la carte Arduino, meilleure assistance pour la programmation (VS Code), format de fichier standard (`.cpp`), fonctionne avec plusieurs platformes (pas juste Arduino)
Inconvénients | Pas de connexion automatique avec la carte Arduino, format de fichier spécial (`.ino`) | Structure de projet plus complexe (dossier `src` et fichier `platformio.ini`)

## Présentation des environnements

Cliquez sur le lien approprié pour votre environnement afin d'apprendre ses fonctionnalités de base.

* [Arduino IDE](./p2-3m_act2-arduino.md)
* [PlatformIO](./p2-3m_act2-pio.md)

## Activité

### Matériel

* 1 carte Arduino Uno
* 1 câble USB

### Instructions

1. Téléchargez le projet `Clignoter` avec le lien approprié ci-dessous et l'enregistrer dans le répertoire de projet par défaut de votre environnement de développement :
    * Arduini IDE : [blink.ino](./assets/code/arduinoide/blink.ino) > dans `~/Documents/Arduino`
    * PlatformIO : [blink-pio.zip](./assets/code/platformio/blink-pio.zip) > enregistrer > **extraire le dossier** `blink-pio` dans `~/Documents/PlatformIO/Projects` 
1. Ouvrez votre environnement de développement
1. Ouvrez le projet `Clignoter` selon la démarche approprié pour votre environnement.
1. Compilez le projet pour vérifier qu'il n'y a pas d'erreurs.
1. Connectez votre carte Arduino à votre ordinateur et téléversez le projet sur la carte.

### Soumettre votre travail

Capturez sur vidéo :
* l'écran de votre environnement de développement (Arduino IDE ou PlatformIO dans VS Code) **montrant le projet correctement compilé** et
* le résultat sur la carte Arduino connectée (la DEL intégrée près de la broche 13 clignote)

Rendez la vidéo dans la tâche appropriée sur Google Classroom.
