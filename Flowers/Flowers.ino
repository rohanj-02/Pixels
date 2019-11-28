 
#include "LedControl.h"
LedControl lc = LedControl(13,11,12,8);
LedControl ld = LedControl(10,8,9,4);

void setup() {


  for (int i = 0; i < 8; ++i) {
  lc.shutdown(i,false);
  // Set the brightness to a medium values
  lc.setIntensity(i, 1);
  // and clear the display
  lc.clearDisplay(i);
  }

  for (int i = 0; i < 8; ++i) {
  ld.shutdown(i,false);
  // Set the brightness to a medium values
  ld.setIntensity(i, 1);
  // and clear the display
  ld.clearDisplay(i);
  }
}

// following are seven different states a flower can be in

byte f0[] =
{
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00000000,
   B00000000,
   B00000000
};


byte f1[] =
{
   B00000000,
   B00000110,
   B00001110,
   B00011100,
   B00011000,
   B00000000,
   B00000000,
   B00000000
};

byte f2[] =
{
   B00000000,
   B00000110,
   B00001110,
   B00011110,
   B00011111,
   B00000110,
   B00000000,
   B00000000
};

byte f3[] =
{
   B00000000,
   B00000110,
   B00001110,
   B00011100,
   B00011100,
   B00001110,
   B00000110,
   B00000000
};

byte f4[] =
{
   B00000000,
   B00000110,
   B00001110,
   B00011100,
   B00011100,
   B00111110,
   B00111110,
   B00010000
};

byte f5[] =
{
   B00000000,
   B00000110,
   B00001110,
   B00011100,
   B00111100,
   B01111110,
   B01100110,
   B00000000
};


byte f6[] =
{
   B00000000,
   B00000110,
   B01101110,
   B11111100,
   B01111100,
   B01111110,
   B01100110,
   B00000000
};

byte cf0[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00011000
};


byte cf1[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00011000,
   B00111000,
   B01110000,
   B01100000,
   B00000000
};


byte cf2[] =
{
   B00000000,
   B00000000,
   B01100000,
   B11111000,
   B01111000,
   B01110000,
   B01100000,
   B00000000
};

byte cf3[] =
{
   B00000000,
   B01100000,
   B01110000,
   B00111000,
   B00111000,
   B01110000,
   B01100000,
   B00000000
};

byte cf4[] =
{
   B00001000,
   B01111100,
   B01111100,
   B00111000,
   B00111000,
   B01110000,
   B01100000,
   B00000000
};

byte cf5[] =
{
   B00000000,
   B01100110,
   B01111110,
   B00111100,
   B00111000,
   B01110000,
   B01100000,
   B00000000
};

byte cf6[] =
{
   B00000000,
   B01100110,
   B01111110,
   B00111110,
   B00111111,
   B01110110,
   B01100000,
   B00000000
};


byte f7[] =
{
   B00000000,
   B01100110,
   B01111110,
   B00111100,
   B00111100,
   B01111110,
   B01100110,
   B00000000
};

void closed_flower(int x, char ch) {

  for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f0[i]);
      else
       ld.setRow(x,i,f0[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf0[i]);
      else
       ld.setRow(x,i,cf0[i]);
    }
  }
}

void flower_closing(int x, char ch) {     // creates a closing effect of flower by displaying different states

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f6[i]);
      else
       ld.setRow(x,i,f6[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf6[i]);
      else
       ld.setRow(x,i,cf6[i]);
    }
  }

    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f5[i]);
      else
       ld.setRow(x,i,f5[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf5[i]);
      else
       ld.setRow(x,i,cf5[i]);
    }
  }

    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f4[i]);
      else
       ld.setRow(x,i,f4[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf4[i]);
      else
       ld.setRow(x,i,cf4[i]);
    }
  }

    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f3[i]);
      else
       ld.setRow(x,i,f3[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf3[i]);
      else
       ld.setRow(x,i,cf3[i]);
    }
  }
    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f2[i]);
      else
       ld.setRow(x,i,f2[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf2[i]);
      else
       ld.setRow(x,i,cf2[i]);
    }
  }
    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f1[i]);
      else
       ld.setRow(x,i,f1[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf1[i]);
      else
       ld.setRow(x,i,cf1[i]);
    }
  }

    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f0[i]);
      else
       ld.setRow(x,i,f0[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf0[i]);
      else
       ld.setRow(x,i,cf0[i]);
    }
  }

    delay(100);
}


void flower_opening(int x, char ch) {     // creates a opening effect of flower by displaying different states

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f1[i]);
      else
       ld.setRow(x,i,f1[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf1[i]);
      else
       ld.setRow(x,i,cf1[i]);
    }
  }

    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f2[i]);
      else
       ld.setRow(x,i,f2[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf2[i]);
      else
       ld.setRow(x,i,cf2[i]);
    }
  }
    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f3[i]);
      else
       ld.setRow(x,i,f3[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf3[i]);
      else
       ld.setRow(x,i,cf3[i]);
    }
  }
    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f4[i]);
      else
       ld.setRow(x,i,f4[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf4[i]);
      else
       ld.setRow(x,i,cf4[i]);
    }
  }

    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f5[i]);
      else
       ld.setRow(x,i,f5[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf5[i]);
      else
       ld.setRow(x,i,cf5[i]);
    }
  }

    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f6[i]);
      else
       ld.setRow(x,i,f6[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,cf6[i]);
      else
       ld.setRow(x,i,cf6[i]);
    }
  }
    delay(100);

    for (int i = 0; i < 8; ++i) {

    if  (x > 7 || x < 4) {
      if (ch == 'c')
       lc.setRow(x,i,f7[i]);
      else
       ld.setRow(x,i,f7[i]);
    }else {
      if (ch == 'c')
       lc.setRow(x,i,f7[i]);
      else
       ld.setRow(x,i,f7[i]);
    }
  }
    delay(100);
}

void loop() {

      

      closed_flower(7, 'c');
      closed_flower(1, 'c');
      closed_flower(2, 'd');
      closed_flower(3, 'c');
      delay(1000);

      flower_opening(7, 'c');
      flower_opening(1, 'c');
      flower_opening(2, 'd');
      flower_opening(3, 'c');
      delay(1000);

      flower_closing(3, 'c');
      flower_closing(2, 'd');
      flower_closing(1, 'c');
      flower_closing(7, 'c');
      

}
