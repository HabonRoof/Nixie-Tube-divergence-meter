/* This is Nixie Tube frimeware
 * Now it can drive six nixie tube and display random digits
 * Use 74238 for six tubes anode, and use 4028 for the ten cathod.
 * Author: Habonroof
 * release date: 2019/10/03
 * Version:0.2
 * 
 * 
 */



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
boolean divergence_state = false;

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
  Serial.begin(115200);
  randomSeed(analogRead(A0));
}

void loop() {
  if (micros() >= oldMicros) {
    oldMicros = micros() + duration;
    Serial.println(digitalRead(button_1));
    if(digitalRead(button_1) == 0){
      divergence_state = false;
      random_count = 0;
    }
    divergence_meter();
    tubeupdate(random0, random1, random2, random3, random4, random5);
    tube++;
    if (tube > 5)
      tube = 0;
  }
}

void divergence_meter(){
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
