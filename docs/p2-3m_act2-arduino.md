[Accueil](./index.md) > [3M](./accueil3M.md#projet-2--circuits-électroniques-et-programmation) > [Projet 2, Activité 2](./p2-3m_act2.md)

## Arduino IDE

Voici une courte vidéo de présentation de l'IDE :

<iframe width="560" height="315" src="https://www.youtube.com/embed/SX8z3-BEuWQ?si=h9XfN55hrJutm6g0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

La structure du projet avec cet IDE est un fichier `.ino` dans un dossier nommé comme le projet :

```
nom-du-projet
`--- nom-du-projet.ino
```

### Utiliser du code de démarrage

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
