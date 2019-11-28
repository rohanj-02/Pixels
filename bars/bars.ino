
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

byte on = B01111110;

byte h0[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00011000,
   B00011000,
   B00000000,
   B00000000,
   B00000000
};


byte h1[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00011000,
   B00011000,
   B00000000,
   B00000000
};

byte c[] =
{
   B00000000,
   B00000000,
   B00000000,
   B01100110,
   B01100110,
   B00000000,
   B00000000,
   B00000000
};

byte c0[] =
{
   B00000000,
   B00000000,
   B00000000,
   B01100000,
   B01100110,
   B00000110,
   B00000000,
   B00000000
};

byte c1[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000110,
   B01100110,
   B01100000,
   B00000000,
   B00000000
};


byte b0[] =
{
   B01111110,
   B01111110,
   B01111110,
   B00000000,
   B00000000,
   B01111110,
   B01111110,
   B01111110
};


byte b1[] =
{
   B01111110,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B01111110
};

byte b2[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};

void loop() {

  /*
   * configurations are changed after every 130ms to produce a moving pattern
   */
  
    for (int i = 0; i < 8; i++) {
       lc.setRow(0,i,on);
       lc.setRow(1,i,on);
       lc.setRow(2,i,on);
       lc.setRow(3,i,on);
       ld.setRow(0,i,on);
       ld.setRow(1,i,on);
       ld.setRow(2,i,on);
       ld.setRow(3,i,on);
       
    }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(7,i,b0[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(6,i,b0[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(5,i,b0[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(4,i,b0[i]);
      }

      delay(300);

      for (int i = 0; i < 8; ++i) {
          lc.setRow(7,i,b1[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(6,i,b0[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(5,i,b0[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(4,i,b0[i]);
      }

      delay(300);

      for (int i = 0; i < 8; ++i) {
          lc.setRow(7,i,b2[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(6,i,b1[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(5,i,b0[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(4,i,b0[i]);
      }

      delay(300);

      for (int i = 0; i < 8; ++i) {
          lc.setRow(7,i,b1[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(6,i,b2[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(5,i,b1[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(4,i,b0[i]);
      }

      delay(300);

      for (int i = 0; i < 8; ++i) {
          lc.setRow(7,i,b0[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(6,i,b1[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(5,i,b2[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(4,i,b1[i]);
      }

      delay(300);

      for (int i = 0; i < 8; ++i) {
          lc.setRow(7,i,b0[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(6,i,b0[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(5,i,b1[i]);
      }

      for (int i = 0; i < 8; ++i) {
          lc.setRow(4,i,b2[i]);
      }

      delay(300);

}

