void random_display() {
  random0 = random(10);
  random1 = random(10);
  random2 = random(10);
  random3 = random(10);
  random4 = random(10);
  random5 = random(10);
  tubeupdate(random0,random1,random2,random3,random4,random5);
}


void tubeupdate(int num0,int num1,int num2,int num3,int num4,int num5){
  digitalWrite(tube_EN, LOW);
  if (tube == 0) {
    digitalWrite(tube_a, LOW);
    digitalWrite(tube_b, LOW);
    digitalWrite(tube_c, LOW);
    digitalWrite(tube_EN, HIGH);
    digit_update(num0);
  }
  if (tube == 1) {
    digitalWrite(tube_a, HIGH);
    digitalWrite(tube_b, LOW);
    digitalWrite(tube_c, LOW);
    digitalWrite(tube_EN, HIGH);
    digit_update(num1);
  }
  if (tube == 2) {
    digitalWrite(tube_a, LOW);
    digitalWrite(tube_b, HIGH);
    digitalWrite(tube_c, LOW);
    digitalWrite(tube_EN, HIGH);
    digit_update(num2);
  }
  if (tube == 3) {
    digitalWrite(tube_a, HIGH);
    digitalWrite(tube_b, HIGH);
    digitalWrite(tube_c, LOW);
    digitalWrite(tube_EN, HIGH);
    digit_update(num3);
  }
  if (tube == 4) {
    digitalWrite(tube_a, LOW);
    digitalWrite(tube_b, LOW);
    digitalWrite(tube_c, HIGH);
    digitalWrite(tube_EN, HIGH);
    digit_update(num4);
  }
  if (tube == 5) {
    digitalWrite(tube_c, HIGH);
    digitalWrite(tube_b, LOW);
    digitalWrite(tube_a, HIGH);
    digitalWrite(tube_EN, HIGH);
    digit_update(num5);
  }
}

//======================================================

void digit_update(int num) {
  if (num == 0) {
    digitalWrite(digit_a, LOW);
    digitalWrite(digit_b, LOW);
    digitalWrite(digit_c, LOW);
    digitalWrite(digit_d, LOW);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 1) {
    digitalWrite(digit_a, HIGH);
    digitalWrite(digit_b, LOW);
    digitalWrite(digit_c, LOW);
    digitalWrite(digit_d, LOW);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 2) {
    digitalWrite(digit_a, LOW);
    digitalWrite(digit_b, HIGH);
    digitalWrite(digit_c, LOW);
    digitalWrite(digit_d, LOW);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 3) {
    digitalWrite(digit_a, HIGH);
    digitalWrite(digit_b, HIGH);
    digitalWrite(digit_c, LOW);
    digitalWrite(digit_d, LOW);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 4) {
    digitalWrite(digit_a, LOW);
    digitalWrite(digit_b, LOW);
    digitalWrite(digit_c, HIGH);
    digitalWrite(digit_d, LOW);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 5) {
    digitalWrite(digit_a, HIGH);
    digitalWrite(digit_b, LOW);
    digitalWrite(digit_c, HIGH);
    digitalWrite(digit_d, LOW);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 6) {
    digitalWrite(digit_a, LOW);
    digitalWrite(digit_b, HIGH);
    digitalWrite(digit_c, HIGH);
    digitalWrite(digit_d, LOW);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 7) {
    digitalWrite(digit_a, HIGH);
    digitalWrite(digit_b, HIGH);
    digitalWrite(digit_c, HIGH);
    digitalWrite(digit_d, LOW);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 8) {
    digitalWrite(digit_a, LOW);
    digitalWrite(digit_b, LOW);
    digitalWrite(digit_c, LOW);
    digitalWrite(digit_d, HIGH);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 9) {
    digitalWrite(digit_a, HIGH);
    digitalWrite(digit_b, LOW);
    digitalWrite(digit_c, LOW);
    digitalWrite(digit_d, HIGH);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
  }
  if (num == 10) {
    digitalWrite(digit_c, HIGH);
    digitalWrite(digit_d, HIGH);
    digitalWrite(PR, LOW);
    digitalWrite(PL, LOW);
    digitalWrite(PR, HIGH);
  }
  if (num == 11) {
    digitalWrite(digit_c, HIGH);
    digitalWrite(digit_d, HIGH);
    digitalWrite(PR, LOW);
    digitalWrite(PL, HIGH);
  }
}
