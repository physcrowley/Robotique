[Accueil](./index.md) > [4M](./acceuil4M.md#projet-7--mouvement-avec-mission)

# 📚 Notes - la multi-tâche avec Arduino

## Introduction

Plusieurs programmes que nous avons vus jusqu'à présent utilisent la fonction `delay()` pour gérer le temps entre les différentes actions du robot. Cependànt, cette fonction bloque le programme pendant le temps spécifié, ce qui peut être problématique si le robot doit effectuer plusieurs tâches en même temps - comme lire des capteurs, contrôler des moteurs, clignoter des DEL. Dans ce cas, il est préférable d'utiliser une autre approche pour gérer le temps, notamment en utilisant la fonction `millis()`. Par contre, cette fonction vient avec une nouvelle logique de gestion des délais qui est important de comprendre.

## Exemple

Imagine un robot qui fait 3 tours à gauche et ensuite 3 tours à droite infiniment, sauf si la lumière s'éteint. À ce moment, il devrait arrêter de bouger.

> Note : le code de cet exemple utilise la bibliothèque `RobotDrive` qui résume les fonctions pour contrôler les moteurs que nous avons développés dans l'activité 1 de cette section.

### Avec `delay()`
Avec ce que nous avons vus jusqu'à présent, un exemple de code pour ce robot pourrait ressembler à ceci :

```cpp 
#include <Arduino.h>
#include <RobotDrive.h>

int millisForOneTurn = 2100; // à calibrer

int lightSensor = A3;
int lightThreshold = 50; // à calibrer

void setup() {
  setRobotDrivePins(10, 11);
  pinMode(lightSensor, INPUT);
}

void loop() {
    if (analogRead(lightSensor) > lightThreshold) {
        turnLeft();
        delay(millisForOneTurn * 3);
        turnRight();
        delay(millisForOneTurn * 3);
    } else {
        stop();
    }
}
```
