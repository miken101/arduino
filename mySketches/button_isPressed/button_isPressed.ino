#include <Button.h>
/*
create a Button object at pin 12
connect button between pin 12 and GND
*/
Button button = Button(3,BUTTON_PULLUP);
 
void setup(){
  pinMode(13,OUTPUT); //debug to led 13
}
 
void loop(){
  if(button.isPressed()){
        digitalWrite(13,LOW);
  }else{
        digitalWrite(13,HIGH);
  }
}
