[Accueil](./index.md) > [3M](./accueil3M.md#projet-2--circuits-électroniques-et-programmation) > [Projet 2, Activité 2](./p2-3m_act2.md)

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

### Utiliser du code de démarrage

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
