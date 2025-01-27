[Accueil](./index.md) > [4M](./accueil4M.md#projet-7--mouvement-avec-mission)

# Projet 7 - Activité 1 : Entraînement différentiel

## Introduction

L'entrâinement différentiel est une méthode de contrôle de mouvement qui utilise des moteurs indépendants pour chaque roue d'un robot. Cela permet de contrôler la vitesse et la direction du robot en ajustant la vitesse des moteurs. Dans ce projet, vous allez construire une base robotique avec un entraînement différentiel et programmer le mouvement de base d'un robot en utilisant cette méthode.

## Objectifs

1. Monter une base robotique polyvalente.
1. Programmer le mouvement d'un robot en utilisant un entraînement différentiel (un moteur indépendant pour chaque roue).

## Instructions

1. Construire une base robotique Arduino ShieldBot avec des roues motrices et une roue folle selon les instructions sur le tutoriel (lien ci-dessous).
1. Suivre les tests et les observations mentionées dans le tutoriel pour vérifier que les moteurs sont bien connectés et fonctionnent correctement.
   > Remplacer le code de démarrage fourni dans les tutoriels par le code équivalent suivant. Le code ci-dessous est structuré pour un projet PlatformIO et inclut certains ajouts et modifications pour rendre votre code plus compréhensible et réutilisable. Télécharger et extraire le dossier .zip dans votre dossier `~/Documents/PlatformIO/Projects` et les ouvrir avec l'extension _PlatformIO_ dans VS Code.
   - TestMotors.ino -> [test-drive-motors.zip](./assets/code/platformio/test-drive-motors-pio.zip)
   - TestDriveMotors.ino -> [test-drive-differential.zip](./assets/code/platformio/test-drive-differential-pio.zip)
   - ForwardMovement.ino -> [forward-movement.zip](./assets/code/platformio/forward-movement-pio.zip)
        > Cette version crée des **fonctions** pour les mouvements de base. Vous êtes encouragé à programmer les autres mouvements décrits dans le tutoriel- reculer, tourner à gauche et tourner à droite - en créant vos propres fonctions suivant ces modèles.
1. Ajuster votre code selon les instructions dans le tutoriel.

<a href="https://www.cs2n.org/u/mp/badge_pages/195" target="_blank">Tutoriel - mouvement de base</a>

> _Page d'accueil de l'ensemble de ces tutoriels : <a href="https://www.cs2n.org/u/track_progress?id=290" target="_blank">CS2N - Bases logicielles avec Arduino</a>, pratique notamment pour une référence vers la vérification initiale du matériel_

## Analyses

1. Répondez à toutes les questions de validation de la compréhension sur le site.

## Modifications au code

1. Appliquez les modifications requises pour les activités du tutoriel.
1. Pour `Forward Movement`, créer des nouvelles fonctions pour chaque mouvement de base (reculer, tourner à gauche, tourner à droite) en suivant le modèle des fonctions `forward` et `stop`.
1. Créez un dossier compressé `.zip` qui contient tous les projets PlatformIO que vous avez produits pour ce tutoriel et le joindre à la tâche Google Classroom associée. Il devrait seulement y avoir un dossier .zip dans votre soumission qui englobe les 3 dossiers.
