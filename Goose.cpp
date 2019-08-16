#include "Arduino.h"
#include "Goose.h"

Goose::Goose(int selectPin, int resetPin)
{
  s_pin = selectPin;
  r_pin = resetPin;
  pinMode(s_pin, OUTPUT);
  pinMode(r_pin, OUTPUT);
  digitalWrite(s_pin, LOW);
  digitalWrite(r_pin, LOW);
}
void Goose::power_on() {
  digitalWrite(r_pin, HIGH);
}
void Goose::power_off() {
  digitalWrite(r_pin, LOW);
}
void Goose::sing(int song_num) {
  s_num = song_num;
  s_num %= 6;

  Goose::power_on();
  delay(50);
  for (int i = 0; i < s_num ; i++) {
    Goose::one_click();
    delay(m_time);
    Goose::one_click();
    delay(m_time);
  }
  Goose::one_click();
}
void Goose::one_click() {
  digitalWrite(s_pin, HIGH);
  delay(m_time);
  digitalWrite(s_pin, LOW);
}
