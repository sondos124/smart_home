#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
const int button2=2;
const int led2=3;
LiquidCrystal lcd(12,11,7,6,5,4);
RTC_DS3231 rtc;
#include <Servo.h>
// Define the servo motor and potentiometer pins
const int servoPin = 9;  // You can use any digital pin
const int potPin = A1;   // Connect potentiometer to analog pin A0
Servo myServo;  // Create a servo object
void setup() {
  lcd.begin(16,2);
  lcd.print("IE4");
  delay(2000);
  // Attach the servo to the specified pin
  myServo.attach(servoPin);
  Serial.begin(9600);
 pinMode(button2, INPUT_PULLUP);
 pinMode(led2, OUTPUT);
}
void loop() {
 DateTime now = rtc.now();
lcd.clear();
lcd.print(now.year(),DEC);
lcd.print('/');
lcd.print(now.month(),DEC);
lcd.print('/');
lcd.print(now.day(),DEC);
lcd.print(0,1);
lcd.print(now.hour(),DEC);
lcd.print(':');
lcd.print(now.minute(),DEC);
lcd.print(':');
lcd.print(now.second(),DEC);
delay(2000);

// Read the potentiometer value (0 to 1023)
  int potValue = analogRead(potPin);

  // Map the potentiometer value to the servo angle (0 to 180)
  int servoAngle = map(potValue, 0, 1023, 0, 180);

  // Move the servo to the calculated angle
  myServo.write(servoAngle);

  // Add a delay for smoother movement (adjust as needed)
  delay(15);
int etat_button_2=digitalRead(button2);
  if(etat_button_2==LOW){
    Serial.println("1");
    digitalWrite(led2, HIGH) ;
     }
     if(etat_button_2==HIGH){
      Serial.println("0");
      digitalWrite(led2, LOW);     }}
