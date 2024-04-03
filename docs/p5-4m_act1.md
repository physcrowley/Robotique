[Accueil](./index.md) > [3M](./acceuil4M.md#projet-5--systèmes-mécaniques)

# Projet 5, activité 1 : Tourelle universelle

## Objectif

Contrôler 2 servomoteurs ensemble pour créer une tourelle universelle qui peut pointer dans toutes les directions. En anglais, le terme équivalent à "tourelle universelle" est _pan-tilt mechanism_.

## Introduction

Visionner la vidéo suivante :

<iframe width="560" height="315" src="https://www.youtube.com/embed/iH9_xtulyws?si=t-pDHEEyJRlfl8Et" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

## Matériel

- 1 carte Arduino Uno
- 2 servomoteurs 9g
- 2 potentiomètres
- carton
- ruban adhésif
- bâtonnets de bois
- ciseaux

## Instructions

### Tester le matériel

1. Connectez les servomoteurs et les potentiomètres à la carte Arduino selon le schéma suivant :
   ![circuit_tourelle](./images/p5/circuit_tourelle.png)
1. Tester vos servomoteurs et potentiomètres individuellement. Téléchargez le code ci-dessous et créer les projets PlatformIO correspondants (voir les [notes sur comment importer un projet PlatformIO](./p2-3m_act2-pio.md#utiliser-du-code-de-démarrage)) :
   > Vous avez probablement déjà une version du projet servo-test. Vous pouvez la réutiliser pour tester les servomoteurs.
   - Test pour un servomoteur : [servo-test-pio.zip](./code/platformio/servo-test-pio.zip)
   - Test pour un potentiomètre [pot-test-pio.zip](./code/platformio/pot-test-pio.zip)
1. Notez les valeurs de calibrage que vous avez obtenus pour chaque pièce.

### Assembler la tourelle

Par exemple :
![tourelle](./images/p5/tourelle.png)

1. Fixez le 1e servomoteur à une base en carton.
1. Ajouter un des bras de servomoteur à l'axe de rotation du 1e servomoteur.
1. Fixez le 2e servomoteur à l'extrémité du bras du 1e servomoteur. Utilisez un bâtonnet de bois ou du carton pour créer une plateforme pour le 2e servomoteur. **L'axe de rotation du 2e servomoteur doit être dans le plan de rotation du 1e servomoteur.**
1. Ajoutez un bras de servomoteur à l'axe de rotation du 2e servomoteur.

### Tester l'intégration matérielle et logicielle

1. Téléchargez le code de démarrage suivant et créez le projet PlatformIO correspondant :
   - [tourelle-pio.zip](./code/platformio/tourelle-pio.zip)
1. Tester votre montage en tournant le potentiomètre pour le servo du bas ("lower").
1. Ajouter le code nécessaire pour inclure le potentimètre et le servo du haut ("upper").
1. Tester votre montage en tournant les deux potentiomètres. Le mécanisme devrait tourner 180 degrés sur la plan horizontal et 180 degrés sur le plan vertical.

## Livrables

Demandez à l'enseignant de vérifier le fonctionnement de votre tourelle.
Prenez une vidéo de votre montage et la soumettre dans le devoir approprié sur Classroom.
