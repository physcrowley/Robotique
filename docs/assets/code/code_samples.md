<a href="../../index.md" target="_blank">Accueil</a>

# Exemples de code à télécharger

Cette page vous permet de télécharger des exemples de code pour les projets de robotique et d'ingénierie décrits dans les cours TER3M et TER4M.

- Exemples pour <a href="#ev3-pybricks" target="_blank">EV3 (pybricks)</a>
- Exemples pour <a href="#arduino" target="_blank">Arduino</a>

## EV3 (pybricks)

_<a href="#arduino" target="_blank">🔗 Sauter à Arduino</a>_

Les exemples sont en format `.py` et devraient remplacer le fichier `main.py` dans le dossier de votre projet EV3 Pybricks.

### Projet 1

- [Démarrage](./pybricks/starter.py) - mais ce code est déjà le fichier `main.py` quand on crée un nouveau projet EV3 avec l'extension LEGO MINDSTORMS EV3 pour VSCode.

### Projet 6

­> 🚧 à venir

## Arduino

_<a href="#ev3-pybricks" target="_blank">🔗 Sauter à EV3 (pybricks)</a>_

Sections

- <a href="#projet-2" target="_blank">Projet 2 : Circuits électroniques et programmation</a>
- <a href="#projet-5" target="_blank">Projet 5 : Systèmes mécaniques</a>
- <a href="#projet-6" target="_blank">Projet 6 : Mouvement avec mission</a>
- <a href="#lié-au-cours-software-foundations-with-arduino-shieldbot-de-cs2n" target="_blank">Lié au cours _Software Foundations with Arduino (Shieldbot)_ de CS2N</a>

Les exemples sont en format `.ino` pour Arduino IDE et en format `.zip` pour PlatformIO (VSCode).

### Projet 2

#### Activité 2

4M : boutons-poussoirs et temps de réponse

> Voir les liens dans l'activité <a href="../../p2-4m_act2.md" target="_blank">boutons-poussoirs et temps de réponse</a>

#### Activité 3

Démonstrations d'éléments de base de la programmation Arduino (format Arduino IDE) :

- types de données et de variables : [data_demo.ino](./arduinoide/data_demo.ino)
- conditions : [conditional_demo.ino](./arduinoide/conditional_demo.ino)
- afficher des messages : [serial_demo.ino](./arduinoide/serial_demo.ino)

Version 3M : clignotement d'une DEL

- Arduino IDE [blink.ino](./arduinoide/blink.ino)
- PlatformIO [blink-pio.zip](./platformio/blink-pio.zip)

Version 4M : contrôle de différents types de moteurs

- Arduino IDE :
  - [servo-test.ino](./arduinoide/servo-test.ino) - pour tester un servomoteur
  - <a href="../../p2-4m_act3.md" target="_blank">Voir l'activité</a> pour le code pour les moteurs CC et les moteurs pas-à-pas

#### Activité 4

Version 3M : avec indicateurs DEL

- Arduino IDE [distance-leds.ino](./arduinoide/distance-leds.ino)
- PlatformIO [distance-leds-pio.zip](./platformio/distance-leds-pio.zip)

Version 4M : avec un servomoteur comme indicateur de distance

- Arduino IDE [distance-servo.ino](./arduinoide/distance-servo.ino)
- PlatformIO [distance-servo-pio.zip](./platformio/distance-servo-pio.zip)

### Projet 5

#### Activité 1 (4M seulement) - tourelle universelle

- PlatformIO [pot-test-pio.zip](./platformio/pot-test-pio.zip) - pour tester les potentiomètres
- PlatformIO [servo-test-pio.zip](./platformio/servo-test-pio.zip) - pour tester les servomoteurs
- PlatformIO [tourelle-pio.zip](./platformio/tourelle-pio.zip) - code de démarrage pour le projet de tourelle universelle

#### Activité 2

Version 3M : concours de biceps

- [safe_motor.zip](./pybricks/safe_motor.zip) - pour contrôler un moteur EV3 en toute sécurité

Version 4M : bras robotique avec pince

­> 🚧 à venir

### Projet 6

­> 🚧 à venir


### Lié au cours _Software Foundations with Arduino (Shieldbot)_ de CS2N

_Source : <a href="https://www.cs2n.org/u/track_progress?id=290" target="_blank">Software Foundations with Arduino (Shieldbot) de CS2N</a>_

#### Exemple de Machine à états finis

Cet exemple est pour la caméra Pixy2, des moustaches tactiles et un haut-parleur piezoélectrique, comme pour <a href="https://www.cs2n.org/u/mp/badge_pages/233" target="_blank">le défi proposé dans _Camera Programming with Arduino (Shieldbot)_</a>. 

Le code implémente le diagramme d'états dans les <a href="https://docs.google.com/document/d/1LxZwPFYOOgUi6hL9_VkzVpgnHcKnO2U3EskbVziUh4s/view" target="_blank">notes de cours de M. Crowley</a> en modularisant les instructions de trois façons différentes.

- [PixyFSM.ino](./arduinoide/PixyFSM.ino) - code de base, purement procédural
- [PixyFSM_functions.ino](./arduinoide/PixyFSM_functions.ino)- code découpé en fonctions
- [PixyFSM_header pour Arduino IDE](./arduinoide/PixyFSM_header.zip) (`.zip`) - code déclarant une classe (dans un fichier `.h`) pour les constantes et les fonctions du robot
- [PixyFSM_header pour PlatformIO](./platformio/PixyFSM-header-pio.zip) (`.zip`) - même code que ci-dessus, mais pour PlatformIO. Le fichier `.h` est dans le dossier `include` et le fichier `.cpp` est dans le dossier `src`.
