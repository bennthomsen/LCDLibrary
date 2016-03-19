/*
  Example code demonstrating the use of the LCD library for writing characters to
  the MIDIS 16x2 LCD display.  
*/  

#include "LCDdriver.h"

LCD mylcd(0x3E);    //Create LCD object

char data;

void setup()
{
  mylcd.init();
  Serial.begin(9600);
  mylcd.backLight(500);
  mylcd.writeString("Ready to Rx now");
  mylcd.writeString(":");
  mylcd.lineFeed();
  mylcd.blinkOn();
}

void loop()
{
  if (Serial.available()) {
    while (Serial.available() > 0) {
      //Write each character to mylcd
      data = Serial.read();
      switch (data){
        case 8:                  //Backspace
          mylcd.backSpace();
        break;
        case 13:
        break;
        case 10:                 //Carriage return
          mylcd.lineFeed();
        break;
        case 0x1C:               //Back Arrow
        mylcd.back();
        break;
        case 0x1D:               //Forward Arrow
        mylcd.forward();
        break;
        case 0x1E:               //Up Arrow
        mylcd.up();
        break;
        case 0x1F:               //Down Arrow
        mylcd.down();
        break;
        default:
        mylcd.writeString(data); //Write character
      }
    }
  } 
}
