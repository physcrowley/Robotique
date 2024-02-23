[Accueil](./index.md) > [4M](./acceuil4M.md#projet-2--circuits-électroniques-et-programmation)

# Projet 2, Activité 2 : Boutons-poussoirs et temps de réponse

## 🚧 Version temporaire :

### Base
1. Suivre les instructions sur [le site d'Arduino](https://docs.arduino.cc/built-in-examples/digital/Debounce/). Le terme **debounce** se traduit à **antirebond** en français et signifie "délai suffisant pour des lectures distinctes".

### Ajustements
1. Ajuster le délai dans le code pour trouver un délai qui fonctionne bien pour votre bouton-poussoir, c'est-
a-dire un délai qui permet de lire distinctement les états **HIGH** et **LOW** du bouton-poussoir. Trouvez la valeur minimale fiable. C'est fiable si vous voyez un changement d'état 1 -> 0 chaque fois que vous appuyez sur le bouton-poussoir. Si vous obtenez plusieurs changements d'état pour un seul appui, le délai est trop court. Si vous n'obtenez pas de changement d'état, le délai est trop long.
1. Remplacer l'affichage de l'état du bouton-poussoir au moniteur de série (`Serial.println()`) par le changement de l'état d'un DEL, p. ex. sur la broche 12. Chaque fois que vous poussez le bouton-poussoir, la DEL change d'état (il s'allume s'il était éteint ou s'éteint s'il était allumé). Ajustez le délai pour avoir un comportement fiable. Filmez le comportement non fiable quand le délai est trop petit et le comportement fiable quand le délai est bien ajusté. Voici du code à ajouter à votre exemple pour faire cela :

```cpp
//... code existant pour les constantes (incluant le bouton)
const int ledPin = 12; // la DEL est branchée sur la broche 12
int ledState = LOW; // l'état initial de la DEL est éteint

void setup() {
    //... code existant
  pinMode(ledPin, OUTPUT); // la broche 12 est une sortie
}

// remplacer le code existant de la fonction loop() par le code suivant
void loop() {
    int buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        ledState = ledState == 0 ? 1 : 0; // si l'état est 1, changer à 0; sinon, changer à 1
        digitalWrite(ledPin, ledState);
    }
    delay(50); // délai pour éviter les rebonds
}

