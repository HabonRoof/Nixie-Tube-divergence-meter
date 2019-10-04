

/* This is Nixie Tube frimeware
   Now it can drive six nixie tube and display random digits
   Use 74238 for six tubes anode, and use 4028 for the ten cathod.
   Use PCF8563 as RTC timer.
   Author: Habonroof
   release date: 2019/10/03
   Version:0.3


*/

#include <Wire.h>
#include <Rtc_Pcf8563.h>

byte button_1 = 6;
byte button_2 = 7;

byte tube_a = 8;
byte tube_b = 9;
byte tube_c = 10;
byte tube_EN = 13;

byte PL = 11;
byte PR = 12;
byte digit_a = 2;
byte digit_b = 3;
byte digit_c = 4;
byte digit_d = 5;

byte random0;
byte random1;
byte random2;
byte random3;
byte random4;
byte random5;

int random_count = 0;
int random_time = 330;
int duration = 3000;
byte tube = 0;
unsigned long oldMicros;
byte Mode = 1;

boolean divergence_state = false;

Rtc_Pcf8563 rtc;
byte Hour;
byte Minute;
byte Second;
byte Hour1 = 0;
byte Hour2 = 0;
byte Min1 = 0;
byte Min2 = 0;
byte Sec1 = 0;
byte Sec2 = 0;
void setup() {
  pinMode(tube_a, OUTPUT);
  pinMode(tube_b, OUTPUT);
  pinMode(tube_c, OUTPUT);
  pinMode(tube_EN, OUTPUT);

  pinMode(digit_a, OUTPUT);
  pinMode(digit_b, OUTPUT);
  pinMode(digit_c, OUTPUT);
  pinMode(digit_d, OUTPUT);
  pinMode(PL, OUTPUT);
  pinMode(PR, OUTPUT);
  pinMode(button_1, INPUT);
  pinMode(button_2, INPUT);

  /*RTC.initClock();
    day, weekday, month, century(1=1900, 0=2000), year(0-99)
    rtc.setDate(3, 4, 10, 0, 19);
    hr, min, sec
    rtc.setTime(22, 8, 40);
  */
  Serial.begin(115200);
  randomSeed(analogRead(A0));
}

void loop() {
  if (micros() >= oldMicros) {
    oldMicros = micros() + duration;
    if (digitalRead(button_1) == 0) {
      divergence_state = false;
      random_count = 0;
    }
    if (digitalRead(button_2) == 0) {
      Mode ++;
      Serial.println(Mode);
      delay(250);
      if (Mode > 1)
        Mode = 0;
    }
    if (Mode == 1) {
      Serial.println("this is 1");
      divergence_meter();
    }
    if (Mode == 2) {
      real_time_clock();
      Serial.println("this is 2");
    }
    tube++;
    if (tube > 5)
      tube = 0;
  }
}

void real_time_clock() {
  Hour = rtc.getHour();
  Minute = rtc.getMinute();
  Second = rtc.getSecond();
  Hour1 = Hour / 10;
  Hour2 = Hour % 10;
  Min1 = Minute / 10;
  Min2 = Minute % 10;
  Sec1 = Second / 10;
  Sec2 = Second % 10;
  Serial.print(Hour);
  Serial.print(Minute);
  Serial.print(Second);
  tubeupdate(Hour1, Hour2, Min1, Min2, Sec1, Sec2);
}

void divergence_meter() {
  if (random_count < random_time) {
    random_display();
    random_count++;
    if (random_count == random_time) {
      random0 = random(2);
      random1 = 10;
      divergence_state = true;
    }
  }
  tubeupdate(random0, random1, random2, random3, random4, random5);
}
