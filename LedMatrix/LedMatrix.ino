#include "LedControl.h"

LedControl lc=LedControl(12,10,11,1);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames

const int trigPin = 3;
const int echoPin = 2;
long duration;
int distance;

// Put values in arrays
byte invader1a[] =
{
   B00011000,  // First frame of invader #1
   B00111100,
   B01111110,
   B11011011,
   B11111111,
   B00100100,
   B01011010,
   B10100101
};

byte invader1b[] =
{
  B00011000, // Second frame of invader #1
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};

byte invader2a[] =
{
  B00100100, // First frame of invader #2
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100
};

byte invader2b[] =
{
  B00100100, // Second frame of invader #2
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
};

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
//  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
//  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
//  lc.clearDisplay(1);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}


//  Take values in Arrays and Display them
void sinvader1a()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,invader1a[i]);
  }
//  delay(1000);
}

void sinvader1b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,invader1b[i]);
  }
}

void sinvader2a()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,invader2a[i]);
  }
}

void sinvader2b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,invader2b[i]);
  }
}

void loop()
{
// Put #1 frame on both Display
//    sinvader1a();
//    delay(delayTime);
//    sinvader1b();
//    delay(delayTime);
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
 if (distance < 30){
    sinvader1a();
    delay(delayTime);
 }
 else{
  sinvader1b();
  delay(delayTime);
 }
  Serial.print("Distance: ");
  Serial.println(distance);


// Put #2 frame on both Display
//    sinvader1b();
//    delay(delayTime);
//    sinvader2b();
//    delay(delayTime);

}
