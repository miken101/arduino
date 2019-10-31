#include <Adafruit_NeoPixel.h>

#define LED_PIN 2
#define LED_COUNT 60
#define LED_BRIGHT 64
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(LED_BRIGHT);
  strip.show(); // Initialize all pixels to 'off'
}

uint32_t red = strip.Color(255, 0, 0);

void loop() {
  colorWipe_smart(red);
}

void colorWipe_smart(uint32_t color) {
  static uint8_t wait = 50;
  static unsigned long lastUpdate = 0;
  static uint16_t currentLed = 0;
  
  unsigned long now = millis();
  if (now > lastUpdate+delay) {
    strip.setPixelColor(currentLed, color);
    strip.show();    
    currentLed = currentLed>strip.numPixels() ? 0 : currentLed+1;
    lastUpdate = now;
  }
}
