[Accueil](./index.md) > [3M](./acceuil3M.md#projet-2--circuits-électroniques-et-programmation)

# Notes : programmation Arduino de base

Travailler avec un microcontrolleur veut dire remplacer de la logique électronique par une logique logicielle. Il faut alors apprendre comment programmer dans le langage de programmation du microcontrolleur. Pour la carte Arduino, le langage de programmation est une version simplifiée de C++.

Pour d'autres microcontrolleurs, le langage de programmation peut être différent. Par exemple, pour la brique EV3 (un microordinateur), le langage de programmation est une version simplifiée de Python.

Sauter directement à la section qui vous intéresse :
- [Démarrage](#démarrage)
  - [Commentaires dans le code C++](#commentaires-dans-le-code-c)
  - [Structure d'un programme Arduino](#structure-dun-programme-arduino)
  - [Ajouter des bibliothèques de code](#ajouter-des-bibliothèques-de-code)
  - [Constantes et variables](#constantes-et-variables)
    - [Syntaxe](#syntaxe)
    - [Types de données](#types-de-données)
  - [La fonction setup()](#la-fonction-setup)
    - [Définir le mode d'utilisation des broches](#définir-le-mode-dutilisation-des-broches)
    - [Démarrer la communication série](#démarrer-la-communication-série)
    - [Afficher des messages dans le moniteur série](#afficher-des-messages-dans-le-moniteur-série)
  - [La fonction loop()](#la-fonction-loop)
    - [Lire ou écrire une valeur sur une broche](#lire-ou-écrire-une-valeur-sur-une-broche)
- [Structures de contrôle](#structures-de-contrôle)
  - [Conditions](#conditions)
  - [La sélection](#la-sélection)
  - [La répétition](#la-répétition)

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

#### Afficher des messages dans le moniteur série

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


La fonction `loop()` est exécutée en boucle, jusqu'à ce que le microcontrolleur soit éteint. On l'utilise généralement pour lire les valeurs des composantes électroniques et pour envoyer des valeurs à d'autres composantes électroniques.

#### Lire ou écrire une valeur sur une broche

On utilise la fonction `digitalRead(broche)` pour lire une valeur d'une broche. La valeur lue est soit `HIGH` (équivalent à 1) ou `LOW` (équivalent à 0). On utilise la fonction `digitalWrite(broche, valeur)` pour envoyer une valeur à une broche. La valeur envoyée est encore soit `HIGH` ou `LOW`.

```cpp
// présumant que la DEL est connectée à la broche 12 et activité en mode OUTPUT,
// le code suivant fait clignoter la DEL
void loop() {
  digitalWrite(DEL, HIGH); // allumer la DEL
  delay(1000); // attendre 1 seconde
  digitalWrite(DEL, LOW); // éteindre la DEL
  delay(1000); // attendre 1 seconde
}
```

Certains composants donnent ou utilisent une valeur analogique, soit une valeur qui se trouve dans un intervalle de valeurs permises. Des résistances variables (potentiomètres) ou des capteurs de distance fournissent des valeurs analogiques. Des moteurs reçoivent des valeurs analogiques pour ajuster leur position ou leur vitesse. Pour lire une valeur analogique, on utilise la fonction `analogRead(broche)`. Pour envoyer une valeur analogique, on utilise la fonction `analogWrite(broche, valeur)`. La broche doit être compatible avec la fonction `analogWrite()` pour envoyer une valeur analogique. Ces broches sur la carte Arduino Uno sont soit des broches numériques précédés d'un `~` (3, 5, 6, 9, 10 et 11) ou des broches spéciales (A0 à A5).

```cpp
const int DEL = 9; // la DEL est connectée à la broche 9
const int capteur = A0; // un capteur est connecté à la broche A0

void setup() {
  pinMode(DEL, OUTPUT); // la broche DEL est utilisée pour envoyer une valeur à une vraie DEL
  pinMode(capteur, INPUT); // la broche capteur est utilisée pour lire une valeur 
}

void loop() {
  int valeur = analogRead(capteur); // lire la valeur du capteur
  analogWrite(DEL, valeur / 4); // ajuster la luminosité de la DEL selon la valeur lue
}
```

En robotique, c'est dans la fonction `loop()` qu'on met le code pour contrôler les moteurs, lire les capteurs et prendre des décisions basées sur les valeurs lues, notamment décider si on a atteint un objectif ou si on doit changer de direction.

Pour faire ces choses, on utilise les structures de contrôle de la section suivante afin d'obtenir la logique désirée.

## Structures de contrôle

Les **structures de contrôle** sont des instructions qui permettent de contrôler l'exécution du programme. On utilise des structures de contrôle pour prendre des décisions, répéter des actions ou exécuter des actions seulement si certaines conditions sont remplies.

Ces structures de contrôle existent dans tous les langages de programmation et sont essentielles pour écrire des programmes qui font des choses utiles. Les sections suivantes présentent la syntaxe C++ pour les structures de contrôle les plus communes, mais les concepts sont transférables aux autres langages.

### Conditions

Les **conditions** sont des expressions qui sont soit vraies ou fausses. On utilise des conditions pour prendre des décisions dans un programme. Les conditions sont souvent utilisées avec des structures de contrôle pour exécuter des actions seulement si certaines conditions sont remplies.

Par exemple, on peut voir si une valeur captée est plus grande (ou plus petite) qu'une valeur limite ou si une variable qui compte quelque chose à atteint une certaine valeur.

```cpp	
int valeur = 5;
Serial.println(valeur > 3); // affiche "1" (vrai) dans le moniteur série
Serial.println(valeur < 3); // affiche "0" (faux) dans le moniteur série
```

```cpp
int compteur = 0;
compteur++; // ajoute 1 à la valeur de compteur
Serial.print("Le compteur est à ");
Serial.println(compteur); // affiche "Le compteur est à 1" dans le moniteur série
Serial.println(compteur == 5); // affiche "0" (faux) dans le moniteur série
```

Les conditions sont souvent exprimées en utilisant des opérateurs de comparaison. Voici quelques exemples d'opérateurs de comparaison :

- `==` pour égal
- `!=` pour différent
- `>` pour plus grand
- `<` pour plus petit
- `>=` pour plus grand ou égal
- `<=` pour plus petit ou égal

On peut aussi combiner des conditions en utilisant des opérateurs logiques. Voici quelques exemples d'opérateurs logiques :

- `&&` pour ET
- `||` pour OU
- `!` pour NON (ou l'inverse)

### La sélection

La sélection nous permet d'écrire du code qui s'exécute seulement si une condition est vraie. On peut optionnellement écrire du code qui s'exécute si la condition est fausse. On utilise la structure `if` pour faire une sélection simple et la structure `if...else` pour faire une sélection avec une alternative. Voici la syntaxe de base :

```cpp
if (condition) {
  // code qui s'exécute si la condition est vraie
} else {
  // code qui s'exécute si la condition est fausse
}
```
où `condition` est remplacée par une expression écrite comme expliqué dans la section précédente.

Voici un exemple considérant une lecture qui vient d'un capteur quelconque :

```cpp
const int DEL = 12;
const int capteur = A0;

void setup() {
  pinMode(DEL, OUTPUT);
  pinMode(capteur, INPUT);
}

void loop() {
  int valeur = analogRead(capteur);
  
  if (valeur > 500) {
    // si la valeur est plus grande que 500 fait ceci
    digitalWrite(DEL, HIGH);
  } else {
    // sinon fait cela
    digitalWrite(DEL, LOW);
  }
}
```

### La répétition

🚧 en développement

La répétition nous permet d'écrire du code qui s'exécute plusieurs fois. On utilise la structure `for` pour répéter une action un nombre fixe de fois et la structure `while` pour répéter une action tant qu'une condition est vraie.


## Ressources additionnelles

Une explication de comment le programme Arduino fonctionne se trouve sur ce site. Dans ce tutoriel, le DEL est connecté à la broche 12 :
1. [Explication des bases avec un exemple sans DEL](https://nboulaire.developpez.com/tutoriels/Arduino/cours-debuter-programmation-arduino/#LIII-A)
1. [Explication de l'exemple pour clignoter un DEL sur la broche 12](https://nboulaire.developpez.com/tutoriels/Arduino/cours-debuter-programmation-arduino/#LIII-D-4)

> Si vous cherchez une explication alternative, vous pouvez consulter ce site pour une explication du code pour clignoter un DEL. Dans ce tutoriel, le DEL est connecté à la carte Arduino sur la broche 2 : [Zeste du Savoir](https://zestedesavoir.com/tutoriels/686/arduino-premiers-pas-en-informatique-embarquee/743_gestion-des-entrees-sorties/3420_notre-premier-programme/#allumer-notre-led)