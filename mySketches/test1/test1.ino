#include <Adafruit_NeoPixel.h>

#define LED_PIN 2
#define LED_COUNT 28
#define LED_BRIGHT 64
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

unsigned long myDelay = 10 ;

void setup() {
  strip.begin();
  strip.setBrightness(LED_BRIGHT);
  strip.show(); // Initialize all pixels to 'off'
}


void loop() {

      for(int j=0;j<256;j++){
          for(int i=0;i<strip.numPixels();i++){
            strip.setPixelColor(i, strip.Color(j,0,255)); 
            strip.show();
            delay(myDelay);
            }
      }
       for(int j=0;j<256;j++){
          for(int i=0;i<strip.numPixels();i++){
            strip.setPixelColor(i, strip.Color(255,j,255)); 
            strip.show();
            delay(myDelay);
            }
      }
      for(int j=255;j>=0;j--){
          for(int i=0;i<strip.numPixels();i++){
            strip.setPixelColor(i, strip.Color(255,j,255)); 
            strip.show();
            delay(myDelay);
            }
      }
      for(int j=255;j>=0;j--){
        for(int i=0;i<strip.numPixels();i++){
            strip.setPixelColor(i, strip.Color(j,0,255)); 
            strip.show();
            delay(myDelay);
            }
      }
}
