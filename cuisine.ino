const int button3=2;
const int led3=3;
const int buzzer=4;
const int button4=5;
const int vane=6;
const int CapteurFlame=7;
unsigned long previousMillis=0;
const long interval=3000;


void setup() {
pinMode(CapteurFlame, INPUT);
pinMode(button3, INPUT);
pinMode(button4, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(vane,OUTPUT);
Serial.begin(9600);
}

void loop() {
 int etat_button_3=digitalRead(button3);
 int etat_flame=digitalRead(CapteurFlame);
 char received_etat_led1=Serial.read();
 char received_etat_led2=Serial.read();
 unsigned long currentMillis=millis();
 if (received_etat_led1 == '1')

 {
  digitalWrite(led3,HIGH);
 }
if(received_etat_led1=='0')
{digitalWrite(led3,LOW);
}
if (received_etat_led2 == '1')

 {
  digitalWrite(led3,HIGH);
 }
if(received_etat_led2=='0')
{digitalWrite(led3,LOW);
}
if(etat_flame=HIGH)
{digitalWrite(buzzer,HIGH);
if (currentMillis - previousMillis >= interval){
  digitalWrite(vane, HIGH);
  digitalWrite(buzzer,LOW);

}
}
if (etat_flame== LOW)
{
  digitalWrite(buzzer, LOW);
  digitalWrite(vane, LOW);
}
if(button4== HIGH)
{digitalWrite(buzzer,LOW);
digitalWrite(vane,LOW);
}}
