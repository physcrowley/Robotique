[Accueil](./index.md) > [4M](./acceuil4M.md#projet-7--mouvement-avec-mission) > [Activité 2 : Capteurs](./p7-4m_act2.md)

# Activité 2 : Phototransistor (capteur lumineux)

## Code adapté

- PhototransistorsV2 et LightLevelPitchV2 -> [light-pio.zip](./code/platformio/light-pio.zip)

> Lire les commentaires d'en-tête dans `main.cpp` pour comprendre les modifications dans notre version par rapport à la version sur le site de CS2N.

## Questions d'analyse

1. Quelle est la différence entre les valeurs produites par un capteur _numérique_ comme un bouton (ou une moustache) et un capteur _analogique_ comme un phototransistor?
2. Quelle différence y a-t-il entre les numéros de broches analogiques et de broches numériques dans la bibliothèque `Arduino.h` (dans votre programme Arduino)?
3. Est-ce que les valeurs du phototransistor sont plus élevées quand il y a plus de lumière ou quand il y a moins de lumière?

## Modifications au code

1. Appliquez vos connaissances de la technique `millis()` pour créer un bip répétitif de 0.3s (comme un clignotement sonore) si la valeur lumineuse est plus haute qu'une certaine valeur, p. ex. 200. Ajuster la valeur limite selon ce que vous observez dans votre environnement.
   > _Consultez les [notes sur la multitâche](./p7-4m_notes-multi.md) au besoin_
