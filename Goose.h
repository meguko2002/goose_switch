#ifndef _GOOSE_H_
#define _GOOSE_H_

class Goose{
  public:
    Goose(int selectPin,int resetPin);
    void sing(int song_num); //select 0-5, 0:song 1-5:cry
    void power_on();
    void power_off();
    void one_click();
   private:
    int s_num;
    int s_pin;
    int r_pin;
    const int m_time=50;
};

#endif
