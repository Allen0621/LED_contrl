int L[8] = { 5, 4, 3, 2 };
int B[5] = { 12, 11, 10, 9, 8 };
bool debug = 0;
bool state0 = 0;
bool state1 = 0;
bool state2 = 0;
bool state3 = 0;
bool state4 = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++) {
    pinMode(B[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(L[i], OUTPUT);
  }
}

void loop() {
  if (debug) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(L[i], 1);
    }
    return;
  }
  int sw;
  sw = digitalRead(B[0]);
  if (sw == 0) {
    if (state0 == 0) {
      for (int i = 0; i < 4; i++) {
        digitalWrite(L[i], 1);
      }
      state0 = 1;
    } else {
      for (int i = 0; i < 4; i++) {
        digitalWrite(L[i], 0);
      }
      state0 = 0;
    }
  }
  sw = digitalRead(B[1]);
  if (sw == 0) {
    if (state1 == 0) {
      digitalWrite(L[0], 1);
      state1 = 1;
    } else {
      digitalWrite(L[0], 0);
      state1 = 0;
    }
  }
  sw = digitalRead(B[2]);
  if (sw == 0) {
    if (state2 == 0) {
      digitalWrite(L[1], 1);
      state2 = 1;
    } else {
      digitalWrite(L[1], 0);
      state2 = 0;
    }
  }
  sw = digitalRead(B[3]);
  if (sw == 0) {
    if (state3 == 0) {
      digitalWrite(L[2], 1);
      state3 = 1;
    } else {
      digitalWrite(L[2], 0);
      state3 = 0;
    }
  }
  sw = digitalRead(B[4]);
  if (sw == 0) {
    if (state4 == 0) {
      digitalWrite(L[3], 1);
      state4 = 1;
    } else {
      digitalWrite(L[3], 0);
      state4 = 0;
    }
  }
}
