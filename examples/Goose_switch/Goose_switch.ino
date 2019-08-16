/***Goose switch*******************
  resetPinでgoose電源オンオフを制御、
    オンするたびに曲順リセット
  selectPinで曲選択、２度押しで曲が切り替わる
*************************************/

#include "Goose.h"
const int resetPin =  13;  //gooseの電源スイッチ
const int selectPin =  10; //gooseの押しボタン
const int buttonPin = 2;
int song_num = 6;  //select 0-5

Goose goose(selectPin,resetPin);

void setup() {
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  static int oldState=HIGH;
  digitalWrite(resetPin, LOW);
  if ((buttonState == LOW) && (oldState == HIGH)) {
    goose.sing(song_num);
    delay(5000);  //wait 5sec(30sec for 1st-song),and power_off()
    goose.power_off();
  }
  oldState = buttonState;
}
