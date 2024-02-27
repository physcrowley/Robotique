[Accueil](./index.md) > [3M](./acceuil3M.md#projet-2--circuits-électroniques-et-programmation)

# Notes : programmation Arduino de base

Travailler avec un microcontrolleur veut dire remplacer de la logique électronique par une logique logicielle. Il faut alors apprendre comment programmer dans le langage de programmation du microcontrolleur. Pour la carte Arduino, le langage de programmation est une version simplifiée de C++.

Pour d'autres microcontrolleurs, le langage de programmation peut être différent. Par exemple, pour la brique EV3 (un microordinateur), le langage de programmation est une version simplifiée de Python.

## Démarrage

### Commentaires dans le code C++

Les **commentaires** sont des lignes de texte qui ne sont pas exécutées par le microcontrolleur. Ils servent à expliquer le code pour les humains qui lisent le code. Les commentaires sont écrits en utilisant `//` pour un commentaire sur une seule ligne ou entre `/*` et `*/` pour un commentaire sur plusieurs lignes.

```cpp
// Ceci est un commentaire sur une seule ligne

/*
Ceci est un commentaire sur plusieurs lignes.

L'ordinateur ignore entièrement ces commentaires en compilant le programme.
*/
```

### Structure d'un programme Arduino

Un programme Arduino est composé de trois parties principales : définitions initiales, `setup()` et `loop()`. Les définitions initiales ajoutent des bibliothèques de code, au besoin, et nomme des constantes ou variables qu'on veut utiliser dans les deux autres parties du programme. La fonction `setup()` est exécutée une seule fois, au début du programme. La fonction `loop()` est exécutée en boucle, jusqu'à ce que le microcontrolleur soit éteint.

```cpp
/*
 Définitions initiales
*/
#include <Arduino.h> // ajout du code de base pour les projets Arduino

const int DEL = 12; // définition d'une constante

void setup() {
  // code qui se lance une seule fois, au début de programme
}

void loop() {
  // code qui se répète indéfiniment
}
```

### Ajouter des bibliothèques de code

Les **bibliothèques de code** sont du code déjà écrit qui peuvent être incluses dans un programme pour ajouter des fonctionnalités. Par exemple, la bibliothèque `Servo` est utilisée pour contrôler des servomoteurs. Pour ajouter une bibliothèque de code, on utilise la commande `#include` suivie du nom de la bibliothèque.

```cpp
#include <Servo.h> // ajout de la bibliothèque de code pour contrôler des servomoteurs
```

> La bibliothèque `Arduino` est ajouté automatiquement par l'EDI Arduino, mais on peut toujours l'inclure explicitement avec `#include <Arduino.h>`. Cette déclaration est d'ailleurs nécessaire avec les autres environnements de développement comme PlatformIO.

### Constantes et variables

Une **constante** est une valeur utile qui ne changera pas durant l'exécution du programme. Les broches utilisées pour connecter les différentes composantes électroniques à la carte Arduino sont souvent définies comme des constantes. 

Une **variable** est une valeur qui peut changer durant l'exécution du programme. Par exemple, une variable peut être utilisée pour compter le nombre de fois qu'un bouton a été appuyé. Une autre variable peut être utilisée pour stocker la valeur d'un capteur de distance ou pour l'état actuel du programme.

#### Syntaxe

Voici la syntaxe pour définir une constante ou une variable en C++ :

```cpp
const [type] [nom] = [valeur]; // pour une constante
[type] [nom] = [valeur]; // pour une variable
```
    
Il faut remplacer `[type]` par le type de donnée, `[nom]` par un nom descriptif et `[valeur]` par une valeur du type déclaré. Finalement, l'instruction se termine par un point-virgule, `;`, comme toutes les instructions en C++ (et dans plusieurs autres langages comme Java, Javascript et C#). Le mot-clé `const` dit au compilateur que cette valeur ne changera pas durant l'exécution du programme. C'est ce qui distingue une constante d'une variable.

Voici quelques exemples :

```cpp
const int DEL = 12;
int state = LOW; // LOW est une constante définie dans la bibliothèque Arduino (équivalent à 0)
```

Ce code est utilisé pour dire au programme qu'on a connecté une DEL sur la broche 12 et que son état (`state`)initial est éteint. La variable `state` peut changer durant l'exécution du programme (par exemple, à `HIGH` qui est égale à 1), mais la constante `DEL` ne changera pas.

#### Types de données

Il existe plusieurs types de données en C++, mais les plus communs dans nos programmes Arduino sont `int` pour les nombres entiers, `float` pour les nombres décimaux et `String` pour le texte.

Voici quelques exemples de déclarations de ces types de variables :

```cpp
int nombre = 5;
float decimale = 3.14;
String texte = "Bonjour!";
```

Notez que le texte doit être entre guillemets pour le distinguer des noms de variables.

### La fonction setup()

La fonction `setup()` est exécutée une seule fois, au début du programme. On l'utilise généralement pour définir l'utilité des broches et pour démarrer les communications entre la carte Arduino et l'ordinateur.

#### Définir le mode d'utilisation des broches

On utilise la fonction `pinMode(broche, mode)` pour définir le mode d'utilisation d'une broche. Le mode peut être `INPUT` pour lire une valeur d'une composante électronique ou `OUTPUT` pour envoyer une valeur à une composante électronique.

> Les constantes `INPUT` et `OUTPUT` sont définies dans la bibliothèque Arduino.

```cpp
const int DEL = 12;
void setup() {
  pinMode(DEL, OUTPUT); // la broche DEL est utilisée pour envoyer une valeur à une vraie DEL
}
```

#### Démarrer la communication série

On utilise la fonction `Serial.begin(vitesse)` pour démarrer la communication série entre la carte Arduino et l'ordinateur. La vitesse est mesurée en bauds (bits par seconde). La vitesse par défaut est 9600 bauds.

```cpp
void setup() {
  Serial.begin(9600); // démarrer la communication série à 9600 bauds
}
```

### Afficher des messages dans le moniteur série

On utilise la fonction `Serial.println(message)` pour afficher un message dans le moniteur série. Le message peut être un texte entre guillemets ou une variable. Dans le cas d'une variable, c'est sa valeur qui sera affichée.

```cpp
void setup() {
  Serial.begin(9600);
  Serial.println("Bonjour!");
}
```

On peut composer un message en incluant des bouts de phrase et des valeurs en utilisant la fonction `Serial.print(message)` pour chaque partie et terminer la ligne avec la fonction `Serial.println()`. Le `ln` dans le nom de la fonction veut "ligne" et indique que la fonction ajoute un retour à la ligne à la fin du message.

```cpp
const int DEL = 12;
void setup() {
  Serial.begin(9600);
  Serial.print("La DEL est connectée à la broche ");
  Serial.print(DEL);
  Serial.println(".");
}
```
affiche le message suivant dans le moniteur série :
```
La DEL est connectée à la broche 12.
```

### La fonction loop()


## Structures de contrôle

### La sélection


### La répétition



## Ressources additionnelles

Une explication de comment le programme Arduino fonctionne se trouve sur ce site. Dans ce tutoriel, le DEL est connecté à la broche 12 :
1. [Explication des bases avec un exemple sans DEL](https://nboulaire.developpez.com/tutoriels/Arduino/cours-debuter-programmation-arduino/#LIII-A)
1. [Explication de l'exemple pour clignoter un DEL sur la broche 12](https://nboulaire.developpez.com/tutoriels/Arduino/cours-debuter-programmation-arduino/#LIII-D-4)

> Si vous cherchez une explication alternative, vous pouvez consulter ce site pour une explication du code pour clignoter un DEL. Dans ce tutoriel, le DEL est connecté à la carte Arduino sur la broche 2 : [Zeste du Savoir](https://zestedesavoir.com/tutoriels/686/arduino-premiers-pas-en-informatique-embarquee/743_gestion-des-entrees-sorties/3420_notre-premier-programme/#allumer-notre-led)