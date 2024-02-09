[Accueil](./index.md) > [3M](./acceuil3M.md)

## Projet 1, Activité 3 : Installation logicielle et tests de connexion avec la brique EV3

### VS Code
Ce logiciel est votre éditeur de code. Avec les extensions suggérées, il devient un environnement de développement intégré (IDE) pour la programmation de la brique EV3.

1. Installer **VS Code** sur votre ordinateur. Vous pouvez obtenir l'installateur à partir de [https://code.visualstudio.com/](https://code.visualstudio.com/).
1. Ajouter l'extension _LEGO MINDSTORMS EV3_ de LEGO Education à votre installation de VS Code. Vous pouvez la trouver dans l'onglet Extensions de VS Code. Cette extension ajoute également _EV3 Device Browser_ à votre ordinateur, ce qui vous permet de vous connecter à la brique EV3.

### Documentation Python
VS Code essaiera de signaler les erreurs dans vos programmes. Pour bien faire ce travail, il a besoin de connaître les fonctions et les classes disponibles dans le module _pybricks_, soit les objets que vous utilisez pour programmer la brique EV3 en Python.

1. Installer **Python** sur votre compte (sans droits d'administrateur). Vous pouvez obtenir l'installateur à partir de [https://www.python.org/](https://www.python.org/).
    > Assurez-vous de cocher la case _Add Python to PATH_ lors de l'installation.
1. Ajouter le module _pybricks_ à votre installation de Python. Ouvrez un terminal dans VS Code (via le menu Terminal) et exécutez la commande suivante :
    ```shell
    pip install git+https://github.com/pybricks/pybricks-api@master
    ```

### Connexion avec la brique EV3

1. Suivre les étapes de dépannage de connexion dans le document [Dépannage de connexion avec la brique EV3](https://docs.google.com/document/d/1LnTJR6cIUQQlo0-1DnkuxlnX-Cyz_5t5xbr6X3uP4eE/view) afin d'établir une connexion entre la brique EV3 et votre ordinateur.

### Premier programme

1. Utilisez l'extension _LEGO MINDSTORMS EV3_ pour créer un nouveau projet Python dans VS Code nommé `test-ev3`. Enregistez le projet dans votre dossier Documents. Le fichier _main.py_ est créé automatiquement dans le projet et contient le code à tester.
1. Créez votre espace de travail pour le cours. Un espace de travail est une référence vers tous les dossiers de projets. Vous pouvez le créer dans le menu _File_ > _Save Workspace As..._. Le mettre dans le dossier Documents et le nommer `robotique3m`. Si vous placez tous vos projets pour le cours dans cet espace de travail, vous aurez facilement accès à tous vos projets dans VS Code.
1. Connectez la brique EV3 à votre ordinateur avec un câble USB et utilisez _EV3 Device Browser_ pour établir une connexion.
1. Exécutez le programme en cliquant sur l'onglet _Run and Debug_ dans VS Code. En haut du panneau, vous verrez un bouton vert _Run_ à côté du texte "Download and Run". Cliquez sur ce bouton pour envoyer le code vers la brique EV3 et pour dire à la brique de l'exécuter immédiatement.
    > Des informations sur l'état du programme apparaîtront dans le terminal de VS Code et l'écran de la brique EV3 affichera un icône de bouton _Run_. Si vous cliquez le bon bouton sur la brique, elle émettra un son.
1. Arrêtez le programme en cliquant sur le bouton rouge _Stop_ dans VS Code ou sur le bouton _Back_ de la brique EV3.
