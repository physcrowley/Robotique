[Accueil](./index.md) > [3M](./accueil3M.md#projet-1--inventaire-installation-et-tests-du-matériel-et-des-logiciels)

# Projet 1, Activité 3 : Installation logicielle et tests de connexion avec la brique EV3

## Objectif

- Installer et configurer les logiciels nécessaires pour programmer la brique EV3 avec Python.
- Tester la connexion entre la brique EV3 et l'ordinateur.

## Préparer et tester la brique - Image EV3DEV

Cette image est un système d'exploitation alternative pour la brique EV3. Elle vous permet de progammer la brique avec des langages de programmation modernes comme Python.

1. Obtenir une carte microSD de l'enseignant.
1. Suivre <a href="https://docs.google.com/document/d/12S0q2qnkA0hj6m2gmTn4qhQcznP-quQ0ol4m0WgKlv4/view" target="_blank">ces instructions pour tester l'image de la carte</a>.

## Préparer et tester l'environnement de développement

### VS Code et extensions nécessaires

Ce logiciel est votre éditeur de code. Avec les extensions suggérées, il devient un environnement de développement intégré (IDE) pour la programmation de la brique EV3.

1. Installer **VS Code** sur votre ordinateur. Vous pouvez obtenir l'installateur à partir de <a href="https://code.visualstudio.com/" target="_blank">https://code.visualstudio.com/</a>.
1. Ajouter l'extension _LEGO MINDSTORMS EV3_ de LEGO Education à votre installation de VS Code. Vous pouvez la trouver dans l'onglet Extensions de VS Code. Cette extension ajoute également _EV3 Device Browser_ à votre ordinateur, ce qui vous permet de vous connecter à la brique EV3.
1. Ajouter l'extension _Python_ à votre installation de VS Code. Vous pouvez la trouver dans l'onglet Extensions de VS Code. C'est elle qui analyse votre code pour des erreurs.

## Vérification automatisée du code Python et son module pybricks

VS Code essaiera de signaler les erreurs dans vos programmes avec l'extension Python. Pour bien faire ce travail, il a besoin de connaître les fonctions et les classes disponibles dans le module _pybricks_, soit les objets que vous utilisez pour programmer la brique EV3 en Python.

1. Installer **Python** sur votre compte (sans droits d'administrateur). Vous pouvez obtenir l'installateur à partir de <a href="https://www.python.org/" target="_blank">https://www.python.org/</a>.
   > Assurez vous de **décocher** la case _Use admin rights during installation_ parce que vous n'avez pas cette autorisation.
   > Assurez-vous de **cocher** la case _Add Python to PATH_ lors de l'installation. Cela permet à VS Code de trouver Python.
1. Ajouter la documentation _pybricks (version 2.0.0)_ à votre installation de Python.
   - Ouvrez un terminal dans VS Code (via le menu Terminal)
   - Exécutez la commande suivante :
     ```shell
     pip install pybricks<3
     ```

### Connexion avec la brique EV3

1. Suivre les étapes de dépannage de connexion dans le document <a href="https://docs.google.com/document/d/1LnTJR6cIUQQlo0-1DnkuxlnX-Cyz_5t5xbr6X3uP4eE/view" target="_blank">Dépannage de connexion avec la brique EV3</a> afin d'établir une connexion entre la brique EV3 et votre ordinateur.

### Test - créer un projet dans VS Code et le lancer sur la brique EV3

1. Utilisez l'extension _LEGO MINDSTORMS EV3_ pour créer un nouveau projet Python dans VS Code nommé `test-ev3`. Enregistez le projet dans votre dossier Documents. Le fichier _main.py_ est créé automatiquement et contient le code à tester.
1. Activez la vérification des erreurs pour votre projet.
   - Ouvrez le dossier _.vscode_ dans votre projet.
   - Ouvrez le fichier _settings.json_.
   - Changez les dernières lignes pour qu'elles ressemblent à ceci:
     ```json
     "python.linting.enabled": true,
     "python.languageServer": "Default"
     ```
     > ces valeurs remplacent `false` et `"None"`.
   - Dans le fichier _main.py_, en bougeant le curseur sur les différents éléments, vous devrez voir des bulles d'information apparaître. Cela indique que l'analyseur de code fonctionne.
1. Connectez la brique EV3 à votre ordinateur avec un câble USB et utilisez _EV3 Device Browser_ pour établir une connexion.
1. Exécutez le programme en cliquant sur l'onglet _Run and Debug_ dans VS Code (icone qui combine un triangle et un insecte). En haut du panneau, vous verrez un bouton vert _Run_ à côté du texte "Download and Run". Cliquez sur ce bouton pour envoyer le code vers la brique EV3 et pour dire à la brique de l'exécuter immédiatement.
   > Des informations sur l'état du programme apparaîtront dans le terminal de VS Code et l'écran de la brique EV3 affichera un icône de bouton _Run_.
1. Si le programme fait un son et s'arrête tout seul, c'est une réussite. Le code inclut seulement l'instruction `ev3.speaker.beep()` qui utilise le haut-parleur de la brique pour faire un son.
1. Vous pouvez maintenant éteindre la brique EV3 et la déconnecter de votre ordinateur.


## Soumettre le travail

Tirer une courte vidéo montrant l'exécution du programme sur la brique EV3 et ensuite votre écran d'ordinateur avec VS Code montrant le projet et les informations du lancement de projet au terminal. 

Soumettre cette vidéo dans la tâche appropriée sur Google Classroom.
