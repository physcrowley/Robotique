[Accueil](./index.md) > [3M](./acceuil3M.md)

# Projet 2, Activité 2 : Tutoriel de démarrage avec Arduino

[Détails pour Arduino IDE](#arduino-ide)   |   [Détails pour PlatformIO](#platformio)

Ce tutoriel présente les environnements de développement suivants :
* **Arduino IDE**, un environnement de développement intégré pour programmer des microcontrôleurs Arduino
* **PlatformIO**, une extension pour l'éditeur de code Visual Studio Code pour programmer une diversité de microcontrôleurs, incluant Arduino

Caractéristiques | Arduino IDE | PlatformIO
--- | --- | ---
Installation | [Télécharger](https://www.arduino.cc/en/software) le logiciel autonome | [Installer](https://docs.platformio.org/en/latest/ide/vscode.html) l'extension pour [Visual Studio Code](https://code.visualstudio.com/) _(🚧 L'installation complète de PlatformIO est impossible actuellement sur les G7 du local d'informatique)_
Avantages | Facile à créer un nouveau projet, interface utilisateur simplifiée | Connexion automatique avec la carte Arduino, meilleure assistance pour la programmation (VS Code), format de fichier standard (`.cpp`), fonctionne avec plusieurs platformes (pas juste Arduino)
Inconvénients | Pas de connexion automatique avec la carte Arduino, format de fichier spécial (`.ino`) | Structure de projet plus complexe (dossier `src` et fichier `platformio.ini`)

## Arduino IDE

Voici une courte vidéo de présentation de l'IDE :

<iframe width="560" height="315" src="https://www.youtube.com/embed/SX8z3-BEuWQ?si=h9XfN55hrJutm6g0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

La structure du projet avec cet IDE est un fichier `.ino` dans un dossier nommé comme le projet :

```
nom-du-projet
`--- nom-du-projet.ino
```

La plupart des tutoriels dans ce cours fournissent du code de démarrage dans un fichier compressé au format `.zip`. Il faut extraire le code dans le répertoire de projet par défaut d'Arduino, généralement `~/Documents/Arduino` où `~` est le répertoire personnel de l'utilisateur. Vous pouvez ensuite cliquer sur le fichier `.ino` pour ouvrir le projet dans Arduino IDE. Si ce fichier n'est pas déjà dans son propre dossier, l'IDE vous demandera de corriger la structure du projet et le fera automatiquement si vous acceptez.

### Ajouter des bibliothèques avec Arduino IDE

Si le projet nécessite une bibliothèque qui n'est pas déjà incluse dans l'IDE, vous pouvez l'ajouter en cliquant sur l'onglet _Bibliothèques_ et faire une recherche pour la bibliothèque requise. Vous pouvez ensuite l'installer en cliquant sur le bouton _Installer_. Parfois, un tutoriel fournira une bibliothèque spécifique à utiliser. Dans ce cas, vous pouvez l'ajouter en cliquant sur l'onglet _Croquis_ > _Inclure une bibliothèque_ > _Ajouter une bibliothèque ZIP..._ et en sélectionnant le fichier compressé au format `.zip`.

Les bibliothèques ajoutées de ces façons sont disponibles par la suite pour tous les projets.

### Convertir un projet PlatformIO vers Arduino IDE

Si vous voulez utiliser le code source `.cpp` d'un projet PlatformIO dans un projet Arduino IDE, voici les étapes pour le transfert :
* Créez une copie du fichier `main.cpp` (ou `nom-du-projet.cpp`) et renommez-la `nom-du-projet.ino`.
* Déplacer le fichier `.ino` dans le dossier du projet Arduino IDE, généralement `~/Documents/Arduino` où `~` est le répertoire personnel de l'utilisateur.
* Ouvrez le fichier `.ino` dans Arduino IDE et accepter la proposition de corriger la structure du projet.
* Si nécessaire, [ajoutez les bibliothèques requis](#ajouter-des-bibliothèques-avec-arduino-ide).

## PlatformIO

Voici une courte vidéo de présentation de l'extension :

<iframe width="560" height="315" src="https://www.youtube.com/embed/-2NhjhzFQsM?si=bw1FEXzkcbMJmqff&amp;start=127" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

La structure du projet avec cette extension est un dossier qui porte le nom du projet avec un sous-dossier `src` contenant le code du programme dans un fichier `.cpp` :

```
nom-du-projet
|--- include
|--- lib
|--- src
|    `--- main.cpp
|--- test
`--- platformio.ini
```

> Le code du projet peut être dans un fichier avec n'importe quel nom, mais il doit avoir l'extension `.cpp`. La seule restriction est qu'il n'y ait qu'un seul fichier dans le projet avec les fonctions Arduino standard `void setup()` et `void loop()`.

La plupart des tutoriels dans ce cours fournissent du code de démarrage dans un fichier compressé au format `.zip`. Il faut extraire le code dans le répertoire de projet par défaut de PlafortmIO, généralement `~/Documents/PlatformIO/Projects` où `~` est le répertoire personnel de l'utilisateur. Vous pouvez ensuite importer le projet dans VS Code à partir de la page d'accueil de PlatformIO (`PIO Home`) en cliquant sur le bouton :
*  _Import Arduino Project_ (avec l'option d'ajouter les bibliothèques d'Arduino IDE) ou 
* _Open Project_ (parce que le code de démarrage est déjà un projet PlatformIO).

Pour terminer dans les deux cas, sélectionnez le dossier du projet que vous venez d'extraire.

### Ajouter des bibliothèques avec PlatformIO

Si le projet nécessite une bibliothèque qui ne fait pas partie de la bibliothèque standard d'Arduino, vous pouvez l'ajouter en cliquant sur l'onglet _Libraries_ à la page d'accueil de PlatformIO et faire une recherche pour la bibliothèque requise. Vous pouvez ensuite l'installer en cliquant sur le bouton _Add to Project_ et en choisissant le projet auquel l'ajouter. Vous verrez alors une entrée dans le fichier `platformio.ini` qui fait référence à cette bibliothèque. 

Parfois, un tutoriel fournira une bibliothèque spécifique à utiliser. Vous pouvez l'extraire dans le dossier `lib` du projet. Dans les deux cas, le projet se compilera en incluant la bibliothèque.

Les bibliothèques ajoutées de ces façons sont seulement disponibles dans le projet actuel. Il faut donc gérer les bibliothèques projet-par-projet.

### Convertir un projet Arduino IDE vers un projet PlatformIO

Si vous voulez utliser des fichiers `.ino` dans un projet PlatformIO, voici les étapes pour le transfert :
* À la page d'accueil de PlatformIO, cliquez sur le bouton _New Project_ et choisissez un nom de projet et la carte Arduino Uno. 
* Copiez le code dans le fichier original `.ino` et le coller dans le fichier `./src/main.cpp` du nouveau projet PlatformIO. Ce code devrait entièrement remplacer le contenu de `main.cpp`.
* Ajouter l'instruction `#include <Arduino.h>` comme première ligne dans le fichier.
* Si nécessaire, [ajoutez les bibliothèques requis](#ajouter-des-bibliothèques-avec-platformio).


## Soumettre votre travail

Téléchargez le projet `Clignoter` à partir du [site public pour les exemples de code](https://physcrowley.github.io/TER-Arduino/). 

Capturez sur vidéo :
* l'écran de votre environnement de développement (Arduino IDE ou PlatformIO dans VS Code) **montrant le projet correctement compilé** et
* le résultat sur la carte Arduino connectée (le DEL intégé près de la broche 13 clignote)

Rendez la vidéo dans la tâche appropriée sur Google Classroom.



