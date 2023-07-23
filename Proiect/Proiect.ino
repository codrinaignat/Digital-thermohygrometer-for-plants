#include <LiquidCrystal.h>
#define redLED 13
#define greenLED 10
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int buzzer = 8;
int hygrometer = A1;
int HumidValue;
int pinTemp = A2;

void setup()
{
  pinMode (buzzer, OUTPUT);
  pinMode (redLED, OUTPUT);
  pinMode (greenLED, OUTPUT);
  pinMode (pinTemp, INPUT);
  pinMode (hygrometer, INPUT);
  lcd.begin(16,2);

}

void loop()
{
  HumidValue = analogRead(hygrometer);
  HumidValue = constrain(HumidValue, 400, 1023);
  HumidValue = map(HumidValue, 400, 1023, 100, 0);

  delay(200);

  float temp;
   
  int counter = 25;
  int avg = 0;
  for (int i = 0; i< counter; i++)
  {
    avg += analogRead(pinTemp);
  }
  avg = avg / counter; 
  temp = avg * (5000 / 1024.0); //converting from reading into voltage
  temp = temp / 10; //converting the voltage into the temperature in degree Celsius
 

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print(" deg.");
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
  lcd.print(HumidValue);
  lcd.print("%");
  delay(5000);


if (temp >= 35 & HumidValue > 80)
{
  digitalWrite (redLED, HIGH);
  digitalWrite (buzzer, HIGH);
  int i;
  for (i = 0; i<200; i++)
  {
        digitalWrite (buzzer, HIGH) ;
        delay (2) ;
        digitalWrite (buzzer, LOW) ;
        delay (2) ;
    }
    digitalWrite (greenLED, LOW);
    lcd.clear();
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Temp high!");
    lcd.setCursor(0,1);
    lcd.print("Humidity high!");
    delay(2000);
}
else if (temp >= 35 & HumidValue>=20 & HumidValue <=80)
  {
  digitalWrite (redLED, HIGH);
    digitalWrite (buzzer, HIGH);
    int i;
    for (i = 0; i <200; i++)
    {
        digitalWrite (buzzer, HIGH) ;
        delay (2) ;
        digitalWrite (buzzer, LOW) ;
        delay (2) ;
    }
    digitalWrite (greenLED, LOW);
    lcd.clear();
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Plant is NOT OK");
    lcd.setCursor(0,1);
    lcd.print("Temp value high!");
    delay(2000);
}
else if (temp >= 35 & HumidValue < 20){
  digitalWrite (redLED, HIGH);
    digitalWrite (buzzer, HIGH);
    int i;
    for (i = 0; i <200; i++)
    {
        digitalWrite (buzzer, HIGH) ;
        delay (2) ;
        digitalWrite (buzzer, LOW) ;
        delay (2) ;
    }
    digitalWrite (greenLED, LOW);
    lcd.clear();
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Humid low!");
    lcd.setCursor(0,1);
    lcd.print("Temp high!");
    delay(2000);
  }
else if (temp <10 & HumidValue > 80){
  digitalWrite (redLED, HIGH);
    digitalWrite (buzzer, HIGH);
    int i;
    for (i = 0; i <200; i++)
    {
        digitalWrite (buzzer, HIGH) ;
        delay (2) ;
        digitalWrite (buzzer, LOW) ;
        delay (2) ;
    }
    digitalWrite (greenLED, LOW);
    lcd.clear();
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Temp low!");
    lcd.setCursor(0,1);
    lcd.print("Humid high!");
    delay(2000);
} 
else if (temp <10 & HumidValue < 20){
  digitalWrite (redLED, HIGH);
    digitalWrite (buzzer, HIGH);
    int i;
    for (i = 0; i <200; i++)
    {
        digitalWrite (buzzer, HIGH) ;
        delay (2) ;
        digitalWrite (buzzer, LOW) ;
        delay (2) ;
    }
    digitalWrite (greenLED, LOW);
    lcd.clear();
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Temp low!");
    lcd.setCursor(0,1);
    lcd.print("Humid low!");
    delay(2000);
} 
else if (temp <10 & HumidValue <= 80 & HumidValue >= 20){
  digitalWrite (redLED, HIGH);
    digitalWrite (buzzer, HIGH);
    int i;
    for (i = 0; i <200; i++)
    {
        digitalWrite (buzzer, HIGH) ;
        delay (2) ;
        digitalWrite (buzzer, LOW) ;
        delay (2) ;
    }
    digitalWrite (greenLED, LOW);
    lcd.clear();
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Plant is NOT OK");
    lcd.setCursor(0,1);
    lcd.print("Temp low!");
    delay(2000);
} 
else if (temp >= 10 & temp <35 & HumidValue > 80){
  digitalWrite (redLED, HIGH);
    digitalWrite (buzzer, HIGH);
    int i;
    for (i = 0; i <200; i++)
    {
        digitalWrite (buzzer, HIGH) ;
        delay (2) ;
        digitalWrite (buzzer, LOW) ;
        delay (2) ;
    }
    digitalWrite (greenLED, LOW);
    lcd.clear();
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Plant is NOT OK");
    lcd.setCursor(0,1);
    lcd.print("Humid high!");
    delay(2000);
}
else if (temp >= 10 & temp < 35 & HumidValue < 20){
    digitalWrite (redLED, HIGH);
    digitalWrite (buzzer, HIGH);
    int i;
    for (i = 0; i <200; i++)
    {
        digitalWrite (buzzer, HIGH) ;
        delay (2) ;
        digitalWrite (buzzer, LOW) ;
        delay (2) ;
    }
    digitalWrite (greenLED, LOW);
    lcd.clear();
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Plant is NOT OK");
    lcd.setCursor(0,1);
    lcd.print("Humid low!");
    delay(2000);
}

else 
{
    digitalWrite (redLED, LOW);
    digitalWrite (buzzer, LOW);
    digitalWrite (greenLED, HIGH);
    lcd.clear();
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("Plant is OK");
    lcd.setCursor(0,1);
    lcd.print(":)");

    delay(1000);
}
}
