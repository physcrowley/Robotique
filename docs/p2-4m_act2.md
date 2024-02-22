

## Version temporaire :

### Base
1. Suivre les instructions sur [le site d'Arduino](https://docs.arduino.cc/built-in-examples/digital/Debounce/). Le terme **debounce** se traduit à **antirebond** en français et signifie "délai suffisant pour des lectures distinctes".

### Ajustements
1. Ajuster le délai dans le code pour trouver un délai qui fonctionne bien pour votre bouton-poussoir, c'est-
a-dire un délai qui permet de lire distinctement les états **HIGH** et **LOW** du bouton-poussoir. Trouvez la valeur minimale fiable. C'est fiable si vous voyez un changement d'état 1 -> 0 chaque fois que vous appuyez sur le bouton-poussoir.
1. Remplacer l'affichage de l'état du bouton-poussoir par le changement de l'état d'un DEL, p. ex. sur la broche 12. Chaque fois que vous poussez le bouton-poussoir, la DEL change d'état (il s'allume ou s'éteint). Ajustez le délai pour avoir un comportement fiable. Filmez le comportement non fiable quand le délai est trop petit et le comportement fiable quand le délai est bien ajusté. Voici du code à ajouter à votre exemple pour faire cela :

```cpp
//... code existant pour les constantes (incluant le bouton)
const int ledPin = 12; // la DEL est branchée sur la broche 12
int ledState = LOW; // l'état initial de la DEL est éteint

void setup() {
    //... code existant
  pinMode(ledPin, OUTPUT); // la broche 12 est une sortie
}

void loop() {
    // remplacer le code existant par le code suivant
    int buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        ledState = ledState == 0 ? 1 : 0; // si l'état est 1, changer à 0; sinon, changer à 1
        digitalWrite(ledPin, ledState);
    }
    delay(50); // délai pour éviter les rebonds
}

