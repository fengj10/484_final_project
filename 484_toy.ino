#include <LiquidCrystal.h>
#define LED A2
const int buzzer = 13;
const int C = 6;
const int E = 7;
const int F = 8;
const int G = 9;
const int B = 10;

int state = 2;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int self = 0;
int freq[] = {262, 294, 330, 349, 392};
int melody[] = {5, 3, 3, 4, 2, 2, 1, 2, 3, 4, 5, 5, 5, 5, 3, 3, 4, 2, 2, 1, 3, 5, 5, 3, 2, 2, 2, 2, 2, 3, 4, 3, 3, 3, 3, 3, 4, 5, 5, 3, 3, 4, 2, 2, 1, 3, 5, 5, 1};
int beat[] = {1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4};

int freq1[] = { 659, 659, 0, 659, 0, 523, 659, 0, 784, 0, 392, 0, 523, 0, 392, 0, 330, 0, 440, 0, 494, 0, 466, 440, 392, 659, 0, 784, 0, 880, 0, 698, 0, 784, 0, 659, 0, 523, 587, 494, 523, 0, 392, 0, 330, 0, 440, 0, 494, 0, 466, 440, 392 };
int beat1[] = { 150, 150, 300, 150, 300, 150, 150, 300, 150, 300, 150, 300, 150, 300, 150, 300, 150, 150, 150, 150, 150, 150, 150, 150, 300, 150, 150, 150, 150, 150, 150, 150, 300, 150, 150, 150, 150, 150, 150, 150, 150, 300, 150, 150, 150, 150, 150, 150, 150, 300 };
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);

  pinMode(C, INPUT);
  digitalWrite(C, HIGH);

  pinMode(E, INPUT);
  digitalWrite(E, HIGH);

  pinMode(F, INPUT);
  digitalWrite(F, HIGH);

  pinMode(G, INPUT);
  digitalWrite(G, HIGH);

  pinMode(B, INPUT);
  digitalWrite(B, HIGH);

  pinMode(A1, INPUT);
  digitalWrite(A1, HIGH);

  pinMode(LED,OUTPUT);

  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Pick song:");
  if (state == 0) {
    lcd.setCursor(0, 1);
    lcd.print("1. rhythm1");
  }
  if (state == 1) {
    lcd.setCursor(0, 1);
    lcd.print("2. rhythm2");
  }
  if (state == 2) {
    lcd.setCursor(0, 1);
    lcd.print("3. ownwork");
  }

  if (digitalRead(C) == LOW) {
    state = 0;
  }
  if (digitalRead(E) == LOW) {
    state = 1;
  }
  if (digitalRead(F) == LOW) {
    state = 2;
  }

  if (digitalRead(G) == LOW) {
    if (state == 0 ) {
      for (int i = 0 ; i < 49 ; i++) {
        tone(buzzer, freq[melody[i] - 1]);
        delay(beat[i] * 250);
        noTone(buzzer);
        delay(0);
      }
      delay(1000);
    }
    if (state == 1 ) {
      for (int i = 0; i < 53; i++) {
        if (freq1[i] != 0) {
          tone(buzzer, freq1[i]);
        }
        delay(beat1[i]);
        noTone(buzzer);
        delay(20);
      }
      delay(1000);
    }
    if (state == 2) {
      self = 1;
      digitalWrite(LED, HIGH);
    }

  }

  while (self == 1) {
    while (digitalRead(C) == LOW) {
      tone(buzzer, 262);
    }
    while (digitalRead(E) == LOW) {
      tone(buzzer, 311);
    }
    while (digitalRead(F) == LOW) {
      tone(buzzer, 349);
    }
    while (digitalRead(G) == LOW) {
      tone(buzzer, 392);
    }
    while (digitalRead(B) == LOW) {
      tone(buzzer, 466);
    }
    while (digitalRead(A1) == LOW) {
      state = 0;
      self =0;
      digitalWrite(LED, LOW);
    }
    noTone(buzzer);
  }
}
