[Accueil](./index.md) > [3M](./accueil3M.md#projet-2--circuits-électroniques-et-programmation)

# Projet 2 - Activité 4 : Feux de circulation

## Objectif

- Utiliser un sketch Arduino, des constantes, des variables, la fonction `millis()` ou `delay()` et des blocs conditionnels pour contrôler des DEL
- Optionnellement, intégrer un ou plusieurs capteurs pour influencer le comportment des DEL

## Matériel

- 1 carte Arduino Uno
- 1 fil USB pour relier la carte à l'ordinateur
- 1 DEL de chaque couleur : rouge, jaune, vert
- Pour chaque DEL, 1 résistance 220 ohms  
- 1 plaque d'essai
- fils de raccordement

### Matériel pour les fonctionnalités additionnelles

Vous pouvez aussi ajouter les composants suivants selon les fonctionnalités additionnelles que vous ajoutées à votre projet : DEL bleu (et résistance), bouton poussoir, capteur ultrason HR-S04.

## Instructions

- Contrôler l'allumage des DEL pour dupliquer la séquence des lumières à un feu de circulation, p. ex. : 10s vert, 2s jaune, 12s rouge.
- Ajouter au moins une des fonctionnalités dans la liste ci-dessous.

Votre processus doit être documenté dans une copie du <a href="https://docs.google.com/document/d/10qXbG6t7gSBiXH1rWh8tamR85JPlqGgy0t4OaY0Sv2M/view" target="_blank">journal de conception et de fabrication</a>. C'est ce document qui est évalué à la fin du projet.

#### Fonctionnalités additionnelles

- Imiter l'avertissement pour la traversée piétonnière en faisant clignoter un DEL bleu quand il reste 3s à la lumière rouge.
- Imiter le bouton de traversée piétonnière avec un bouton poussoir qui allume un DEL bleu pendant 3s avant l'allumage du DEL vert (l'effet du bouton se voit au bon moment dans la séquence des lumières)
- Imiter la détection de présence d'un véhicule avec un bouton poussoir : si le bouton poussoir n'est pas enfoncé dans les dernières secondes du feu rouge, la lumière reste rouge au lieu de changer selon la séquence prévue.
- Imiter la détection de présence d'un véhicule avec un capteur de distance : si aucun objet n'est détecté à moins de 20cm dans les dernières secondes du feu rouge, la lumière reste rouge au lieu de changer selon la séquence prévue.

### Schémas des circuits

Utiliser le montage des exercices précedents comme inspiration pour le montage du circuit pour ce projet.


## Soumettre le travail

Voir le Classroom pour les détails de soumission.
