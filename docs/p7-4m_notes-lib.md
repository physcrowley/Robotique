[Accueil](./index.md) > [4M](./acceuil4M.md#projet-7--mouvement-avec-mission)

# 📚 Notes - Créer ses propres bibliothèques Arduino

> Ces notes s'adressent spécifiquement à la structure de projet PlatformIO. _Pour Arduino IDE, la même approche est valide, mais on place les fichiers `.h` et `.cpp` dans le même dossier que le projet `.ino`._

## Survol

On peut créer du code qui est utile dans plusieurs projets. Au lieu de le copier-coller à chaque fois, on peut le mettre dans une bibliothèque. Cela nous permet de réutiliser le code plus facilement et de le partager avec d'autres personnes. Ça garde aussi le code unique du nouveau projet plus propre en gardant le code commun dans d'autres fichiers.

### Objectifs d'apprentissage

Vous devrez être capable de :

- Expliquer la différence entre un fichier d'en-tête et un fichier source.
- Décrire où placer les fichiers d'une bibliothèque personnalisée dans un projet PlatformIO.
- Expliquer la différence entre déclarer une fonction et définir une fonction.

### Critères de succès

- Je suis capable de créer des bibliothèques personnelles pour le code que j'utilise dans plusieurs projets afin de me sauver du temps et rendre le code du projet plus facile à lire.

### Vocabulaire

**header file** (fichier d'en-tête) : un fichier avec l'extension `.h` qui contient les **déclarations** des fonctions. C'est ce fichier qui est importé avec la directive `#include` dans d'autres fichiers et permet à ce code de savoir ce qui est disponible dans la bibliothèque.

**source file** (fichier source) : un fichier avec l'extension `.cpp` qui **définit** les fonctions qui sont déclarées dans le fichier d'en-tête de la bibliothèque. Le fichier principal du programme, souvent `main.cpp`, est aussi un fichier source.

**`lib`** : sous-dossier du projet PlatformIO où on place les bibliothèques personnalisées, soit des dossiers contenant des fichiers .h et .cpp.

**déclaration** : la signature d'une fonction sans sons corps. Une signature inclut :

- le type de retour,
- le nom et
- les paramètres entre parenthèses `()`, et
- elles se terminent avec `;` _(pas un corps `{}`)_

Des déclarations se trouvent dans un fichier d'en-tête mais peuvent aussi se trouver dans un fichier source si les fonctions sont définies après leur première utilisation (p. ex. on utilise une fonction dans `loop()` mais on le définit après `loop()` -> ça prend une déclaration avant `loop()`).

**définition** : le code qui implémente une fonction, incluant sa signature et le corps de la fonction. Le corps est la paire de `{}` avec toutes les instructions qu'on écrit entre ces accolades.

## Créer une bibliothèque

> Suivre ces instructions dans votre plus récent projet PlatformIO, soit le projet `forward-movement`.

Selon le fichier README inclut dans le dossier `lib` de votre projet PlatformIO, voici la structure la plus simple pour une bibliothèque personnelle (nommée `Foo` dans cet exemple) :

```
Project
|-- ...
|-- lib
|   `-- Foo
|       |-- Foo.h
|       `-- Foo.cpp
|-- ...
```

et le fichier `src/main.cpp` qui utilise la bibliothèque `Foo` inclut alors le fichier d'en-tête de la bibliothèque :

```cpp
#include <Arduino.h>
#include <Foo.h>

//...
```

Alors, ce qu'il faut faire est :

1. Créer un dossier pour notre bibliothèque. Le nom ne peut pas contenir des espaces ou des caractères spéciaux et commence généralement avec une majuscule.
1. Dans ce dossier, on crée un fichier `.h` pour les déclarations et un fichier `.cpp` pour les définitions, les deux ayant le même nom que le dossier.
1. On place ce dossier dans le sous-dossier `lib` du projet PlatformIO, s'il n'est pas déjà là.

## Créer la bibliothèque `RobotDrive`

Plaçons le code pour contrôler les moteurs de notre robot à entraînement différentiel dans une bibliothèque nommée `RobotDrive`. Voici la structure de fichiers pour cette bibliothèque :

```
Project
|-- ...
|-- lib
|   `-- RobotDrive
|       |-- RobotDrive.h
|       `-- RobotDrive.cpp
|-- ...
```

### RobotDrive.h - le fichier d'en-tête

**`#ifndef` (if not defined)** : une directive qui vérifie si un symbole n'a pas été défini avant. Si ce n'est pas le cas, le code entre `#ifndef` et `#endif` est inclus. Cela permet d'éviter d'inclure plusieurs fois le même fichier d'en-tête, ce qui revient à copier-coller plusieurs fois les mêmes déclarations de fonctions générant des erreurs de compilation.

La structure d'un fichier `.h` est généralement la suivante :

```cpp
#ifndef NomDuFichier_h
#define NomDuFichier_h

// déclarations des fonctions

#endif
```

> **Note importante** : le `.h` devient `_h` dans les directives `#ifndef` et `#define`.

Spécifiquement pour `RobotDrive.h`, on a :

```cpp
#ifndef RobotDrive_h
#define RobotDrive_h

void setRobotDrivePins(int leftPin, int rightPin);
void stop();
void forward();
void backward();
void turnLeft();
void turnRight();

#endif
```

Notez qu'il n'y a aucun code ici, seulement les déclarations des fonctions.

### RobotDrive.cpp - le fichier de code source

Ce fichier ressemble plus à un programme Arduino standard, mais sans la fonction `setup()` et `loop()`. On inclut le fichier d'en-tête pour avoir accès aux déclarations des fonctions, et ensuite on définit ces fonctions.

Pour `RobotDrive.cpp`, on a :

```cpp
#include <Servo.h> // inclure la bibliothèque pour les Servo
#include <RobotDrive.h> // inclure notre bibliothèque

Servo leftMotor;
Servo rightMotor;

void setRobotDrivePins(int leftPin, int rightPin) {
    leftMotor.attach(leftPin);
    rightMotor.attach(rightPin);
}

void stop() {
    leftMotor.writeMicroseconds(1500);
    rightMotor.writeMicroseconds(1500);
}

void forward() {
    leftMotor.writeMicroseconds(1700);
    rightMotor.writeMicroseconds(1300);
}

void backward() {
    leftMotor.writeMicroseconds(1300);
    rightMotor.writeMicroseconds(1700);
}

void turnLeft() {
    leftMotor.writeMicroseconds(1300);
    rightMotor.writeMicroseconds(1300);
}

void turnRight() {
    leftMotor.writeMicroseconds(1700);
    rightMotor.writeMicroseconds(1700);
}
```

## Utiliser la bibliothèque `RobotDrive`

Maintenant, dans notre fichier `src/main.cpp`, on inclut le fichier d'en-tête de la bibliothèque `RobotDrive` :

```cpp
#include <Arduino.h>
#include <RobotDrive.h>

void setup() {
    setRobotDrivePins(10, 11);

    forward();
    delay(2000);
    stop();
    delay(1000);
    backward();
    delay(2000);
    stop();
    delay(1000);
    turnLeft();
    delay(2000);
    stop();
    delay(1000);
    turnRight();
    delay(2000);
    stop();
}

void loop() {} // ne fait rien
```

N'est-ce pas plus propre et plus facile à lire?

Et la prochaine fois que vous avez besoin de cette fonctionnalité, vous n'avez qu'à copier le dossier `RobotDrive` dans le dossier `lib` de votre nouveau projet.

### Accès aux variables dans le fichier source de la bibliothèque

Les variables déclarées dans le fichier source de la bibliothèque - comme `leftMotor` et `rightMotor` dans `RobotDrive.cpp` - **ne sont pas accessibles** dans le fichier principal `main.cpp`. Alors il faut faire attention à ce que les fonctions de la bibliothèque s'occupent de fournir toutes les manipulations nécessaires pour les variables internes, afin que le programme principal n'ait pas besoin de les utiliser directement.

> _Note : Inclure des variables accessibles à l'extérieur d'une bibliothèque dépasse le cadre de cette introduction. Mais c'est possible, notament en utilisant des classes._

## Créer une archive des bibliothèques personnelles

Afin de plus facilement réutiliser vos bibliothèques personnelles dans d'autres projets, vous pouvez :

1. Créer un nouveau dossier `libraries` à la racine de votre dossier `PlatformIO/Projects/`.
1. Copier votre dossier de bibliothèque, p. ex. le dossier `RobotDrive`, et le coller dans ce dossier `libraries`.
1. Ouvrir ce dossier dans votre espace de travail VS Code, via "File" > "Add Folder to Workspace...". Par la suite, votre dossier `libraries` sera visible quand vous travaillez dans d'autres projets.
1. Alors, vous pourrez simplement copier la bibliothèque voulu du dossier `libraries` et le coller dans le dossier `lib` de votre nouveau projet.

Ainsi, votre dossier `PlatformIO/Projects/` pourrait ressembler à ceci :

```plaintext
Projects
|-- libraries
|   |-- RobotDrive
|   |-- ...autres dossiers de bibliothèques personnelles
|-- Project1
|   |-- lib
|   |   |-- RobotDrive (copié de `libraries`)
|   |...autres dossiers et fichiers de projet
|...autres projets
```
