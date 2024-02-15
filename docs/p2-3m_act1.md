[Accueil](./index.md) > [3M](./acceuil3M.md)

# Projet 2 - Activité 1 : circuits et composants de base

## Objectif

* Réviser les notions de base en électricité
* Créer un circuit de base avec le matériel utilisé avec les trousses d'électronique

## Matériel

Nom | Diagramme | Image 
--- | --- | ---
1 Carte Arduino Uno | ![uno](./images/diag-uno.png) | ![Arduino](./images/arduino-uno.jpg)
1 Câble USB |  | ![USB](./images/usb-a-b.jpg)
1 Bouton-poussoir | ![button](./images/diag-button.png) | ![bouton](./images/push-button.jpg)
1 DEL | ![del](./images/diag-led.png) | ![DEL](./images/led.jpg)
1 Résistance de 220 ohms (code couleur : rouge, rouge, violet, or) | ![résistance](./images/diag-resistor.png) | ![résistance](./images/220ohm.drawio.png)
1 Plaque d'essai |  | ![plaque](./images/breadboard.jpg)

## Révision

Cette section passe en revue les concepts suivants :
* [Circuit électrique](#circuit-électrique)
    * [Diviseurs de tension](#diviseurs-de-tension)
    * [Diviseurs de courant](#diviseurs-de-courant)
* [Plaque d'essai](#plaque-d'essai)
* [DEL](#del)
* [Résistance](#résistance)
* [Bouton-poussoir](#bouton-poussoir)

### Concepts électriques

#### Circuit électrique

![circuit](./images/circuit.drawio.png)

Un circuit électrique est un chemin fermé par lequel circule un courant électrique. Il est composé de plusieurs éléments :
1. Une source d'énergie, qui fournit le courant électrique. Par exemple une pile ou une batterie.
2. Un conducteur, qui transporte le courant électrique. Par exemple un fil de cuivre.
3. Un récepteur, qui utilise le courant électrique. Par exemple une DEL ou un moteur.

> **Note :** C'est important que le récepteur ait la capacité de consommer l'énergie fournie par la source d'énergie. Sinon, on peut endommager ou détruire la source d'énergie et/ou le récepteur.

#### Diviseurs de tension

Un circuit qui divise la tension place plusieurs récepteurs **en série**. Chaque récepteur reçoit une partie de la tension totale. L'effet est que la résistance totale du circuit augmente et le courant diminue. 

![diviseur de tension](./images/voltage-divider.drawio.png)

C'est parfois nécessaire d'ajouter des résistances pour limiter le courant dans un circuit afin de protéger les composants. C'est une application classique des diviseurs de tension.

#### Diviseurs de courant

Un circuit qui divise le courant place plusieurs récepteurs **en parallèle**. Chaque récepteur reçoit une partie du courant total mais avec la tension totale de la source. L'effet est que la source d'énergie doit fournir plus de courant pour alimenter tous les récepteurs.

![diviseur de courant](./images/current-divider.drawio.png)

### Comprendre les composants

#### Plaque d'essai
Une plaque d'essai est un support pour les composants électroniques. Elle permet de créer des circuits temporaires sans souder les composants. Les trous sont connectés horizontalement et verticalement selon un schéma standard.

![plaque](./images/breadboard_connections.drawio.png)

On crée des circuits en insérant des fils monobrin ou les broches des composants dans les trous, en s'assurant de connecter les composants selon le circuit désiré.

Voici une vidéo qui explique comment utiliser une plaque d'essai :

<iframe width="560" height="315" src="https://www.youtube.com/embed/6WReFkfrUIk?si=HZpOz4fT5xvs9U80" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

#### DEL

Un DEL est une diode électroluminescente. C'est un composant qui émet de la lumière lorsqu'il est traversé par un courant électrique. Il est polarisé, c'est-à-dire qu'il a un sens de branchement. Il faut donc le brancher dans le bon sens pour qu'il fonctionne.

![DEL](./images/led-annotation.drawio.png)

La longue patte de la DEL est la patte positive. Elle doit être connectée au courant positif pour que la DEL s'allume. La patte négative est la patte la plus courte.

#### Résistance

Les résistances consomment de l'énergie électrique et sont généralement utilisées pour diminuer le courant ou la tension pour protéger les composants.

Notamment, les DEL ne peuvent pas survivre à des tensions trop élevées et la carte Arduino ne peut pas survivre à des courants trop élevés. Chaque composant a des intervalles de tension et de courant à respecter et on peut trouver ces informations dans les spécifications techniques du composant.

Par exemple, voici [les spécifications pour un affichage DEL 7 segments](https://docs.rs-online.com/b51e/0900766b801bf827.pdf).

La valeur d'une résistance est indiquée par un code de bandes de couleurs. Le tableau suivant, en couleurs plus naturelles, peut vous aider à identifier la couleur de chaque bande sur une résistances :

![résistance](./images/resistance-table.png)
_source : [FabLabUTC](https://fablabutc.fr/wp-content/uploads/2021/01/Tutoriel_Electronique-Generale-3.pdf)_

Le [calculateur de résistances sur le site de DigiKey](https://www.digikey.ca/fr/resources/conversion-calculators/conversion-calculator-resistor-color-code-4-band), un fournisseur important de composants électroniques en Amérique du Nord, peut faire le calcul de la résistance si vous connaissez les couleurs. Il y a un onglet pour les résistances de 4 bandes et un autre pour les résistances de 5 bandes. 

P. ex. pour une résistance de 220 ohms à 4 bandes les couleurs sont rouge, rouge, brun/marron _et or (±5%)_; mais avec 5 bandes les couleurs sont rouge, rouge, noir, noir _et rouge (±2%)_.

![résistance](./images/220ohm.drawio.png)

#### Bouton-poussoir

Un bouton poussoir est un interrupteur qui se ferme lorsqu'on appuie dessus. Il est souvent utilisé pour démarrer ou arrêter un circuit.

![bouton](./images/push-button-internals.drawio.png)

## Activité - Créer un circuit de base

### Schéma du circuit

![schéma](./images/schematic.png)

### Image du circuit

![image](./images/picture.drawio.png)

### Description du circuit
Brancher la carte Arduino à l'ordinateur avec le câble USB. L'ordinateur devient la source d'énergie et la carte Arduino offre des prises de 5V, de 3.3V et de masse (GND). 

Insérer le bouton-poussoir, la résistance et la DEL dans la plaque d'essai. Connecter les composants selon le schéma du circuit.

La DEL devrait être éteinte. Quand vous appuyer sur le bouton-poussoir, la DEL devrait s'allumer. Relâcher le bouton-poussoir. La DEL devrait s'éteindre.

### Soumettre votre travail

Prendre une vidéo du circuit en action. Soumettre la vidéo dans le devoir sur Google Classroom.
