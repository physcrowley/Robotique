[Accueil](./index.md) > [4M](./acceuil4M.md#projet-7--mouvement-avec-mission)

# Projet 7 - Activité 2 : Capteurs

## Introduction

Si le robot est capable de détecter son environnement, on peut lui donner une certaine autonomie. Dans ce projet, vous apprendrez à utiliser des capteurs pour permettre à un robot de réagir à son environnement.

## Objectifs

1. Ajouter un haut-parleur, des capteurs tactiles et un capteur d'intensité lumineux à la base robotique pour programmer des comportements plus complexes du robot.

## Instructions

1. Créez un Google Docs pour répondre aux questions d'analyse ci-dessous.
1. Joignez ce document à la tâche Google Classroom associée.
1. Ajoutez dans le Google Docs un en-tête pour chaque section du tutoriel ci-dessous, et complétez les questions d'analyse à mesure que vous progressez.

D'ordre général :

- Suivez les instructions de montage et de vérification de votre robot dans les tutoriels sur CS2N,
- ... mais en remplaçant le code `.ino` fourni (et ignorant les détails spécifiques à Arduino EDI) par le **code modifié et adapté pour PlatformIO dans la section appropriée sur cette page du cours.**.
- Complétez les quiz de validation de la compréhension sur le site de CS2N.
- Sur cette page du cours (ici), répondez aux questions d'analyse additionnelles (dans votre Google Docs) et appliquez les autres modifications indiquées pour chaque section du tutoriel.
- Après avoir complété toutes les sections, créez un dossier compressé `.zip` qui contient tous les projets PlatformIO que vous avez produits/modifiés pour ce tutoriel et le joindre à la tâche Google Classroom associée.

[ACCÉDER AUX TUTORIELS CS2N POUR LES CAPTEURS ICI](https://www.cs2n.org/u/mp/badge_pages/158)

> _Page d'accueil de l'ensemble de ces tutoriels : [CS2N - Bases logicielles avec Arduino](https://www.cs2n.org/u/track_progress?id=290)_

### Code adapté, questions d'analyse et modifications additionnelles pour chaque section du tutoriel

- [Haut-parleur (piézo-électrique)](#haut-parleur-piézo-électrique)
- [Capteurs tactiles (moustaches)](#capteurs-tactiles-moustaches)
- [Pseudocode (virer aux obstacles)](#pseudocode)
- [Capteur lumineux (phototransistor)](#capteur-lumineux-phototransistors)
- [Application : balayeuse nocturne](#application--balayeuse-nocturne)
- [Application : balayeuse-compteur](#application--balayeuse-compteur)

### Haut-parleur (piézo-électrique)

> _[Instructions générales](#instructions)_

Code de démarrage : PiezospeakerDemoV2 -> [piezo-pio.zip](./code/platformio/piezo-pio.zip)

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N. Vous pourrez alors ignorez certaines explications sur des éléments de code qui ont été retirés, comme les macros `#define`.

#### Questions d'analyse

1. Que signifie le modificateur de variable `const`?
1. Que signifie le modificateur de variable `static` utilisé dans la fonction `loop()` : `static const int toneLength = 1000;`?
1. Pourquoi est-ce une bonne idée de déclarer une variable pour la durée du ton dans ce programme (on le fait dans setup() et dans loop())?
1. Quel ton est le plus aigu? Le plus grave? Il y en avait trois dans le programme : 2000Hz, 500Hz et 1500Hz.
1. Comment est-ce que l'utilisation de la bibliothèque personnelle que nous avons créée à la fin de l'activité 1 sur l'entrainement différentiel rend ce programme plus lisible? plus simple à utiliser?

#### Modifications au code

1. Modifier le code pour avoir des durées de tons différentes pour setup() et pour loop().
1. Faites des tests avec le délai pour le virage à droite pour obtenir un virage d'environs :
   1. 45 degrés,
   1. 90 degrés,
   1. 120 degrés.
1. Notez les valeurs obtenues dans votre document d'analyse. C'est de l'information qui pourrait être utile plus tard dans d'autres programmes.

### Capteurs tactiles (moustaches)

> _[Instructions générales](#instructions)_

Code de démarrage : WhiskerSetupV2 -> [whisker-pio.zip](./code/platformio/whisker-pio.zip)

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N.

#### Questions d'analyse


1. La constante `LOW` représente quelle valeur pour un signal numérique? La constante `HIGH`?
1. Dans le programme `piezo` il y avait des instructions `delay()` suite aux instructions pour les moteurs mais il n'y en a pas dans ce programme. Expliquez pourquoi. _Indice : consultez les notes sur la multi-tâche._
1. Selon la structure du code, est-ce que le contact avec la moustache met fin au programme? Pourquoi ou pourquoi pas? Qu'est-ce qui se passe si on enlève le contact avec la moustache?

#### Modifications au code

1. Ajouter un ton qui dure 0.5s quand le capteur tactile est enfoncé (en plus d'arrêter le mouvement du robot).

### Pseudocode

> _[Instructions générales](#instructions)_

Code de démarrage : VacuumPseudocodingStart -> [vacuum-pio.zip](./code/platformio/vacuum-pio.zip)

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N.

#### Questions d'analyse

1. Que veut dire le type `bool`?
1. En C++ avec la bibliothèque `Arduino.h` un `bool` peut prendre quelles valeurs ...
   1. s'il est faux?
   1. s'il est vrai?
1. Que veut dire l'opérateur `&&`? 
1. Les deux autres opérateurs logiques sont `||` et `!`, mais ils ne sont pas utilisés dans ce programme. Que veulent-ils dire?

#### Modifications au code

1. Assurez-vous d'avoir suivi les modifications du code dans le tutoriel pour transformer la cascade des `if-else` en chaîne linéaire de `if-else if-else`.

### Capteur lumineux (phototransistors)

> _[Instructions générales](#instructions)_

Code de démarrage :

- PhototransistorsV2 -> ...
- LightLevelPitchV2 ->

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N.

#### Questions d'analyse

#### Modifications au code

### Application : balayeuse nocturne

> _[Instructions générales](#instructions)_

Code de démarrage : NightimeVacuumV2 -> ...

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N.

#### Questions d'analyse

#### Modifications au code

### Application : balayeuse-compteur

> _[Instructions générales](#instructions)_

Code de démarrage : CountingVacuum -> ...

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N.

#### Questions d'analyse

#### Modifications au code
