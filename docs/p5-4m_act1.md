[Accueil](./index.md) > [3M](./acceuil4M.md#projet-5--systèmes-mécaniques)

# Projet 5, activité 1 : Tourelle universelle

## Objectif

Contrôler 2 servomoteurs ensemble pour créer une tourelle universelle qui peut pointer dans toutes les directions. En anglais, le terme équivalent à "tourelle universelle" est *pan-tilt mechanism*.

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

1. Connectez les servomoteurs à la carte Arduino selon le schéma suivant :
    > 🚧 à ajouter
1. Fixez le 1e servomoteur à une base en carton.
1. Ajouter un des bras de servomoteur à l'axe de rotation du 1e servomoteur.
1. Fixez le 2e servomoteur à l'extrémité du bras du 1e servomoteur. Utilisez un bâtonnet de bois ou du carton pour créer une plateforme pour le 2e servomoteur. **L'axe de rotation du 2e servomoteur doit être dans le plan de rotation du 1e servomoteur.**
1. Ajoutez un bras de servomoteur à l'axe de rotation du 2e servomoteur.
1. Téléchargez le code suivant et créez le projet PlatformIO correspondant :
    * [tourelle-pio.zip](./code/platformio/tourelle-pio.zip)
1. Tester votre montage en tournant les potentiomètres pour contrôler les servomoteurs. Le bras du 2e servomoteur devrait pointer dans toutes les directions, jusqu'aux limites de rotation des servomoteurs.

## Livrables

Demandez à l'enseignant de vérifier le fonctionnement de votre tourelle.
Prenez une vidéo de votre montage et la soumettre dans le devoir approprié sur Classroom.