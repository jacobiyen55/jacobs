#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trig1 = 6;
const int echo1 = 7;
const int trig2 = A5;
const int echo2 = A4;
const int trig3 = A3;
const int echo3 = A2;

const int kalibButon = 8;
const int olcmeButon = 9;

int sure = 0;
int mesafe = 0;

int sure2 = 0;
int mesafe2 = 0;

int sure3 = 0;
int mesafe3 = 0;

int ilkmesafe;
int ilkmesafe2;
int ilkmesafe3;

void setup() {
  lcd.begin(20,4);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  
  pinMode(kalibButon, INPUT);
  pinMode(olcmeButon, INPUT);

  while (digitalRead(kalibButon) == LOW) 
{
    lcd.setCursor(2, 0);
    lcd.print("KALiBRASYON iCiN");
    lcd.setCursor(2, 1);
    lcd.print(" BUTONA BASINIZ ");
    delay(100);

    if (digitalRead(kalibButon) == HIGH) 
{
      delay(50);
      ilkmesafe = mesafeolc();
      ilkmesafe2 = mesafeolc2();
      ilkmesafe3 = mesafeolc3();
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(" KALIBRASYON YAPILDI ");
      lcd.print(ilkmesafe);
      lcd.print(ilkmesafe2);
      lcd.print(ilkmesafe3);
      delay(3000);
      lcd.clear();
      break;
    }
  }
}


void loop() 
{
  if (digitalRead(olcmeButon) == HIGH) 
{
    lcd.setCursor(0, 0);
    lcd.print("Yukseklik:");
    lcd.setCursor(10, 0);
    int yukseklik = ilkmesafe - mesafeolc();
    lcd.print(yukseklik);

    lcd.setCursor(0, 2);
    lcd.print("Boy :");
    lcd.setCursor(6, 2);
    int boy = ilkmesafe3 - mesafeolc3();
    lcd.print(boy);

    lcd.setCursor(0, 1);
    lcd.print("En :");
    lcd.setCursor(5, 1);
    int en = ilkmesafe2 - mesafeolc2();
    lcd.print(en);
    
    delay(3000);
    lcd.clear(); 
  }
    else 
{
      lcd.setCursor(0, 0);
      lcd.print("     OLCUM iCiN   ");
      lcd.setCursor(0, 1);
      lcd.print("   BUTONA BASINIZ ");
      delay(100);
      lcd.clear();
    }
  }

  int mesafeolc() 
{
    digitalWrite(trig1, HIGH);
    delay(1);
    digitalWrite(trig1, LOW);
    sure = pulseIn(echo1, HIGH);
    mesafe = (sure / 2) / 27.6;
    return mesafe;
  }

  int mesafeolc2() 
{
    digitalWrite(trig2, HIGH);
    delay(1);
    digitalWrite(trig2, LOW);
    sure2 = pulseIn(echo2, HIGH);
    mesafe2 = (sure2 / 2) / 27.6;
    return mesafe2;
  }

    int mesafeolc3() 
{
    digitalWrite(trig3, HIGH);
    delay(1);
    digitalWrite(trig3, LOW);
    sure3 = pulseIn(echo3, HIGH);
    mesafe3 = (sure3 / 2) / 27.6;
    return mesafe3;
  }

  
