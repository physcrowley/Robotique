[Accueil](./index.md) > [4M](./acceuil4M.md#projet-7--mouvement-avec-mission)

# 📚 Notes : plusieurs tâches en parallèle (la multi-tâche) - synchroniser avec millis()

## Introduction

Plusieurs programmes que nous avons vus jusqu'à présent utilisent la fonction `delay()` pour gérer le temps entre les différentes actions du robot. Cependànt, cette fonction **bloque le programme** pendant le temps spécifié, ce qui peut être problématique si le robot doit effectuer plusieurs tâches en même temps - comme lire des capteurs, contrôler des moteurs, clignoter des DEL. Dans ce cas, il est préférable d'utiliser une autre approche pour gérer le temps, notamment en utilisant la fonction `millis()`. Par contre, cette fonction vient avec une nouvelle logique de gestion des délais qui est important de comprendre.

## En bref

**bloquer** : arrêter l'exécution du programme pour un certain temps, notamment avec `delay()`

**multi-tâche** : gérer plusieurs tâches en même temps. Avec certain matériel, c'est possible de lancer plusieurs fils d'exécution en parallèle (comme Scratch), mais il y a un seul fil d'exécution possible avec Arduino. Pour faire de la multi-tâche avec Arduino, on doit gérer les tâches en séquence tout en vérifier si c'est le moment de lancer une instruction spécifique.

**millis()** : fonction qui retourne le nombre de millisecondes écoulées depuis le démarrage du programme. On peut l'utiliser pour gérer les intervalles de temps sans bloquer le programme.

**variable locale** : variable déclarée à l'intérieur d'une fonction et qui n'est accessible que dans cette fonction. Elle est détruite à la fin de la fonction sauf si elle est déclarée `static`.

## Exemple - robot qui dance en tournant avec moustaches comme signal d'arrêt

Imagine un robot qui fait 3 tours à gauche et ensuite 3 tours à droite infiniment, sauf si une de ses moustaches est enfoncée. À ce moment, il devrait arrêter de bouger.

Présumant qu'on implémente le code pour ce comportement comme une machine à états finis, le diagramme d'états est plus complexe que l'exemple dans l'introduction aux FSM : il inclut une boucle (entre les états LEFT et RIGHT) et des embranchements (quand le capteur est enfoncé).

![diagramme d'états multi-tâche](./images/p7/fsm_multi.drawio.png)

## Solution avec `delay()`

Avec ce que nous avons vus jusqu'à présent, incluant la bibliothèque personnelle `RobotDrive`, un exemple de code pour le robot de l'exemple pourrait ressembler à ceci :

```cpp
#include <Arduino.h>
#include <RobotDrive.h>

/*
DÉFINIR LES CONNEXIONS MATÉRIELLES
*/

const int millisForOneTurn = 2100; // à calibrer; avec turnLeft() et turnRight()

const int rightWhisker = 7;
const int pressed = LOW; // ou 0

/*
DÉFINIR LES ÉTATS DU ROBOT
*/

enum class States {
  SETUP,
  LEFT,
  RIGHT,
  STOP
};

States currentState = States::SETUP;

void setup() {
  setRobotDrivePins(10, 11);
  pinMode(rightWhisker, INPUT);
  currentState = States::LEFT;
}

void loop() {
  /* LIRE LES CAPTEURS */
  if (digitalRead(rightWhisker) == pressed) {
    currentState = States::STOP;
  }

  /* GÉRER L'ÉTAT */
  switch (currentState) {
  case States::LEFT:
    turnLeft();
    delay(3 * millisForOneTurn);   // fait 3 tours à gauche
    currentState = States::RIGHT;  // change l'état
    break;
  case States::RIGHT:
    turnRight();
    delay(3 * millisForOneTurn);  // fait 3 tours à droite
    currentState = States::LEFT;  // change l'état
    break;
  case States::STOP:
    stop();                       // état final (pas de transition)
    break;
  }
}
```

### Analyse

1. Créer un nouveau projet PlatformIO nommé `multi-tasking`.
1. Configurez votre projet en lui ajoutant les bibliothèques nécessaires :
   1. Ajoutez la ligne suivante à son fichier `platformio.ini` : `lib_deps = arduino-libraries/Servo@^1.2.1` afin d'ajouter la bibliothèque externe `Servo` à votre projet.
   1. Copier le dossier `RobotDrive` de vos bibliothèques personnelles dans le dossier `lib` du projet.
1. Copiez le code ci-dessus dans le fichier `/src/main.cpp` et compilez-le pour vérifier qu'il n'y a pas d'erreurs de transcription.
1. Téléversez le code vers votre base robotique à entraînement différentiel et observez le comportement du robot.
1. Est-ce que vous pouvez fiablement arrêter le robot en enfonçant une moustache?
   - À quel moment est-ce que le robot semble réagir à l'enfoncement de la moustache?
   - Est-ce que le robot s'arrête avant de finir les 3 rotations à gauche ou à droite?
   - Si la moustache n'est pas enfoncée au moment de la transition entre les directions, est-ce que le contact influence le programme?

## Introduction à `millis()`

Avec la solution précédente, le problème est que le programme est bloqué durant chaque `delay()`. Notamment, la boucle `loop()` n'est pas en train de se répéter alors on n'arrive pas à l'instruction pour lire les capteurs. Si la moustache est enfoncée pendant un `delay()`, le robot n'est pas en mesure de le détecter.

La solution est de remplacer le code qui bloque le programme (`delay()`) par un code qui lui permet d'itérer en continu tout en respectant les délais voulus. Heureusement, il y a la fonction `millis()` qui nous donnne des lectures de chronomètre en millisecondes depuis le lancemement du programme.

La logique de base pour remplacer `delay()` par `millis()` est la suivante :

```
Est-ce la différence entre maintenant et le temps de référence est plus grande que le délai voulu?
    Si oui, faire la chose voulue et mettre à jour le temps de référence.
    Si non, fait rien.
```

Ça ne semble peut-être pas majeur comme changement, mais ce l'est! Le temps nécessaire pour passer à travers cette sélection est minime et le code suivant s'exécute immédiatement. Quand ce code se trouve dans une boucle, tout le code de la boucle a le temps de se répéter plusieurs fois avant que le délai soit atteint et la tâche voulue est exécutée.

On atteint alors la possibilité d'une vraie multi-tâche, où plusieurs tâches peuvent être gérées en même temps.

### Implémentation de base

Avec la syntaxe Arduino, l'algorithme général ci-dessus donne le code de base suivant :

```cpp
#include <Arduino.h>

const int waitTime = 3000; // 3 secondes, par exemple
unsigned long referenceTime = millis();

void setup() {}

void loop() {
  if (millis() - referenceTime >= waitTime) {
    // code pour la tâche voulue
    referenceTime = millis(); // mettre à jour le temps de référence
  }
}
```

- Notre temps de référence est de type `unsigned long` pour pouvoir contenir les valeurs de 0 à 4,294,967,295 (en millisecondes, c'est environ 50 jours). Un `unsigned int` ne suffirait pas pour des délais de plus de 65 secondes!
- L'appelle à `millis()` nous donne le temps actuel en millisecondes depuis le lancement du programme. On l'utilise chaque fois qu'on a besoin du temps (comme pour initialiser `referenceTime`, pour calculer la différence entre maintenant et `referenceTime` et pour réinitialiser `referenceTime`).

### Implémentation plus robuste

Parce que le code dans `loop()` peut devenir assez complexe avec plusieurs tâches, on tend à écrire une fonction spécifique pour chaque tâche. Cela nous donne la possibilité de gérer les variables liées au délai entièrement à l'intérieur de la fonction, ce qui rend le code plus lisible et plus facile à maintenir.

Voici l'exemple précédent réécrit avec une fonction pour la tâche :

```cpp
#include <Arduino.h>

void doTask(); // déclaration avancée de la fonction

void setup() {}

void loop() {
  doTask();
}

void doTask() {
  static const int waitTime = 3000; // 3 secondes, par exemple
  static unsigned long referenceTime = millis();

  if (millis() - referenceTime >= waitTime) {
    // code pour la tâche voulue
    referenceTime = millis(); // mettre à jour le temps de référence
  }
}
```

- Si on définit la fonction après `loop()`, on doit déclarer la fonction avant `loop()` pour que le compilateur sache qu'elle existe. C'est ce que fait la ligne `void doTask(); // déclaration avancée de la fonction`.
- Les variables `waitTime` et `referenceTime` sont maintenant des variables locales à la fonction `doTask()`. Elles sont `static` pour être :
    - déclarées et initialisées une seule fois : quand la fonction est initialement chargée en mémoire
    - conservées entre les appels de la fonction (contrairement à des variables locales normales qui sont détruites à la fin de la fonction)
- Pour ajouter des tâches supplémentaires, il suffit de copier-coller la fonction `doTask()` sans même changer les noms des varaibles internes à la fonction, soit les **variables locales**. Parce que ces variables sont seulement accessibles dans la fonction où elles sont déclarées, des variables avec le même nom dans différentes fonctions ne seront pas confondues.

#### Tester rapidement cette implémentation plus robuste

1. Créez un nouveau projet PlatformIO nommé `millis-test`.
1. Copiez le code ci-dessous dans le fichier `/src/main.cpp` et le transférez vers une carte Arduino (comme celle dans votre robot).
1. Vérifier que le DEL intégré clignote toutes les 0.5 secondes.

```cpp
#include <Arduino.h>

void blink();

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  blink();
}

void blink() {
  static const int waitTime = 500; 
  static unsigned long referenceTime = millis();

  if (millis() - referenceTime >= waitTime) {
    digitalWrite(13, !digitalRead(13));
    referenceTime = millis(); // mettre à jour le temps de référence
  }
}
```

> Notez l'astuce pour la ligne `digitalWrite(13, !digitalRead(13));` : `!` est l'opérateur de négation logique qui inverse la valeur d'une variable booléenne. Alors chaque fois qu'on passe sur cette instruction, on donne  au DEL (avec `digitalWrite`) l'état inverse de ce qu'il avait (obtenu avec `digitalRead`).

## Solution avec `millis()`

Revenant à l'exemple du robot qui dance en tournant avec moustaches comme signal d'arrêt, voici une solution qui utilise `millis()` pour gérer les délais :

```cpp
#include <Arduino.h>
#include <RobotDrive.h>

/*
DÉFINIR LES CONNEXIONS MATÉRIELLES
*/

const int rightWhisker = 7;
const int pressed = LOW; // ou 0

/*
DÉFINIR LES ÉTATS DU ROBOT
*/

enum class States {
  SETUP,
  LEFT,
  RIGHT,
  STOP
};

States currentState = States::SETUP;

/*
DÉCLARATIONS AVANCÉES
*/

void spin(States direction);

void setup() {
  setRobotDrivePins(10, 11);
  pinMode(rightWhisker, INPUT);
  turnLeft(); // initialise le mouvement
  currentState = States::LEFT;
}

void loop() {
  /* LIRE LES CAPTEURS */
  if (digitalRead(rightWhisker) == pressed) {
    currentState = States::STOP;
  }

  /* GÉRER L'ÉTAT */
  switch (currentState) {
  case States::LEFT:
    spin(currentState);
    currentState = States::RIGHT;
    break;
  case States::RIGHT:
    spin(currentState);
    currentState = States::LEFT;
    break;
  case States::STOP:
    stop();
    break;
  }
}

// change la direction de rotation à un délai fixe avec millis()
void spin(States direction) {
  static const int waitTime = 3 * 2100; // à calibrer avec turnLeft() et turnRight()
  static unsigned long referenceTime = millis();

  if (millis() - referenceTime >= waitTime) {
    if (direction == States::LEFT) {
      turnLeft();
    } else {
      turnRight();
    }
    referenceTime = millis(); // mettre à jour le temps de référence
  }
}
```

- La fonction `spin(States direction)` est utiliser pour `turnLeft()` et `turnRight()` et utilise l'état de la machine à états fini passé en argument pour choisir la bonne instruction de mouvment. Sinon, cette fonction est équivalente à la fonction `doTask()` de l'exemple précédent.
- Parce que notre fonction pour gérer les délais attend avant de donner une nouvelle instruction, il faut donner une première instruction de mouvement dans `setup()` pour initialiser le mouvement. Sinon il faudrait attendre le premier délai avant de voir le robot bouger.

### Analyse

1. Remplacer le code dans `/src/main.cpp` du projet `multi-tasking` que nous avons initialisé avec une solution utilisant `delay()` par le code ci-dessus.
1. Compilez le code pour vérifier qu'il n'y a pas d'erreurs de transcription.
1. Téléversez le code vers votre base robotique à entraînement différentiel et observez le comportement du robot.
1. Est-ce que vous pouvez maintenant fiablement arrêter le robot en enfonçant une moustache?
    - À quel moment est-ce que le robot semble réagir à l'enfoncement de la moustache?
    - Est-ce que le robot s'arrête avant de finir les 3 rotations à gauche ou à droite?
    - Si la moustache n'est pas enfoncée au moment de la transition entre les directions, est-ce que le contact influence le programme?
