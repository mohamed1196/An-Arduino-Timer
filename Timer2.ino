int sec = 0;
int Min = 0;
int frequancy;
String T;
boolean T1 = false;


unsigned char upSec;
unsigned char upMin;
unsigned char downSec;
unsigned char downMin;
unsigned char start;
unsigned char pause;
unsigned char cancel;
unsigned char Tone;

#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();


  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, OUTPUT);

}

void loop() {

  lcd.setCursor(4, 0);
  lcd.print("Min Sec");
  lcd.setCursor(6, 1);
  lcd.print(Min);
  lcd.print(":");
  lcd.print(sec);

  upMin = digitalRead(2);
  downMin = digitalRead(3);
  upSec = digitalRead(4);
  downSec = digitalRead(5);
  start = digitalRead(6);
  pause = digitalRead(7);
  cancel = digitalRead(8);
  Tone = digitalRead(9);

  if (Tone == LOW)
  {
    delay(200);
    T1 = !T1;

    if (T1 == false)
    {

      T = "T1";
      frequancy = 80;
      lcd.setCursor(14, 1);
      lcd.print(T);
    }

    else if (T1 == true)
    {
      T = "T2";
      frequancy = 1000;
      lcd.setCursor(14, 1);
      lcd.print(T);
    }
  }

  else if (upSec == LOW)
  {
    if (sec == 59)
    {
      sec = 0;
      Min = Min + 1;
      delay(200);
      lcd.setCursor(9, 0);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Min Sec");
      lcd.setCursor(6, 1);
      lcd.print(Min);
      lcd.print(":");
      lcd.print(sec);
    }

    else
    {
      sec = sec + 1;
      delay(200);
      lcd.setCursor(4, 0);
      lcd.print("Min Sec");
      lcd.setCursor(6, 1);
      lcd.print(Min);
      lcd.print(":");
      lcd.print(sec);
    }
  }

  else if (downSec == LOW)
  {

    if (Min == 0 & sec == 0)
    {
      Min = 0;

      sec = 0;
    }

    else if (sec <= 0) {
      sec = 59;
      Min = Min - 1;
      delay(200);
      lcd.setCursor(4, 0);
      lcd.print("Min Sec");
      lcd.setCursor(6, 1);
      lcd.print(Min);
      lcd.print(":");
      lcd.print(sec);

    }
    else if (sec == 10)
    {
      sec = sec - 1;
      delay(200);
      lcd.setCursor(10, 1);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Min Sec");
      lcd.setCursor(6, 1);
      lcd.print(Min);
      lcd.print(":");
      lcd.print(sec);
    }
    else
    {
      sec = sec - 1;
      delay(200);
      lcd.setCursor(4, 0);
      lcd.print("Min Sec");
      lcd.setCursor(6, 1);
      lcd.print(Min);
      lcd.print(":");
      lcd.print(sec);
    }

  }


  else if (upMin == LOW)
  {

    Min = Min + 1;
    delay(200);
    lcd.setCursor(4, 0);
    lcd.print("Min Sec");
    lcd.setCursor(6, 1);
    lcd.print(Min);
    lcd.print(":");
    lcd.print(sec);

  }

  else if (downMin == LOW)
  {

    if (Min == 0)
    {
      Min = 0;

    }
    else if (Min == 10)
    {
      Min = Min - 1;
      delay(200);
      lcd.setCursor(10, 1);
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("Min Sec");
      lcd.setCursor(6, 1);
      lcd.print(Min);
      lcd.print(":");
      lcd.print(sec);
    }
    else
    {
      Min = Min - 1;
      delay(200);

      lcd.setCursor(4, 0);
      lcd.print("Min Sec");
      lcd.setCursor(6, 1);
      lcd.print(Min);
      lcd.print(":");
      lcd.print(sec);
    }

  }



  else if (start == LOW)
  {

    while (Min != 0 | sec != 0)
    {

      if (sec <= 0)
      {
        delay(1000);
        sec = 59;
        Min = Min - 1;
        lcd.setCursor(4, 0);
        lcd.print("Min Sec");
        lcd.setCursor(6, 1);
        lcd.print(Min);
        lcd.print(":");
        lcd.print(sec);

      }


      else if (sec == 10)
      {
        delay(1000);
        sec = sec - 1;
        lcd.setCursor(10, 1);
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Min Sec");
        lcd.setCursor(6, 1);
        lcd.print(Min);
        lcd.print(":");
        lcd.print(sec);
      }

      else
      {
        delay(1000);
        sec = sec - 1;
        lcd.setCursor(4, 0);
        lcd.print("Min Sec");
        lcd.setCursor(6, 1);
        lcd.print(Min);
        lcd.print(":");
        lcd.print(sec);
      }

      if (cancel == LOW)
      {
        break;
      }

    }

    tone(10, frequancy);


  }

  else if (cancel == LOW)
  {
    Min = 0;
    sec = 0;
    noTone(10);
    delay(200);
    lcd.setCursor(10, 1);
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Min Sec");
    lcd.setCursor(6, 1);
    lcd.print(Min);
    lcd.print(":");
    lcd.print(sec);
  }




}
