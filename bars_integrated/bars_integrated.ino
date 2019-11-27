
#include "LedControl.h"
LedControl lc = LedControl(13,11,12,8);
LedControl ld = LedControl(10,8,9,4);
const int no_of_ultrasonic = 3;
int trigPin[no_of_ultrasonic] = {A0,A2,A4};
int echoPin[no_of_ultrasonic] = {A1,A3,A5};
int duration[3];
int distance[3];

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
  distance[i] = (duration[i]/2) / 29.1;
}

void printsensor(int i){
  Serial.print(i + 1);
  Serial.print(" Sensor: ");
  Serial.print(distance[i]); 
  Serial.print("cm    ");
}

void getPosition(){

  if(distance[0] < 50 && distance[1] > 50 && distance[2] > 50){
    Serial.println("1");
  }
  else if((distance[1] < 50 && distance[2] > 50 && distance[0] > 50) || (distance[0] < 50 && distance[1] < 50 && distance[2] < 50)){
    Serial.println("3");
  }
  else if(distance[2] < 50 && distance[1] > 50 && distance[0] > 50){
    Serial.println("5");
  }
  else if(distance[1] < 50 && distance[0] < 50 && distance[2] > 50){
    Serial.println("2");
  }
  else if(distance[1] < 50 && distance[2] < 50 && distance[0] > 50){
    Serial.println("4");
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
    for (int i = 0; i < no_of_ultrasonic; i++){
      readsensor(i);
//      printsensor(i);
    }
//    Serial.println();
    getPosition();
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
