int age = 10;

void setup() {
  Serial.begin(9600);
  /*
  Une condition est une expression qui s'évalue à vrai ou faux
  ... c'est une question avec une réponse oui/non

  On compare souvent deux valeurs ensemble.
  Souvent, une des deux est une variable

  > : plus grand que
  >= : plus grand que ou égale à
  == : égale à
  <= : moins grand ou égale à
  < : moins grand que
  != : pas égale à
  */
  if (age >= 16) {
    // code à exécuter si la condition est vrai
    Serial.println("Tu peux conduire.");
  } else {
    // code à exécuter si la condition est fausse
    Serial.println("Tu es encore trop jeune pour conduire.");
  }
  

}

void loop() {


}
