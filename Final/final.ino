#include "LedControl.h"
LedControl lc = LedControl(13,11,12,8);
LedControl ld = LedControl(10,8,9,4);
const int no_of_ultrasonic = 6;
int trigPin[no_of_ultrasonic] = {A0,A2,A4,2,4,6};
int echoPin[no_of_ultrasonic] = {A1,A3,A5,3,5,7};
int duration[6];
int distance[6];
int distance_threshold = 30;

void setup() {
  
  Serial.begin (9600);
  for(int i = 0; i < no_of_ultrasonic; i++){
    pinMode(trigPin[i], OUTPUT);
  }
  for(int i = 0; i < no_of_ultrasonic; i++){
    pinMode(echoPin[i], INPUT);
  }

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

void readsensor(int i){
  int duration1, distance1;
  digitalWrite (trigPin[i], HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin[i], LOW);
  duration[i] = pulseIn (echoPin[i], HIGH);
  distance[i] = abs((duration[i]/2) / 29.1);
}

void printsensor(int i){
  Serial.print(i + 1);
  Serial.print(" Sensor: ");
  Serial.print(distance[i]); 
  Serial.print("cm    ");
}

int getPosition(){

  if(abs(distance[3]) < distance_threshold && abs(distance[0]) < distance_threshold && abs(distance[4]) > distance_threshold && abs(distance[1]) < distance_threshold){
    Serial.println("12");
    return 12;
  }
  else if(abs(distance[5]) < distance_threshold && abs(distance[2]) < distance_threshold && distance[1] > distance_threshold && distance[4] > distance_threshold){
    Serial.println("3");
    return 3;
  }
  else if(distance[3] < distance_threshold && distance[4] > distance_threshold && distance[5] > distance_threshold){
    Serial.println("1");
    return 1;
  }
  else if(distance[3] < distance_threshold && distance[4] < distance_threshold && distance[5] > distance_threshold){
    Serial.println("2");
    return 2;
  }
  else if(distance[3] < distance_threshold && distance[4] < distance_threshold && distance[5] < distance_threshold || distance[4] < distance_threshold){
    Serial.println("3");
    return 3;
  }
  else if(distance[4] < distance_threshold && distance[5] < distance_threshold && distance[3] > distance_threshold){
    Serial.println("4");
    return 4;
  }
  else if(distance[5] < distance_threshold && distance[4] > distance_threshold && distance[3] > distance_threshold){
    Serial.println("5");
    return 5;
  }
  if(distance[0] < distance_threshold && distance[1] > distance_threshold && distance[2] > distance_threshold){
    Serial.println("6");
    return 6;
  }
  else if((distance[1] < distance_threshold && distance[2] > distance_threshold && distance[0] > distance_threshold) || (distance[0] < distance_threshold && distance[1] < distance_threshold && distance[2] < distance_threshold)){
    Serial.println("8");
    return 8;
  }
  else if(distance[2] < distance_threshold && distance[1] > distance_threshold && distance[0] > distance_threshold){
    Serial.println("10");
    return 10;
  }
  else if(distance[1] < distance_threshold && distance[0] < distance_threshold && distance[2] > distance_threshold){
    Serial.println("7");
    return 7;
  }
  else if(distance[1] < distance_threshold && distance[2] < distance_threshold && distance[0] > distance_threshold){
    Serial.println("9");
    return 9;
  }
  Serial.println("0");
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////BARS///////////////////////
////////////////////////////////////////////
byte on = B01111110;

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
   B01111110,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B01111110,
   B01111110
};

byte b2[] =
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

/////////////////WAITING///////////////////////
//////////////////////////////////////////////

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

/////////////////FLOWERS///////////////////////
//////////////////////////////////////////////

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

///////////////////EYES///////////////////////
//////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void clea() {
  for (int i = 0; i < 8; ++i) {
      lc.clearDisplay(i);
  }

  for (int i = 0; i < 8; ++i) {
      ld.clearDisplay(i);
  }
}


void waiting() {
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

void bars(int x) {

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

    if (x == 0) {
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
    }

    if (x == 2 || x == 7) {
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
    }else if (x == 3 || x == 8) {
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
    }else if (x == 4 || x == 9) {
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
    }else if (x == 5 || x == 10) {
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
    }else {
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
    }
}

void eyes(int x) {
    if (x == 0) {
      eyes();
    }else if (x == 1 || x == 2) {
      left_up();
    }else if (x == 3) {
      middle_up();
    }else if (x == 4 || x == 5) {
      right_up();
    }else if (x == 6 || x == 7) {
      left_down();
    }else if (x == 8) {
      middle_down();
    }else if (x == 9 || x == 10) {
      right_down();
    }else if (x == 12) {
      right();
      delay(50);
      rright();
    }else if (x == 11) {
      left();
      delay(50);
      lleft();
    }
}
int last = -1;
void flowers(int x) {

    if (last != 2 || x == 0) {
    closed_flower(7, 'c');
    }
    if (last != 3 || x == 0) {
    closed_flower(1, 'c');
    }
    if (last != 4 || x == 0) {
    closed_flower(2, 'd');
    }
    if (last != 5 || x == 0) {
    closed_flower(3, 'c');
    }

    if (x == 2 || x == 7) {
      if (last == 3) {
        flower_closing(1, 'c');
      }else if (last == 4) {
        flower_closing(2, 'd');
      }else if (last == 5) {
        flower_closing(3, 'c');
      }
      if (last != 2) {
          flower_opening(7, 'c');
      }
      last = 2;
    }else if (x == 3 || x == 8) {
      if (last == 2) {
        flower_closing(7, 'c');
      }else if (last == 4) {
        flower_closing(2, 'd');
      }else if (last == 5) {
        flower_closing(3, 'c');
      }
      if (last != 3) {
      flower_opening(1, 'c');
      }
      last = 3;
    }else if (x == 4 || x == 9) {
      if (last == 2) {
        flower_closing(1, 'c');
      }else if (last == 3) {
        flower_closing(7, 'c');
      }else if (last == 5) {
        flower_closing(3, 'c');
      }
      if (last != 4) {
      flower_opening(2, 'd');
      }
      last = 4;
    }else if (x == 5 || x == 10) {
      if (last == 2) {
        flower_closing(7, 'c');
      }else if (last == 4) {
        flower_closing(2, 'd');
      }else if (last == 3) {
        flower_closing(1, 'c');
      }
      if (last != 5) {
      flower_opening(3, 'c');
      }
      last = 5;
    }
}


/////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


unsigned long long start, curr_time;

int las = -1;

bool t = false;
bool first = true;
unsigned long long st = millis();
    
void loop() {
    delay(50);
    for(int i = 0; i < no_of_ultrasonic; i++){
      readsensor(i);
      printsensor(i);
    }
    
    if (getPosition() != 0 || millis() - st < 5000) {
      if (getPosition() != 0) {
        first = true;
      }
      t = true;
      curr_time = millis();

      if ((curr_time - start) % 30000 < 10000) {
          if (las != 1) {
            clea();
          }
          bars(getPosition());
          las = 1;
      }else if ((curr_time - start) % 30000 < 20000) {
          if (las != 2) {
            clea();
          }
          eyes(getPosition());
          las = 2;
      }else if ((curr_time - start) % 30000 < 30000) {
          if (las != 3) {
            clea();
          }
          flowers(getPosition());
          las = 3;
      }
    }else {

     if (first){
      first = false;
      st = millis();
     }else {
            if (t) {
              clea();
              t = false;
              waiting();
              start = millis();
            }
       
     }
    }
  }
