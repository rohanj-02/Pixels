/*  
 *   Play pong on an 8x8 matrix - project from itopen.it
 */
 
#include "LedControl.h"
LedControl lc = LedControl(13,11,12,8);
LedControl ld = LedControl(10,8,9,4);

void setup() {


  for (int i = 0; i < 8; ++i) {
  lc.shutdown(i,false);
  // Set the brightness to a medium values
  lc.setIntensity(i, 4);
  // and clear the display
  lc.clearDisplay(i);
  }

  for (int i = 0; i < 8; ++i) {
  ld.shutdown(i,false);
  // Set the brightness to a medium values
  ld.setIntensity(i, 4);
  // and clear the display
  ld.clearDisplay(i);
  }
}

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

void loop() {

  /*
   * configurations are changed after every 130ms to produce a moving pattern
   */
   
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c[i]);
  }

  delay(130);

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c0[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c[i]);
  }

  delay(130);

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c1[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c[i]);
  }

  delay(130);

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c0[i]);
  }

  delay(130);

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c1[i]);
  }

  delay(130);

}

