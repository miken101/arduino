
// StrandTest from AdaFruit implemented as a state machine
// pattern change by push button
// By Mike Cook Jan 2016

#define PINforControl   2 // pin connected to the small NeoPixels strip
#define NUMPIXELS1      60 // number of LEDs on strip

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS1, PINforControl, NEO_GRB + NEO_KHZ800);

unsigned long patternInterval = 20 ; // time between steps in the pattern
unsigned long lastUpdate = 0 ; // for millis() when last update occoured
unsigned long intervals [] = { 20, 20 } ; // speed for each pattern
const byte button = 3; // pin to connect button switch to between pin and ground

void setup() {
  strip.begin(); // This initializes the NeoPixel library.
   strip.setBrightness(64);
  wipe(); // wipes the LED buffers
  pinMode(button, INPUT_PULLUP); // change pattern button
}

void loop() {
  static int pattern = 0, lastReading;
  int reading = digitalRead(button);
  if(lastReading == HIGH && reading == LOW){
    pattern++ ; // change pattern number
    if(pattern > 1) pattern = 0; // wrap round if too big
    patternInterval = intervals[pattern]; // set speed for this pattern
    wipe(); // clear out the buffer 
    delay(50); // debounce delay
  }
  lastReading = reading; // save for next time

if(millis() - lastUpdate > patternInterval) updatePattern(pattern);
}

void  updatePattern(int pat){ // call the pattern currently being created
  switch(pat) {
    case 0:
         colorWipeLeft(strip.Color(255, 100, 0)); // orange
         break;     
    case 1:
         colorWipeRight(strip.Color(255, 100, 0)); // orange
         break;     
  }  
}


void colorWipeLeft(uint32_t c) { // modified from Adafruit example to make it a state machine
  static int l = 0;
    strip.setPixelColor(l, c);
    strip.setPixelColor(l - 10, 0);
    strip.show();
  l++;
  if(l >= strip.numPixels()){
    l = 0;
    wipe(); // blank out strip
  }
  lastUpdate = millis(); // time for next change to the display
}

void colorWipeRight(uint32_t c) { // modified from Adafruit example to make it a state machine
  static int r = strip.numPixels();
    strip.setPixelColor(r, c);
        strip.setPixelColor(r + 10, 0);
    strip.show();
  r--;
  if(r <= 0){
    r = strip.numPixels();
    wipe(); // blank out strip
  }
  lastUpdate = millis(); // time for next change to the display
}

void wipe(){ // clear all LEDs
     for(int i=0;i<strip.numPixels();i++){
       strip.setPixelColor(i, strip.Color(0,0,0)); 
       }
}
