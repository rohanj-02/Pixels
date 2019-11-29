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

    
}


/////////////////////////////
byte eyetr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B01110000
};

byte eyetl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001110
};


//////////////////////////

byte reyetl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001111
};

byte reyetr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B00110000
};

byte rreyetr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B10010000
};

byte reyebr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001100
};

byte rreyebr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001001
};

byte reyebl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B11110000
};

////////////////////////////////

byte leyetl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001100
};

byte lleyetl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001001
};

byte leyetr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B11110000
};


byte leyebl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B00110000
};

byte lleyebl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B10010000
};

byte leyebr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001111
};

///////////////////////////////////

byte deyetl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001111
};

byte deyetr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B11110000
};

byte deyebl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B01110000,
   B01110000
};

byte deyebr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001110,
   B00001110
};

/////////////////////////////

byte ueyetl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001110,
   B00001110
};

byte ueyetr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B01110000,
   B01110000
};

byte ueyebl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B11110000
};

byte ueyebr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001111
};

//////////////////////////


byte lrdeyetl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001111
};

byte lrdeyetr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B11110000
};

byte ldeyebl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B00110000,
   B00110000
};

byte ldeyebr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001111
};


byte rdeyebl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B11110000
};

byte rdeyebr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001100,
   B00001100
};

///////////////////////

byte lueyetl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001100,
   B00001100
};

byte lueyetr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B11110000
};

byte rueyetl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001111
};

byte rueyetr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B00110000,
   B00110000
};

byte lrueyebl[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B11000000,
   B11100000,
   B11110000,
   B11110000
};

byte lrueyebr[] =
{
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000011,
   B00000111,
   B00001111,
   B00001111
};

/////////////////////////////

void eyes() {

    for (int i = 0; i < 8; ++i) {

      // right eye
      lc.setRow(3, i, eyetr[i]);
      lc.setRow(2, i, eyetl[i]);
      lc.setRow(4, i, eyetl[i]);
      lc.setRow(5, i, eyetr[i]);

      // left eye
      lc.setRow(1, i, eyetr[i]);
      lc.setRow(0, i, eyetl[i]);
      lc.setRow(6, i, eyetl[i]);
      lc.setRow(7, i, eyetr[i]);
    }  
  
}

void left() {

    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, leyetr[i]);
      lc.setRow(2, i, leyetl[i]);
      lc.setRow(4, i, leyebr[i]);
      lc.setRow(5, i, leyebl[i]);

      lc.setRow(1, i, leyetr[i]);
      lc.setRow(0, i, leyetl[i]);
      lc.setRow(6, i, leyebr[i]);
      lc.setRow(7, i, leyebl[i]);
    }
  
}

void lleft() {

    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, leyetr[i]);
      lc.setRow(2, i, lleyetl[i]);
      lc.setRow(4, i, leyebr[i]);
      lc.setRow(5, i, lleyebl[i]);

      lc.setRow(1, i, leyetr[i]);
      lc.setRow(0, i, lleyetl[i]);
      lc.setRow(6, i, leyebr[i]);
      lc.setRow(7, i, lleyebl[i]);
    }
  
}

void rright() {

    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, rreyetr[i]);
      lc.setRow(2, i, reyetl[i]);
      lc.setRow(4, i, rreyebr[i]);
      lc.setRow(5, i, reyebl[i]);

      lc.setRow(1, i, rreyetr[i]);
      lc.setRow(0, i, reyetl[i]);
      lc.setRow(6, i, rreyebr[i]);
      lc.setRow(7, i, reyebl[i]);
    }
  
}

void right() {

    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, reyetr[i]);
      lc.setRow(2, i, reyetl[i]);
      lc.setRow(4, i, reyebr[i]);
      lc.setRow(5, i, reyebl[i]);

      lc.setRow(1, i, reyetr[i]);
      lc.setRow(0, i, reyetl[i]);
      lc.setRow(6, i, reyebr[i]);
      lc.setRow(7, i, reyebl[i]);
    }
  
}

void down() {

    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, deyetr[i]);
      lc.setRow(2, i, deyetl[i]);
      lc.setRow(4, i, deyebr[i]);
      lc.setRow(5, i, deyebl[i]);

      lc.setRow(1, i, deyetr[i]);
      lc.setRow(0, i, deyetl[i]);
      lc.setRow(6, i, deyebr[i]);
      lc.setRow(7, i, deyebl[i]);
    }
}

