/*  
 *   Play pong on an 8x8 matrix - project from itopen.it
 */
 
#include "LedControl.h"


LedControl lc = LedControl(13,11,12,8);
LedControl ld = LedControl(10,8,9,4);


void start() {
    ld.clearDisplay(0);
    for(int r = 0; r < 2; r++){
        for(int c = 0; c < 8; c++){
            ld.setLed(0, r, c, HIGH);
            delay(50);
        }
    }
    delay(1500);
    ld.clearDisplay(0);
}

int matrix[24][32];

void clearscreen() {
  for (int i = 0; i < 8; ++i) {
      lc.clearDisplay(i);
      ld.clearDisplay(i);
  }
}

void clearmatrix() {
  for (int i = 0; i < 24; ++i) {
     for (int j = 0; j < 32; ++j)
        matrix[i][j] = 0; 
  }
}


void update(){


    for (int r = 0; r < 24; ++r) {
      for (int c = 0; c < 32; ++c){
        if (matrix[r][c] == 1){
           if (r < 8) {
              lc.setLed(c/8, r, c%8, HIGH);
           }else if (r >= 8 && r < 16) {
              lc.setLed(7 - c/8, 7 - (r - 8), 7 - c%8, HIGH);
           }else {
              ld.setLed(c/8, r % 16, c % 8, HIGH);
           }
        }else {
          if (r < 8) {
              lc.setLed(c/8, r, c%8, LOW);
           }else if (r >= 8 && r < 16) {
              lc.setLed(7 - c/8, 7 - (r - 8), 7 - c%8, LOW);
           }else {
              ld.setLed(c/8, r % 16, c % 8, LOW);
           }
        }
     }
  }
  
}

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


  for (int i = 0; i < 24; ++i) {
     for (int j = 0; j < 32; ++j)
        matrix[i][j] = 0; 
  }

  start();
}

void dot(int x, int y) {
  /*
   * x, y are coordinates of point p
   *  00
   * 0p00
   * 0000
   *  00
  */
  
  matrix[x - 1][y] = 1;
  matrix[x - 1][y + 1] = 1;
  matrix[x + 2][y] = 1;
  matrix[x + 2][y + 1] = 1;

  
  matrix[x][y] = 1;
  matrix[x][y + 1] = 1;
  matrix[x + 1][y + 1] = 1;
  matrix[x + 1][y] = 1;

  matrix[x][y - 1] = 1;
  matrix[x + 1][y - 1] = 1;

  matrix[x][y + 2] = 1;
  matrix[x + 1][y + 2] = 1;
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
   
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c[i]);
  }

  delay(100);

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c0[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c[i]);
  }

  delay(100);

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c1[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c[i]);
  }

  delay(100);

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c0[i]);
  }

  delay(100);

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(6,i,c[i]);
  }

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(5,i,c1[i]);
  }

  delay(100);

}

