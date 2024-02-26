/*
Code produit durant un atelier à La Cité Collégial
Adapté par Charles Norminton et M. Crowley
2024-02
*/

/* 
définir les broches utilisées
*/

// capteur ultrason
const int trig = 12;
const int echo = 11;

// DEL
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
const int led5 = 6;

/*
variables globales
*/
int duree = 0;
int distance = 0;

void setup() {
  // spéficier le mode d'utilisation de chaque broche
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  // démarrer la communication série
  Serial.begin(9600);
}
void loop() {
  // prendre un lecture de distance
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, HIGH);
  duree = pulseIn(echo, HIGH);
  distance = (duree / 58);
  Serial.println(distance);

  // activer le led1 selon la valeur
  if (distance <= 10) {
    digitalWrite(led1, LOW);
  } else {
    digitalWrite(led1, HIGH);
  }

  // TODO - activer les autre DEL à des distances variées afin de donner
  // un effet de progression : 1 del vert si c'est très loin (plus loin que 150cm)
  // jusqu'à tous les DEL allumés quand c'est moins que 10cm

}
