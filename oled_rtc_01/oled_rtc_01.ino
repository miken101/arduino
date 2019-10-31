/* This code works with DS3231 RTC module and OLED display
 * It shows a format of date and time in the OLED screen and some cases the temperature too
 * Refer to www.Surtrtech.com for more details
 * This is Code #1 of the tutorial 
 */

#include <SPI.h> //i2c and the display libraries + DS3231
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); //Declaring the display name (display)
RTC_DS3231 rtc;


void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Start the OLED display
  if (! rtc.begin()) {
    display.print("Couldn't find RTC");
    while (1);
      }
  if (rtc.lostPower()) {
    display.print("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  delay(1000); 
  display.clearDisplay();
  display.display();

}

void loop() {                       //This code displays the Time only hours:minutes

DateTime now = rtc.now();
  display.clearDisplay();
  display.setTextSize(2);       //size of the text that will follow              
  display.setTextColor(WHITE);  //its color            
  display.setCursor(1,0);      //position from where you want to start writing           
  printDigits(now.hour()); //text todisplay
  display.print(":");
  printDigits(now.minute());
  display.print(":");
  printDigits(now.second());

  display.setTextSize(1); 
  display.setCursor(1,16);  
  display.print(now.day(), DEC); //text todisplay
  display.print("/");
  display.print(now.month(), DEC);
  display.print("/");
  display.print(now.year(), DEC);

  display.setCursor(1, 24);  
  display.print("Temp: ");
  display.print(rtc.getTemperature());
  display.print(" C");

  display.display();

}
void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    display.print('0');
  display.print(digits);
}
