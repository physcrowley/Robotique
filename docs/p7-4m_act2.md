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

<a href="https://www.cs2n.org/u/mp/badge_pages/158" target="_blank">ACCÉDER AUX TUTORIELS CS2N POUR LES CAPTEURS ICI</a>

> _Page d'accueil de l'ensemble de ces tutoriels : <a href="(https://www.cs2n.org/u/track_progress?id=290)" target="_blank">CS2N - Bases logicielles avec Arduino</a>_

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
1. Les deux autres opérateurs logiques sont `||` et `!`, mais ils ne sont pas utilisés dans ce programme. Que veulent-ils dire? Faire une recherche pour trouver la réponse.

#### Modifications au code

1. Assurez-vous d'avoir suivi les modifications du code dans le tutoriel pour transformer la cascade des `if-else` en chaîne linéaire de `if-else if-else`.

### Capteur lumineux (phototransistors)

> _[Instructions générales](#instructions)_

Code de démarrage :

- PhototransistorsV2 et LightLevelPitchV2 -> [light-pio.zip](./code/platformio/light-pio.zip)

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N.

#### Questions d'analyse

1. Quelle est la différence entre les valeurs produites par un capteur _numérique_ comme un bouton (ou une moustache) et un capteur _analogique_ comme un phototransistor?
2. Quelle différence y a-t-il entre les numéros de broches analogiques et de broches numériques dans la bibliothèque `Arduino.h` (dans votre programme Arduino)?
3. Est-ce que les valeurs du phototransistor sont plus élevées quand il y a plus de lumière ou quand il y a moins de lumière?

#### Modifications au code

1. Appliquez vos connaissances de la technique `millis()` pour créer un bip répétitif de 0.3s (comme un clignotement sonore) si la valeur lumineuse est plus haute qu'une certaine valeur, p. ex. 200. Ajuster la valeur limite selon ce que vous observez dans votre environnement.

### Application : balayeuse nocturne

> _[Instructions générales](#instructions)_

Code de démarrage : NightimeVacuumV2 -> [night-vacuum-pio.zip](./code/platformio/night-vacuum-pio.zip)

#### Questions d'analyse

1. Pourquoi est-ce que le type `bool` est approprié pour les variables `leftState` et `rightState` (lignes 68 et 69)? Quelles valeurs peuvent être gardées dans un booléen? Quelles valeurs sont données par la fonction `digitalRead()`?
2. Mesurez les mouvements produits par chaque série d'instructions :
   1. Reculer pendant 1s (combien de cm)?
   2. Tourner pendant 800ms (combien de degrés)?
   3. Tourner pendant 400ms (combien de degrés)?
3. Ce code utilise la fonction `delay()` pour gérer le temps des mouvements. Dans le contexte de ce programme, est-ce que c'est une option raisonnable, ou serait-il important de remplacer ça avec des équivalents en `millis()`? Est-ce que le robot passe toujours son temps dans une branche de code qui utilise `delay()`? C'est quoi le pire cas possible ici avec `delay()` en terme de blocage du code? Est-ce que c'est un problème considérant l'objectif du programme : un robot qui est actif uniquement quand il fait sombre?

#### Modifications au code

1. Ajustez les durées, au besoin, pour obtenir des distances ou angles plus appropriés.
2. Produire un ton différent (sans un délai spécifique) pour chaque type de contact avec un obstacle (droite, gauche, avant).
3. Que ce soit utile ou non dans ce contexte (comme vous l'aviez considérer au dernier numéro des questions d'analyse), voici quand même une version de ce programme écrit comme une machine à états finis (MEF/FSM) dans le but de vous fournir une autre variante en exemple : [night-vacuum-fsm.zip](./code/platformio/night-vacuum-fsm-pio.zip). La machine a été conçue avec les états suivants :
   - `SETUP` : initialisation,
   - `IDLE` : immobile,
   - `ADVANCE` : avancer,
   - `AVOID_RIGHT` : reculer et tourner à gauche,
   - `AVOID_LEFT` : reculer et tourner à droite,
   - `AVOID_FRONT` : reculer et tourner plus de 90 degrés (p. ex. 120)

   1. Lisez le code et identifiez les transitions entre les états. Les écrire sous forme d'un tableau avec les colonnes `état actuel`, `condition de transition`, `état suivant` est une bonne façon d'organiser ces informations. 
      > Dans le code, on reconnaît une transition quand on assigne un nouvel état à la variable `currentState`.
   2. Est-ce qu'il y a un état final dans ce cas? Pourquoi ou pourquoi pas?
   3. Avec l'extension draw.io dans VS Code, produire le diagramme d'états pour cette machine à états finis. Vous pouvez l'enregistrez dans le dossier `/src` de votre projet.
   4. Pour chaque état d'évitement d'obstacle il y a deux mouvements à faire, chacun avec leurs propres délais, alors la condition avec les `millis()` n'est pas juste un `if-else` mais plutôt un	`if-else if-else`, utilisant le premier délai dans le premier `if` et le deuxième délai dans le deuxième `if`. Lisez comment les conditions pour chaque `if` sont structurées et expliquez comment ils fonctionnent.
   5. Regardez comment le temps est géré dans le code pour l'utilisation de `millis()`. Le temps de référence, stocké dans la variable `start`, est une donnée globale utilisée et manipulée dans les fonctions de plusieurs états. Ceci est différent des exemples de clignotement et de dance qu'on a vus précédemment où le délai était indépendant du reste du programme et utilisé exclusivement dans le code pour la lumière ou les roues. Lisez le code pour répondre à ces questions :
      1. Dans quel état est-ce qu'on réinitialise le temps de référence?
      2. Dans quels états est-ce qu'on utilise le temps de référence pour calculer le temps écoulé?
      3. Au lieu de modifier le temps de référence dans leur bloc `else`, ces états font quoi?


### Application : balayeuse-compteur

> _[Instructions générales](#instructions)_

Code de démarrage : CountingVacuum -> ...

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N.

#### Questions d'analyse

#### Modifications au code
