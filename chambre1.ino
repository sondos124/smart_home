#include <Stepper.h>
// Définition des broches du moteur pas à pas
#define motorPin1 A2
#define motorPin2 A3
#define motorPin3 A4
#define motorPin4 A5
// Définition du nombre de pas par tour pour le moteur pas à pas
#define STEPS_PER_REV 2048
// Déclaration de l'objet Stepper
Stepper myStepper(STEPS_PER_REV, motorPin1, motorPin2, motorPin3, motorPin4);
// Broche du potentiomètre analogique
#define potPin A1
const int lm35Pin=A0;
const int bcdA1=10;
const int bcdB1=11;
const int bcdC1=12;
const int bcdD1=13;
const int bcdA2=6;
const int bcdB2=7;
const int bcdC2=8;
const int bcdD2=9;
//transmitteur
const int button1=2;
const int led1=3;
void setup() {
  // Déclaration de la vitesse du moteur pas à pas (peut être ajustée selon vos besoins)
  myStepper.setSpeed(30);
  // Initialisation de la communication série
  Serial.begin(9600);
  pinMode(bcdA1, OUTPUT);
  pinMode(bcdB1, OUTPUT);
  pinMode(bcdC1, OUTPUT);
  pinMode(bcdD1, OUTPUT);
  pinMode(bcdA2, OUTPUT);
  pinMode(bcdB2, OUTPUT);
  pinMode(bcdC2, OUTPUT);
  pinMode(bcdD2, OUTPUT);
  Serial.begin(9600);
  Serial.begin(9600);
 pinMode(button1, INPUT_PULLUP);
 pinMode(led1, OUTPUT);}
void loop() {
  // Lecture de la valeur du potentiomètre
  int potValue = analogRead(potPin);
  // Convertir la valeur analogique (0-1023) en une valeur de pas (0 - STEPS_PER_REV)
  int steps = map(potValue, 0, 1023, 0, STEPS_PER_REV);
  // Rotation du moteur pas à pas selon la position du potentiomètre
  myStepper.step(steps);
  // Affichage de la position actuelle du moteur
  Serial.print("Steps: ");
  Serial.println(steps);
  // Attente d'un court délai entre les lectures du potentiomètre
  delay(100);
  int sensorValue=analogRead(lm35Pin);
  int temperatureC=map(sensorValue, 0, 1023, 0, 500);
  int tens= int(temperatureC)/10;
  int units= int(temperatureC)%10;
  int bcdTens= convertToBCD(tens);
  int bcdUnits= convertToBCD(units);
  displayBCD(bcdTens, bcdA1, bcdB1, bcdC1, bcdD1);
  delay(5);
  displayBCD(bcdUnits, bcdA2, bcdB2, bcdC2, bcdD2);
  Serial.print(temperatureC);
  Serial.print("°C");
  delay(1000);
  int etat_button_1=digitalRead(button1);
  if(etat_button_1==LOW){
    Serial.println("1");
    digitalWrite(led1, HIGH) ;}
     if(etat_button_1==HIGH){
      Serial.println("0");
      digitalWrite(led1, LOW);     }}
int convertToBCD(int num){
  switch(num){
    case 1:
    return 0b0001;
    case 2:
    return 0b0010;
    case 3:
    return 0b0011;
    case 4:
    return 0b0100;
    case 5:
    return 0b0101;
    case 6:
    return 0b0110;
    case 7:
    return 0b0111;
    case 8:
    return 0b1000;
    case 9:
    return 0b1001;
    default:
    return 0;
  }}
void displayBCD(int bcdValue, int bcdA, int bcdB, int bcdC, int bcdD) {
  digitalWrite(bcdA, bitRead(bcdValue, 0));
  digitalWrite(bcdB, bitRead(bcdValue, 1));
  digitalWrite(bcdC, bitRead(bcdValue, 2));
  digitalWrite(bcdD, bitRead(bcdValue, 3));
}
