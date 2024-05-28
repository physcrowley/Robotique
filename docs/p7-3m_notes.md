[Accueil](./index.md) > [3M](./acceuil3M.md#projet-7--mouvement-avec-mission)

# Notes : Programmer avec ev3-micropython

La plupart de ces notes s'appliquent au langage Python en général et peuvent être utilisées dans d'autres contextes de programmation aussi.

Seulement les notes sur les objets de la bibliothèque `pybricks` sont spécifiques à la programmation de l'EV3.

- [Notes : Programmer avec ev3-micropython](#notes--programmer-avec-ev3-micropython)
  - [Informations dans un programme](#informations-dans-un-programme)
    - [Pratique](#pratique)
  - [Calculs](#calculs)
    - [Pratique](#pratique-1)
  - [Comparaisons logiques avec Python](#comparaisons-logiques-avec-python)
    - [Pratique](#pratique-2)
  - [Sélection](#sélection)
    - [Pratique](#pratique-3)
  - [Répétition](#répétition)
    - [Pratique](#pratique-4)
  - [Bibliothèque `pybricks`](#bibliothèque-pybricks)
    - [Pratique](#pratique-5)
  - [Fonctions](#fonctions)
    - [Pratique](#pratique-6)


## Informations dans un programme

**instruction** : chaque ligne de code dans un programme Python représente une seule instruction. Les instructions sont exécutées une à la fois, de haut en bas, dans l'ordre où elles apparaissent dans le programme. Il y a des structures de contrôle qui modifie l'ordre d'exécution, mais on les verra plus tard.

**valeur littérale** : des valeurs numériques ou du texte que vous écrivez entre guillemets `""` ou apostrophes `''`. Par exemple, `5` est une valeur littérale numérique et `'Bonjour'` est une valeur littérale de texte.

**variable** : des noms que vous donnez à différentes valeurs afin de faire **référence** à ces valeurs plus tard dans votre programme. Tout texte qui n'est pas entre guillemets ou apostrophes est considéré comme un nom de variable (ou de fonction).

**assignation** : l'action d'associer une valeur à un nom de varable. Par exemple, `x = 5` assigne la valeur `5` à la variable `x`.

**fonction** : un bloc de code qui effectue une tâche spécifique et qui peut produire une valeur pour le programme, ce qui s'appelle sa **valeur de retour**. On peut assigner la valeur de retour à une variable. On **appelle** une fonction en écrivant son nom suivi de parenthèses. Par exemple, `print('Bonjour')` appelle la fonction `print()` avec le texte `'Bonjour'` comme argument.

**commentaires** : des notes que vous ajoutez à votre programme pour expliquer ce que fait le code. Les commentaires sont ignorés par l'ordinateur lors de l'exécution du programme. Dans Python, les commentaires commencent par le symbole `#` et s'arrêtent à la fin de la ligne. On peut aussi utiliser des commentaires multilignes en entourant le texte avec trois guillemets `""" ... """`.

**affichage** : écrire des messages à l'écran de l'ordinateur. Les valeurs dans votre programme sont stockées en mémoire, alors pour savoir ce qu'ils sont, on doit demander de les voir. Dans Python, vous pouvez afficher des messages avec la fonction `print()` et placer votre message entre les parenthèses. Le message peut être du texte entre guillemets, des variables, des valeurs littérales ou une combinaison de ces éléments. C'est pratique pour détecter des erreurs dans votre programme.

### Pratique

> Travaillez dans VS Code pour ces exercices. Vous devrez avoir installé Python, pybricks et les extensions associées comme décrit dans [les notes précédentes](./p1-3m_act3.md#vérification-automatisée-du-code-python-et-son-module-pybricks)

1. Créer un sous-dossier nommé `pratique` dans votre dossier "Documents".
1. Ouvrez ce dossier dans VS Code via "File" > "Open Folder".
1. Dans VS Code, créez un nouveau fichier Python nommé `data.py` dans ce dossier utilisant le bouton "New File" à côté du nom du dossier.
1. Ajoutez le code suivant dans le fichier `data.py`. 
    > _Si le copier-coller semble vous donner des erreurs d'indentation, vous pouvez télécharger une copie du code ici : [data.py](./code/python/data.py)_

    ```python
    # le commentaire suivant est un format typique d'en-tête de programme
    """
    Fichier : data.py
    Date : 11 mai 2024
    Auteur : David Crowley
    Description : Ce programme explore l'utilisation de variables en Python
    """

    # Assigner des valeurs à des variables
    nom = 'Alice'
    age = 16
    taille = 1.45 # en mètres

    # Afficher les valeurs des variables
    print('Nom:', nom)
    print('Age:', age)
    print('Taille:', taille)

    """
    Réponses aux questions :

    """
    ```

1. Enregistrez le fichier en cliquant sur "File" > "Save" ou en utilisant le raccourci clavier `Ctrl` + `S`.
    > Vous pouvez aussi activer l'enregistrement automatique dans VS Code en cliquant sur "File" > "Auto Save".
1. Exécutez le programme en cliquant sur le bouton "Run" en haut à droite de l'éditeur de texte. Vous verrez le résultat dans le terminal de VS Code.
1. Ajoutez vos réponses à ces questions dans le commentaire `Réponses aux questions` :
    1. Il y a combien de lignes dans ce qui est affiché à l'écran durant l'exécution du programme? Ces messages correspondent à quels numéros de ligne dans votre programme?
    1. Est-ce que le premier message affiché est `Nom: nom` ou `Nom: Alice`? L'instruction est `print('Nom:', nom)`, alors qu'est-ce qui se passe avec la variable `nom`?
    1. Changez les valeurs des variables `nom`, `age` et `taille` pour vos propres informations. Lancer le programme pour voir les changements. Décrivez ce qui s'est passé.
    1. Coupez les lignes de code qui assignent les valeurs aux variables et collez-les à la fin du programme, après les `print` mais avant le commentaire `Réponses aux questions`. Lancez le programme maintenant. Ça plante et nous dit que le nom `nom` n'est pas défini. Qu'est-ce que ça nous dit à propos de l'ordre d'exécution des instructions dans un programme Python?

## Calculs

**opérateurs** : des symboles qui représentent des opérations mathématiques. Les opérateurs les plus communs sont `+` pour l'addition, `-` pour la soustraction, `*` pour la multiplication et `/` pour la division. Il y a aussi `**` pour l'exposant, `//` pour la division entière et `%` pour le reste de la division.

**fonctions mathématiques** : Python a des fonctions intégrées pour des opérations mathématiques plus complexes. Par exemple, `abs()` pour la valeur absolue, `round()` pour arrondir un nombre, `min()` et `max()` pour trouver le plus petit ou le plus grand nombre dans une liste.

### Pratique

1. Créez un nouveau fichier Python nommé `calculations.py` dans le dossier `pratique` et y coller ce code :
    >_Si le copier-coller semble vous donner des erreurs d'indentation, vous pouvez télécharger une copie du code ici : [calculations.py](./code/python/calculations.py)_

    ```python
    """
    Fichier : calculations.py
    Date : 11 mai 2024
    Auteur : David Crowley
    Description : Ce programme explore l'utilisation de calculs en Python
    """

    # Assigner des valeurs à des variables
    x = 5
    y = 3
    print('Valeurs de x et y:', x, y)

    # Afficher les résultats de calculs
    print('Somme:', x + y)
    print('Différence:', x - y)
    print('Produit:', x * y)
    print('Quotient:', x / y)
    print('Reste:', x % y)

    exponent = x ** y # garder le résultat du calcul dans une variable
    print('Exposant:', exponent)

    biggest = max(x, y) # garder le résultat d'une fonction dans une variable
    print('Max', biggest)
    ```

1. Enregistrez le fichier en cliquant sur "File" > "Save" ou en utilisant le raccourci clavier `Ctrl` + `S`.
    > Vous pouvez aussi activer l'enregistrement automatique dans VS Code en cliquant sur "File" > "Auto Save".
1. Exécutez le programme en cliquant sur le bouton "Run" en haut à droite de l'éditeur de texte. Vous verrez le résultat dans le terminal de VS Code.
1. Changez les valeurs de `x` et `y` pour des nombres de votre choix. Lancez le programme pour voir les changements.

## Comparaisons logiques avec Python

**opérateurs de comparaison** : des symboles qui comparent deux valeurs et retournent un résultat booléen (`True` ou `False`). Les opérateurs de comparaison les plus communs sont `==` pour l'égalité, `!=` pour la différence, `>` pour plus grand, `<` pour plus petit, `>=` pour plus grand ou égal et `<=` pour plus petit ou égal.

**opérateurs logiques** : des symboles qui combinent des comparaisons pour produire un résultat booléen. Les opérateurs logiques les plus communs sont `and` pour l'opération ET, `or` pour l'opération OU et `not` pour l'opération NON.

**mot-clé `in`** : un mot-clé qui vérifie si une valeur est dans une liste ou une chaîne de caractères et donne un résultat booléen. Par exemple, `5 in [1, 2, 3, 4, 5]` est `True` parce que `5` est dans la liste `[1, 2, 3, 4, 5]`.

### Pratique

1. Créer un nouveau fichier Python nommé `comparisons.py` dans le dossier `pratique` et y coller ce code :
    > _Si le copier-coller semble vous donner des erreurs d'indentation, vous pouvez télécharger une copie du code ici : [comparisons.py](./code/python/comparisons.py)_
    
    ```python
    """
    Fichier : comparisons.py
    Date : 11 mai 2024
    Auteur : David Crowley
    Description : Ce programme explore l'utilisation de comparaisons en Python
    """
    # Assigner des valeurs à des variables
    x = 5
    y = 3
    print('Valeurs de x et y:', x, y)

    # Comparer les valeurs
    print('x est égal à y:', x == y)
    print('x est différent de y:', x != y)
    print('x est plus grand que y:', x > y)
    print('x est plus petit que y:', x < y)
    print('x est plus grand ou égal à y:', x >= y)
    print('x est plus petit ou égal à y:', x <= y)

    # Comparer du texte
    nom = 'Alice'
    print('Le nom est Alice:', nom == 'Alice')
    print('Le nom est différent de Bob:', nom != 'Bob')

    # Comparer des valeurs dans une liste ou un texte
    values = [1, 2, 3, 4, 5]
    print(values)
    print('5 est dans la liste:', 5 in values)
    print('6 est dans la liste:', 6 in values)

    word = 'Bonjour'
    print(word)
    print('o est dans le mot:', 'o' in word)
    ```

1. Enregistrez le fichier en cliquant sur "File" > "Save" ou en utilisant le raccourci clavier `Ctrl` + `S`.
1. Exécutez le programme en cliquant sur le bouton "Run" en haut à droite de l'éditeur de texte. Vous verrez le résultat dans le terminal de VS Code.

## Sélection

**sélection** : une structure de contrôle qui permet au programme de faire un choix basé sur une condition.

**condition** : une expression qui est évaluée comme `True` ou `False`, comme les comparaisons logiques que nous avons vues plus tôt.

**indentation** : l'espacement au début des lignes. Python dépend de l'indentation pour savoir quelles lignes de code sont dans une structure de contrôle. _Les débutants brisent souvent leur code en changeant l'indentation par accident. FAITES ATTENTION!_

Voici la structure générale d'une sélection en Python :

```python
if condition :
    # code à exécuter si la condition est vraie
else :
    # code à exécuter si la condition est fausse

# code qui suit la sélection
```

S'il y a plusieurs conditions distinctes à vérifier, on peut utiliser `elif` (contraction de "else if") :

```python
if condition1 :
    # code à exécuter si la condition1 est vraie
elif condition2 :
    # code à exécuter si la condition2 est vraie
else:
    # code à exécuter si aucune des conditions précédentes n'est vraie
```

### Pratique

La pratique pour cette section se fera en analysant le code pour les exemples dans les activités avec l'EV3.

## Répétition

**boucle** : une structure de contrôle qui permet au programme de répéter une série d'instructions plusieurs fois.

**itération** : un passage à travers une boucle.

**mécanisme de contrôle** : la façon de contrôler la répétition, afin de quitter la boucle éventuellement. Ça peut être basé sur une **condition** dans la déclaration de la boucle ou dans une sélection dans le bloc de code de la boucle.

Voici la structure générale d'une boucle en Python :

```python
while condition :
    # code à répéter tant que la condition est vraie
    # aussi, un mécanisme de contrôle pour changer la condition

# code qui suit la boucle
```

### Pratique

La pratique pour cette section se fera en analysant le code pour les exemples dans les activités avec l'EV3.

## Bibliothèque `pybricks`

**module** : un fichier Python qui contient des fonctions et des classes. Les modules sont **importés** dans un programme pour utiliser leur contenu. Par exemple, `import pybricks.hubs` ajoute le code du fichier "./pybricks/hubs.py" au programme et `import random` ajoute le code du fichier "./random.py" au programme.

**classe** : du code qui définit un type d'objet. Les classes sont utilisées pour créer des objets qui ont des propriétés (variables) et des méthodes (fonctions) spécifiques. Par exemple, la classe `Motor` dans `pybricks.ev3devices.Motor` est une classe qui définit du code pour utiliser un moteur EV3.

**objet** : une variable dans notre code qui fait référence à une instance d'une classe. Par exemple, `left_motor = Motor(Port.A)` crée un objet `left_motor` qui est une instance de la classe `Motor` pour le moteur connecté au port A de la brique EV3.

**propriété** : une variable qui est définie dans une classe et qui est associée à un objet de cette classe. Par exemple, `left_motor.port` est une propriété de l'objet `left_motor` qui donne le port auquel le moteur est connecté.

**méthode** : une fonction qui est définie dans une classe et qui est appelée sur un objet de cette classe. Par exemple, `left_motor.run(500)` appelle la méthode `run()` sur l'objet `left_motor` pour faire tourner le moteur à 500 degrés par seconde.

### Pratique

La pratique pour cette section se fera en analysant le code pour les exemples dans les activités avec l'EV3.

## Fonctions

On peut définir nos propres fonctions en Python pour réutiliser du code ou pour organiser notre programme en parties plus petites et plus faciles à comprendre.

C'est un sujet qui dépasse le cadre d'un cours d'introduction à la robotique, mais c'est quand même très important pour la programmation en général.

Comme avec les variables, dans Python il faut déclarer une fonction avant de l'utiliser dans le programme. C'est d'ailleurs pourquoi les instructions `import` sont souvent au début d'un programme.

### Pratique

Si vous êtes intéressé à apprendre plus sur la déclaration de fonctions en Python, vous pouvez consulter [ce tutoriel les site w3schools](https://www.w3schools.com/python/python_functions.asp).
