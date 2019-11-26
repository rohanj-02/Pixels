/*  
 *   Play pong on an 8x8 matrix - project from itopen.it
 */
 
#include "LedControl.h"


LedControl lc = LedControl(12,11,10,1);


void start() {
    lc.clearDisplay(0);
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            lc.setLed(0, r, c, HIGH);
            delay(50);
        }
    }
    delay(1500);
    lc.clearDisplay(0);
}

int matrix[24][32];


void update(){

    for (int i = 0; i < 24; ++i) {
      for (int j = 0; j < 32; ++j){
        if (matrix[i][j] == 1){
           if (r < 8) {
              lc.setLed(c/8, r, c%8, HIGH);
           }else if (r >= 8 && r < 16) {
              lc.setLed(7 - c/8, r - 8, 7 - c%8, HIGH);
           }else {
              lc.setLed(8 + c/8, r - 16, c % 8);
           }
        } 
     }
  }
  
}

void setup() {
  // The MAX72XX is in power-saving mode on startup,
  // we have to do a wakeup call
  pinMode(11, INPUT);

  lc.shutdown(0,false);
  // Set the brightness to a medium values
  lc.setIntensity(0, 8);
  // and clear the display
  lc.clearDisplay(0);


  for (int i = 0; i < 24; ++i) {
     for (int j = 0; j < 32; ++j)
        matrix[i][j] = 0; 
  }

  start();
}

void bar(int c, int start) {

    for (int i = start; i < 24 - start; ++i) {
        matrix[i][c] = 1;
        matrix[i][c + 1] = 1;
    }
    
}

int height = 0;

void loop() {
   
    update();

    bar(4, 13);
    bar(8, 9);
    bar(16, 5);
    bar(24, 9);
    bar(28, 13);
    delay(1000);
}
