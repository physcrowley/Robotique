[Accueil](./index.md) > [4M](./acceuil4M.md#projet-2--circuits-électroniques-et-programmation)

# Projet 2 - Activité 4 : Indicateur de distance

## Objectif

- Utiliser le capteur de distance HC-SR04 pour contrôler la position d'un servomoteur.
- Utiliser la fonction `map()` pour convertir l'intervalle de lectures d'un capteur vers un intervalle approprié de sorties pour un servomoteur.
- Compléter un schéma électrique pour le projet à partir d'un gabarit.

## Matériel

- 1 carte Arduino Uno
- 1 fil USB pour relier la carte à l'ordinateur
- 1 capteur de distance à ultrasons HC-SR04
- 1 servomoteur SG90
- 1 plaque d'essai
- fils de raccordement
- carton / papier / ciseaux et ruban adhésif pour construire le cadran pour l'indicateur

## Code de démarrage

Ouvrir le code de démarrage dans votre environnement de développement Arduino.

- Version Arduino IDE : [distance-servo.ino](./assets/code/arduinoide/distance-servo.ino)
- Version PlatformIO : [distance-servo-pio.zip](./assets/code/platformio/distance-servo-pio.zip)

Le code devrait fonctionner correctement à l'état initial pour fournir des lectures de distance valides.

Constatez les éléments suivants :

- Le code utilise la bibliothèque `Servo.h` pour contrôler le servomoteur.
- Les valeurs des broches utilisées pour les différents composants
- Les commentaires `TODO` pour indiquer où ajouter du code pour compléter le projet.

## Schéma

Compléter un schéma des connections électriques pour le projet. Utiliser le gabarit suivant :

- [Gabarit pour le schéma](./assets/images/p2/distance-servo.cddx)

1. Télécharger le gabarit (format `.cddx`).
1. Ouvrir le site [Circuit Diagram](https://www.circuit-diagram.org/).
1. Ouvrir le gabarit téléchargé via le menu `Open` > `Import`.
1. Sélectionner l'outil `Wire` pour ajouter des fils entre les composants et les broches appropriées sur la carte Arduino.
   > Utiliser les déclarations dans le code pour identifier les broches à utiliser dans le circuit.
1. Les connexions pour la masse (`GND`) et le 5V (`Vcc`) sont déjà faites pour le capteur de distance et le servomoteur.
   > Les fils nommés `rail +` et `rail -` représentent les rails d'alimentation sur la plaque d'essai.
1. Télécharger le schéma terminé via le menu `Download` > `PNG Image`.

## Instructions

1. Monter le circuit selon le schéma complété.
1. Tester le montage de base :
   1. Tester le code de démarrage pour vérifier que la distance s'affiche correctement dans le moniteur série.
   1. Calibrez le servomoteur pour qu'il tourne de 0 à 180 degrés.
      > [Utilisez les instructions et le code de l'activité 3](p2-4m_act3.md) pour cette étape. Si vous travaillez dans **Arduino IDE**, simplement ouvrir le projet dans une fenêtre séparée. Si vous travaillez dans **PlatformIO**, vous pouvez copier le code du dossier `src` de l'activité 3 dans le dossier `tests` de ce projet et lancer le test au lieu de lancer le projet.
1. Compléter le code - les tâches décrites dans les `TODO`- pour que le servomoteur tourne en fonction de la distance mesurée.
   > Indices : vous devrez faire une recherche dans la documentation ou dans des tutoriels pour découvrir comment la fonction `map()` fonctionne. Vous devrez aussi ajouter un bras au servomoteur afin de visualiser correctement sa position. Ce bras deviendra l'indicateur de distance.
1. Construire un cadran pour l'indicateur de distance.
   1. Fixer un morceau de carton ou de papier sur la bôitier du servomoteur afin que l'axe du servomoteur passe à travers la feuille (couper un fente ou un trou pour l'arbre). Attacher le bras au servomoteur une fois que la feuille est attachée.
   1. Créer un cadran sur le carton avec des graduations pour les distances. Commencer avec les distances extrêmes (2 cm et 200 cm) et ajouter des graduations intermédiaires. Retirer le carton du moteur, au besoin, pour bien tracer les graduations et le rattacher par la suite.
1. Filmer le fonctionnement de l'indicateur de distance en action.

Enrichissement fortement suggérée :

- Ajouter un bouton-poussoir au projet pour activer ou désactiver l'indicateur de distance (lectures du capteur et mouvement du servomoteur). [Voir l'activité 2](p2-4m_act2.md) pour des idées sur comment ajouter un bouton-poussoir à un projet. Comme avec les tests du servomoteur, tester le bouton-poussoir indépendamment du projet principal pour vous assurer qu'il fonctionne correctement avant de l'ajouter au projet principal.
- Si l'indication de distance est désactivé, l'indicateur devrait indiquer l'état éteint (p. ex. à 0 degré pour le servomoteur). Sinon, l'indicateur devrait indiquer la distance mesurée sur le cadran (p. ex. entre 30 degrés et 180 degrés).
  - Ajoutez une nouvelle constante pour l'angle de repos (état éteint) de l'indicateur.
  - Changez la valeur pour le signal pour la distance minimal pour donner une séparation avec la position de repos.
- Créer un nouveau cadran de carton afin de refléter les nouvelles positions du servomoteur:
  - Le cadran devrait inclure les positions suivantes : Off 2cm ... 200cm
- Filmer le nouveau fonctionnement de l'indicateur de distance en action.

## À soumettre

Soumettre les documents suivants dans l'activité appropriée sur le Google Classroom :

1. Le schéma complété en format image (p. ex. `.png`).
1. Une vidéo du projet en action.
1. Le code complété pour le projet (le fichier `.ino` ou `.cpp`).
