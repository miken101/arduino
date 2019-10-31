#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    60
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

}
void loop() {
  for (int i = 0; i <= 59; i++) {
    leds[i] = CRGB ( 0, 0, 0);
    FastLED.show();}
}
