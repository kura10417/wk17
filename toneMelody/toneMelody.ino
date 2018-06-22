#include "pitches.h"
const int interruptNumber = 0;
const int led =  13;  
const int button = 2;  
int state = 0;
//int button_State1 = 0;
volatile boolean buttonState = LOW;


int littleStar[]={C5, C5, G5, G5, A5, A5, G5, 0, F5, F5, E5, E5, D5, D5, C5, 0,
                      G5, G5, F5, F5, E5, E5, D5, 0, G5, G5, F5, F5, E5, E5, D5, 0,
                      C5, C5, G5, G5, A5, A5, G5, 0, F5, F5, E5, E5, D5, D5, C5, 0};
int littleStarDurations[]={4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                          4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                          4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
int littleBee[]={G5, E5, E5, 0, F5, D5, D5, 0, C5, D5, E5, F5, G5, G5, G5, 0,
                     G5, E5, E5, 0, F5, D5, D5, 0, C5, E5, G5, G5, E5, 0, 0, 0,
                     D5, D5, D5, D5, D5, E5, F5, 0, E5, E5, E5, E5, E5, F5, G5, 0,
                     G5, E5, E5, 0, F5, D5, D5, 0, C5, E5, G5, G5, C5, 0, 0, 0};
int littleBeeDurations[]={4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                         4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT); 
  attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
}

void loop() {
  buttonState = digitalRead(button);
  if (state == HIGH) {
    int num1 = 13;
    for (int thisNote = 0; thisNote < num1; thisNote++) {
      buttonState = digitalRead(button);
      Serial.print(buttonState);Serial.print('\t');Serial.println(state);
      attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
      if (state == LOW){num1=0;}
    int littleStarDuration = 1000 / littleStarDurations[thisNote];
    tone(8, littleStar[thisNote], littleStarDuration);
    int pauseBetweenNotes = littleStarDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
   }
  if (state == LOW) {
    noTone(8);
    int num2 = 8;
    for (int thisNote = 0; thisNote < num2; thisNote++) {
      buttonState = digitalRead(button);
      Serial.print(buttonState);Serial.print('\t');Serial.println(state);
      attachInterrupt(interruptNumber, buttonStateChanged, CHANGE);
      if (state == HIGH){num2=0;}
    int littleBeeDuration = 1000 / littleBeeDurations[thisNote];
    tone(8, littleBee[thisNote], littleBeeDuration);
    int pauseBetweenNotes = littleBeeDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    }
   }   

}
void buttonStateChanged() {
  state =! state; 
}