void up() {

    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, ueyetr[i]);
      lc.setRow(2, i, ueyetl[i]);
      lc.setRow(4, i, ueyebr[i]);
      lc.setRow(5, i, ueyebl[i]);

      lc.setRow(1, i, ueyetr[i]);
      lc.setRow(0, i, ueyetl[i]);
      lc.setRow(6, i, ueyebr[i]);
      lc.setRow(7, i, ueyebl[i]);
    }
}

void middle(){
    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, leyetr[i]);
      lc.setRow(2, i, leyetl[i]);
      lc.setRow(4, i, leyebr[i]);
      lc.setRow(5, i, leyebl[i]);

      lc.setRow(1, i, reyetr[i]);
      lc.setRow(0, i, reyetl[i]);
      lc.setRow(6, i, reyebr[i]);
      lc.setRow(7, i, reyebl[i]);
    }
}

void middle_down(){
    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, lrdeyetr[i]);
      lc.setRow(2, i, lrdeyetl[i]);
      lc.setRow(4, i, ldeyebr[i]);
      lc.setRow(5, i, ldeyebl[i]);

      lc.setRow(1, i, lrdeyetr[i]);
      lc.setRow(0, i, lrdeyetl[i]);
      lc.setRow(6, i, rdeyebr[i]);
      lc.setRow(7, i, rdeyebl[i]);
    }
}

void middle_up(){
    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, lueyetr[i]);
      lc.setRow(2, i, lueyetl[i]);
      lc.setRow(4, i, lrueyebr[i]);
      lc.setRow(5, i, lrueyebl[i]);

      lc.setRow(1, i, rueyetr[i]);
      lc.setRow(0, i, rueyetl[i]);
      lc.setRow(6, i, lrueyebr[i]);
      lc.setRow(7, i, lrueyebl[i]);
    }
}


void right_up(){
    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, rueyetr[i]);
      lc.setRow(2, i, rueyetl[i]);
      lc.setRow(4, i, lrueyebr[i]);
      lc.setRow(5, i, lrueyebl[i]);
      
      lc.setRow(1, i, rueyetr[i]);
      lc.setRow(0, i, rueyetl[i]);
      lc.setRow(6, i, lrueyebr[i]);
      lc.setRow(7, i, lrueyebl[i]);
    }
}


void right_down(){
    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, lrdeyetr[i]);
      lc.setRow(2, i, lrdeyetl[i]);
      lc.setRow(4, i, rdeyebr[i]);
      lc.setRow(5, i, rdeyebl[i]);
      
      lc.setRow(1, i, lrdeyetr[i]);
      lc.setRow(0, i, lrdeyetl[i]);
      lc.setRow(6, i, rdeyebr[i]);
      lc.setRow(7, i, rdeyebl[i]);
    }
}

void left_up(){
    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, lueyetr[i]);
      lc.setRow(2, i, lueyetl[i]);
      lc.setRow(4, i, lrueyebr[i]);
      lc.setRow(5, i, lrueyebl[i]);

      lc.setRow(1, i, lueyetr[i]);
      lc.setRow(0, i, lueyetl[i]);
      lc.setRow(6, i, lrueyebr[i]);
      lc.setRow(7, i, lrueyebl[i]);
    }
}


void left_down(){
    for (int i = 0; i < 8; ++i) {
      lc.setRow(3, i, lrdeyetr[i]);
      lc.setRow(2, i, lrdeyetl[i]);
      lc.setRow(4, i, ldeyebr[i]);
      lc.setRow(5, i, ldeyebl[i]);

      lc.setRow(1, i, lrdeyetr[i]);
      lc.setRow(0, i, lrdeyetl[i]);
      lc.setRow(6, i, ldeyebr[i]);
      lc.setRow(7, i, ldeyebl[i]);
    }
}

void loop() {

  eyes();
  delay(500);

  left();
  delay(500);

  lleft();
  delay(500);

  left_up();
  delay(500);

  left_down();
  delay(500);

  eyes();
  delay(500);

  right();
  delay(500);

  rright();
  delay(500);

  right_up();
  delay(500); 

  right_down();
  delay(500);

  eyes();
  delay(500);

  middle();
  delay(500);

  middle_up();
  delay(500);

  middle_down();
  delay(500);
  
}
