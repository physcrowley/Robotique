[Accueil](./index.md) > [4M](./acceuil4M.md#projet-7--mouvement-avec-mission) > [Activité 2 : Capteurs](./p7-4m_act2.md)

# Activité 2 : Application - balayeuse nocturne

## Code adapté

NightimeVacuumV2 -> [night-vacuum-pio.zip](./code/platformio/night-vacuum-pio.zip)

## Questions d'analyse

1. Pourquoi est-ce que le type `bool` est approprié pour les variables `leftState` et `rightState` (lignes 68 et 69)? Quelles valeurs peuvent être gardées dans un booléen? Quelles valeurs sont données par la fonction `digitalRead()`?
2. Mesurez les mouvements produits par chaque série d'instructions :
   1. Reculer pendant 1s (combien de cm)?
   2. Tourner pendant 800ms (combien de degrés)?
   3. Tourner pendant 400ms (combien de degrés)?
3. Ce code utilise la fonction `delay()` pour gérer le temps des mouvements. Dans le contexte de ce programme, est-ce que c'est une option raisonnable, ou serait-il important de remplacer ça avec des équivalents en `millis()`? Est-ce que le robot passe toujours son temps dans une branche de code qui utilise `delay()`? C'est quoi le pire cas possible ici avec `delay()` en terme de blocage du code? Est-ce que c'est un problème considérant l'objectif du programme : un robot qui est actif uniquement quand il fait sombre?

## Modifications au code

1. Ajustez les durées, au besoin, pour obtenir des distances ou angles plus appropriés.
2. Produire un ton différent (sans un délai spécifique) pour chaque type de contact avec un obstacle (droite, gauche, avant).
3. Que ce soit utile ou non dans ce contexte (comme vous l'aviez considérer au dernier numéro des questions d'analyse), voici quand même une version de ce programme écrit comme une machine à états finis (MEF/FSM) dans le but de vous fournir une autre variante en exemple : [night-vacuum-fsm.zip](./code/platformio/night-vacuum-fsm-pio.zip). La machine a été conçue avec les états suivants :
   - `SETUP` : initialisation,
   - `IDLE` : immobile,
   - `ADVANCE` : avancer,
   - `AVOID_RIGHT` : reculer et tourner à gauche,
   - `AVOID_LEFT` : reculer et tourner à droite,
   - `AVOID_FRONT` : reculer et tourner plus de 90 degrés (p. ex. 120)

   1. Lisez le code et identifiez les transitions entre les états. Les écrire sous forme d'un tableau avec les colonnes `état actuel`, `condition de transition`, `état suivant` est une bonne façon d'organiser ces informations. 
      > Dans le code, on reconnaît une transition quand on assigne un nouvel état à la variable `currentState`.

   2. Est-ce qu'il y a un état final dans ce cas? Pourquoi ou pourquoi pas?
   3. Avec l'extension draw.io dans VS Code, produire le diagramme d'états pour cette machine à états finis. Vous pouvez l'enregistrez dans le dossier `/src` de votre projet.
   4. Pour chaque état d'évitement d'obstacle il y a deux mouvements à faire, chacun avec leurs propres délais, alors la condition avec les `millis()` n'est pas juste un `if-else` mais plutôt un	`if-else if-else`, utilisant le premier délai dans le premier `if` et le deuxième délai dans le deuxième `if`. Lisez comment les conditions pour chaque `if` sont structurées et expliquez comment ils fonctionnent.
   5. Regardez comment le temps est géré dans le code pour l'utilisation de `millis()`. Le temps de référence, stocké dans la variable `start`, est une donnée globale utilisée et manipulée dans les fonctions de plusieurs états. Ceci est différent des exemples de clignotement et de dance qu'on a vus précédemment où le délai était indépendant du reste du programme et utilisé exclusivement dans le code pour la lumière ou les roues. Lisez le code pour répondre à ces questions :
      1. Dans quel état est-ce qu'on réinitialise le temps de référence?
      2. Dans quels états est-ce qu'on utilise le temps de référence pour calculer le temps écoulé?
      3. Au lieu de modifier le temps de référence dans leur bloc `else`, ces états font quoi?
