[Accueil](./index.md) > [4M](./acceuil4M.md#projet-7--mouvement-avec-mission) > [Activité 2 : Capteurs](./p7-4m_act2.md)

# Activité 2 : Haut-parleur piezoélectrique

## Code adapté

PiezospeakerDemoV2 -> [piezo-pio.zip](./code/platformio/piezo-pio.zip)

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N. Vous pourrez alors ignorez certaines explications sur des éléments de code qui ont été retirés, comme les macros `#define`.

## Questions d'analyse

1. Que signifie le modificateur de variable `const`?
1. Que signifie le modificateur de variable `static` utilisé dans la fonction `loop()` : `static const int toneLength = 1000;`?
1. Pourquoi est-ce une bonne idée de déclarer une variable pour la durée du ton dans ce programme (on le fait dans setup() et dans loop())?
1. Quel ton est le plus aigu? Le plus grave? Il y en avait trois dans le programme : 2000Hz, 500Hz et 1500Hz.
1. Comment est-ce que l'utilisation de la bibliothèque personnelle que nous avons créée à la fin de l'activité 1 sur l'entrainement différentiel rend ce programme plus lisible? plus simple à utiliser?

## Modifications au code

1. Modifier le code pour avoir des durées de tons différentes pour setup() et pour loop().
1. Faites des tests avec le délai pour le virage à droite pour obtenir un virage d'environs :
   1. 45 degrés,
   1. 90 degrés,
   1. 120 degrés.
1. Notez les valeurs obtenues dans votre document d'analyse. C'est de l'information qui pourrait être utile plus tard dans d'autres programmes.
