[Accueil](./index.md) > [3M](./accueil3M.md#projet-7--mouvement-avec-mission)

# Projet 2 : Éviter des obstacles

## Objectifs

1. Ajouter un capteur à la base robotique afin de lui donner l'autonomie d'éviter des obstacles.

## Instructions

1. Modifier la base robotique LEGO EV3 selon les instructions dans le tutoriel (lien ci-dessous).
1. Dans VS Code, **chaque membre du groupe** crée un nouveau projet EV3 nommé `avoidance`.
    > Assurez-vous d'ajuster les paramètres dans le fichier `.vscode/settings.json` pour bien bénéficier des outils de documentation et de complétion automatique.
1. Remplacer le code dans le fichier `main.py` du projet `avoidance` avec le code sur la page du tutoriel.
1. Exécuter le programme sur le robot et observer son comportement. Créer des barrières au besoin. **Chaque membre du groupe** devrait tester la connexion du robot avec son ordinateur et exécuter le programme pour valider qu'il a du code fonctionnel.

<a href="https://pybricks.com/ev3-micropython/examples/robot_educator_ultrasonic.html" target="_blank">Intructions pour la construction et code de démarrage - éviter les obstacles</a>

## 🤸‍♀️ Analyse du mouvement

1. Créez un document Google Docs nommé "Analyse - éviter" et le joindre à la tâche Google Classroom associée.
1. Partagez ce document avec votre partenaire de travail.
1. Écrivez un commentaire privé dans le Classroom pour indiquer qui est le propriétaire du document.
1. Répondez aux questions suivantes dans le document.

### Questions

1. Décrivez le comportement du robot lorsqu'il détecte un obstacle. 
1. Quelle est la distance minimale à laquelle il s'approche d'un obstacle détecté?
    1. en mm
    1. en cm
    1. en m
    > Si le robot bouge trop vite pour le mesurer, vous pouvez insérer la ligne `robot.stop(); wait(5000);` juste devant la ligne `robot.straight(-300)`. Cela arrêtera le robot pendant 5 secondes avant qu'il commence à reculer.

## 👓 Analyse du code

1. Continuez à travailler dans le document Google Docs "Analyse - éviter".
1. Répondez aux questions suivantes dans le document en consultant le code source du programme et les notes du cours.

### Questions

1. Quelles **variables** sont déclarées dans ce programme? Donne le nom de chaque variable.
1. Quels **objets pybricks** sont utilisés dans le programme? 
    1. Donne le type de chaque objet. _Indice : chacun est associé à une variable._
    1. Quel(s) objets sont nouveaux par rapport au dernier projet? À quoi servent-ils?
1. Quel type de structure de contrôle est utilisée quand on utilise le mot-clé `while`? _Indice : voir les notes dans cette section du cours_
1. Il y a deux endroits où on utilise `while` dans le programme. Le premier est `while True :` (à la ligne 45).
    1. À quelle ligne est-ce que ce bloc de code se termine?
    1. Qu'est-ce qui arrive une fois qu'on arrive à la fin de ce bloc de code?
    1. Quel est l'objectif de ce bloc de code? 
    1. Est-ce qu'il arrête de s'exécuter éventuellement? 
    1. Comment est-ce qu'on arrête le programme?
1. Pour le deuxième `while` (à la ligne 52)? 
    1. Quelle est la condition pour la boucle?
    1. Qu'est-ce que ça veut dire?
    1. Il y a une seule instruction dans ce while : `wait(10)` qui met en pause le programme pendant 10 millisecondes. Pourquoi on fait ça?
1. Quelle est la différence entre les commandes suivantes : `robot.drive()`, `robot.straight()` et `robot.turn()`?
    1. Quelles informations sont nécessaires pour chaque commande?
    1. Quelle est le comportement du robot pour chaque commande?

## ✏️ Modifications

Travaillez dans le code du programme pour appliquer les changements suivants à `main.py` :

1. Ajoutez un commentaire en-tête après la ligne `#!/usr/bin/env pybricks-micropython` pour indiquer **votre nom et la date de modification du programme**. Vous pouvez utiliser des commentaires de ligne `#` ou des commentaires multilignes `''' ... '''`.
1. Modifiez le programme pour que le robot détecte un obstacle à 200mm.
1. Modifiez le programme pour que le robot tourne de 135 degrés après avoir reculé.
1. Joindre le fichier `main.py` modifié à la tâche Google Classroom.
