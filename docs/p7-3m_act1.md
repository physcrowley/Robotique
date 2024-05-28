[Accueil](./index.md) > [3M](./acceuil3M.md#projet-7--mouvement-avec-mission)

# Projet 1 : Entraînement différentiel

## Objectifs

1. Monter une base robotique polyvalente.
1. Programmer le mouvement d'un robot en utilisant un entraînement différentiel (un moteur indépendant pour chaque roue).

## Instructions

1. Construire une base robotique LEGO EV3 avec des roues motrices et une roue folle selon les instructions sur le tutoriel (lien ci-dessous).
1. Dans VS Code, **chaque membre du groupe** crée un nouveau projet EV3 nommé `base`.
    > Assurez-vous d'ajuster les paramètres dans le fichier `.vscode/settings.json` pour bien bénéficier des outils de documentation et de complétion automatique.
1. Remplacer le code dans le fichier `main.py` du projet `base` avec le code sur la page du tutoriel.
1. Exécuter le programme sur le robot et observer son comportement. **Chaque membre du groupe** devrait tester la connexion du robot avec son ordinateur et exécuter le programme pour valider qu'il a du code fonctionnel.

<a href="https://pybricks.com/ev3-micropython/examples/robot_educator_basic.html" target="_blank">Intructions pour la construction et code de démarrage - mouvement de base</a>

## 🤸‍♀️ Analyse du mouvement

1. Créez un document Google Docs nommé "Analyse - base" et le joindre à la tâche Google Classroom associée.
1. Partagez ce document avec votre partenaire de travail.
1. Écrivez un commentaire privé dans le Classroom pour indiquer qui est le propriétaire du document.
1. Répondez aux questions suivantes dans le document.

### Questions

1. Quelle distance en cm représente un déplacement de 1000mm? Est-ce que le robot se déplace exactement de cette distance?
1. Combien de rotations complètes représentent un virage de 360 degrés? Est-ce que le robot tourne exactement de cette quantité?
1. Est-ce que le robot finit son mouvement à la même position et la même orientation que son état de départ? Si non, tenter d'expliquer pourquoi.
1. Faites les conversions suivantes pour les déplacements :
    1. 1 mètre (m) = combien de millimètres (mm)?
    1. 33cm = combien de millimètres (mm)?
    1. 250mm = combien de centimètres (cm)?
1. Faites les conversions suivantes pour les angles :
    1. 90 degrés = combien de rotations complètes?
    1. 2 tours complets = combien de degrés?
    1. 1/2 tour complet = combien de degrés?

## 👓 Analyse du code

1. Continuez à travailler dans le document Google Docs "Analyse - base".
1. Répondez aux questions suivantes dans le document en consultant le code source du programme et les notes du cours.

### Questions

1. Quelles **variables** sont déclarées dans le programme? Donne le nom de chaque variable.
1. Quels **objets pybricks** sont utilisés dans le programme? Donne le type de chaque objet. _Indice : chacun est associé à une variable._
1. Lisant la bulle d'information quand votre curseur est sur le mot `DriveBase`, décrivez ce que le paramètre `axle_track` représente.
1. Le programme pour contrôler le robot ne fait aucun calcul visible pour la distance ou l'angle de rotation. Ces calculs sont faits par l'objet `DriveBase`. Quelles informations sont utilisées par l'objet pour déterminer la distance et l'angle de rotation? _Indice : regarder les informations géométriques données en créant l'objet._
1. Quelle méthode est utilisée pour déplacer le le robot en ligne droite? Quelle valeur prend-elle en argument?
1. Quelle méthode est utilisée pour tourner le robot? Quelle valeur prend-elle en argument?

## ✏️ Modifications

Travaillez dans le code du programme pour appliquer les changements suivants à `main.py` :

1. Ajoutez un commentaire en-tête après la ligne `#!/usr/bin/env pybricks-micropython` pour indiquer **votre nom et la date de modification du programme**. Vous pouvez utiliser des commentaires de ligne `#` ou des commentaires multilignes `''' ... '''`.
1. Modifiez le programme pour que le robot se déplace de 500mm au lieu de 1000mm.
1. Modifiez le programme pour que le robot tourne de 180 degrés au lieu de 360 degrés.
1. Ajoutez un grand virage à gauche de 90 degrés en utilisant la méthode `robot.curve()`. En consultant la documentation (curseur sur le nom), vous pouvez voir les informations nécessaires pour utiliser cette méthode, notamment un rayon en mm et un angle en degrés.
    1. Ajoutez un commentaire de ligne (`#`) qui explique si le signe + ou - sur les degrés de rotation fait tourner le robot à gauche ou à droite.
1. Joindre le fichier `main.py` modifié à la tâche Google Classroom.
