[Accueil](./index.md) > [4M](./acceuil4M.md#projet-7--mouvement-avec-mission) > [Activité 2 : Capteurs](./p7-4m_act2.md)

# Activité 2 : Moustaches (capteurs tactiles)

## Code adapté

WhiskerSetupV2 -> [whisker-pio.zip](./assets/code/platformio/whisker-pio.zip)

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N.

## Questions d'analyse

1. La constante `LOW` représente quelle valeur pour un signal numérique? La constante `HIGH`?
1. Dans le programme `piezo` il y avait des instructions `delay()` suite aux instructions pour les moteurs mais il n'y en a pas dans ce programme. Expliquez pourquoi. _Indice : consultez les notes sur la multi-tâche._
1. Selon la structure du code, est-ce que le contact avec la moustache met fin au programme? Pourquoi ou pourquoi pas? Qu'est-ce qui se passe si on enlève le contact avec la moustache?

## Modifications au code

1. Ajouter un ton qui dure 0.5s quand le capteur tactile est enfoncé (en plus d'arrêter le mouvement du robot).
