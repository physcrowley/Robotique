[Accueil](./index.md)

# Exemples de code à télécharger

Cette page vous permet de télécharger des exemples de code pour les projets de robotique et d'ingénierie décrit dans les activités des cours TER3M et TER4M.

[EV3 (pybricks)](#ev3-pybricks)

[Arduino](#arduino)

## EV3 (pybricks)

­>🚧 à venir

## Arduino
Les exemples sont en format `.zip` ou `.ino` pour Arduino IDE et en format `.zip` pour PlatformIO (VSCode).

* [Initiation](#programme-dinitiation-classique)
* [Lié aux activités](#lié-aux-activités)
* [Lié au cours _Software Foundations with Arduino (Shieldbot)_ de CS2N](#lié-au-cours-software-foundations-with-arduino-shieldbot-de-cs2n)

### Programme d'initiation classique

Clignoter un DEL pour tester la connexion entre l'ordinateur et la carte Arduino.

- [Clignoter pour Arduino IDE](./arduinoide/blink/blink.ino) (`.zip`)
- [Clignoter pour PlatformIO](./platformio/blink-pio.zip) (`.zip`)

### Lié aux activités
_Source : voir les pages [3M](../acceuil3M.md) et [4M](../acceuil4M.md) pour les activités_

#### Test de servomoteurs

Utilise la bibliothèque `Servo.h` pour contrôler un servomoteur. Définit des fonctions pour le mouvement dans les deux sens et pour le retour à la position neutre ou l'arrêt. Vous devrez ajuster les valeurs de la durrée des impulsions selon le servomoteur que vous utilisez.

- [Servo-test pour Arduino IDE](./arduinoide/servo-test.zip) (`.zip`)
- [Servo-test pour PlatformIO](./platformio/servo-test-pio.zip) (`.zip`)

### Lié au cours _Software Foundations with Arduino (Shieldbot)_ de CS2N

_Source : [Software Foundations with Arduino (Shieldbot) de CS2N](https://www.cs2n.org/u/track_progress?id=290)_

### Exemple de Machine à états finis

Cet exemple est pour la caméra Pixy2, des moustaches tactiles et un haut-parleur piezoélectrique, comme pour [le défi proposé dans _Camera Programming with Arduino (Shieldbot)_](https://www.cs2n.org/u/mp/badge_pages/233). Le code implémente le diagramme d'états dans les [notes de cours de M. Crowley](https://docs.google.com/document/d/1LxZwPFYOOgUi6hL9_VkzVpgnHcKnO2U3EskbVziUh4s/view) en modularisant les instructions de trois façons différentes.

- [PixyFSM](./arduinoide/PixyFSM/PixyFSM.ino) (`.ino`) - code de base, purement procédural
- [PixyFSM_functions](./arduinoide/PixyFSM_functions/PixyFSM_functions.ino) (`.ino`)- code découpé en fonctions
- [PixyFSM_header pour Arduino IDE](./arduinoide/PixyFSM_header.zip) (`.zip`) - code déclarant une classe (dans un fichier `.h`) pour les constantes et les fonctions du robot
- [PixyFSM_header pour PlatformIO](./platformio/PixyFSM_header_pio.zip) (`.zip`) - même code que ci-dessus, mais pour PlatformIO. Le fichier `.h` est dans le dossier `include` et le fichier `.cpp` est dans le dossier `src`.
