[Accueil](./index.md) > [4M](./accueil4M.md#projet-2--circuits-électroniques-et-programmation)

# Projet 2 - Activité 4 : Indicateur de distance

## Objectif

- Intégrer le contrôle de différents capteurs et moteurs avec un programme Arduino, les bibliothèques appropriées et la fonction `map()`

## Matériel

- 1 carte Arduino Uno
- 1 fil USB pour relier la carte à l'ordinateur
- 1 capteur de distance à ultrasons HC-SR04
- 1 servomoteur SG90
- 1 plaque d'essai
- fils de raccordement
- carton / papier / ciseaux et ruban adhésif pour construire le cadran pour l'indicateur

### Matériel pour les fonctionnalités additionnelles

Vous pouvez aussi ajouter les composants suivants selon les fonctionnalités additionnelles que vous ajoutées à votre projet : DELs et résistances, bouton poussoir.

## Instructions

- Utiliser un servomoteur et un cadran gradué en carton comme indicateur de distance
- Il devrait avoir une position réservée pour le cas où il n'y a pas de lecture valide (lecture de 0) et une région pour les distances valides (de 5cm à au moins 250cm)


Votre processus doit être documenté dans une copie du <a href="https://docs.google.com/document/d/10qXbG6t7gSBiXH1rWh8tamR85JPlqGgy0t4OaY0Sv2M/view" target="_blank">journal de conception et de fabrication</a>. C'est ce document qui est évalué à la fin du projet.

#### Quelques remarques :

- Les bibliothèques `Servo.h` pour le moteur et `NewPing.h` pour le capteur de distance sont utiles.
- C'est important de calibrer votre moteur et votre capteur individuellement (trouver leurs valeurs limites) avant de les intégrer dans un plus grand programme. Vous pouvez utiliser des programmes existants pour ça.
- La fonction `map()` est utile pour convertir les valeurs d'un capteur en valeurs appropriés pour l'actionneur.
- Si vous ne simulez pas votre solution, vous devrez tout de même monter le circuit dans Tinkercad. Dans tous les cas, le circuit dans Tinkercad est la source de vos diagrammes du projet.

#### Fonctionnalités additionnelles

- Ajouter un bouton-poussoir au projet pour activer ou désactiver l'indicateur de distance. Diviser alors le cadran en trois zones : éteint, aucune lecture (hors de portée) et cadran gradué.
- Ajouter des indicateurs DEL pour complémenter les états éteint et/ou hors de portée


### Schémas des circuits

Utiliser le montage des exercices précedents comme inspiration pour le montage du circuit pour ce projet.

## À soumettre

Voir le Classroom pour les détails de soumission.
