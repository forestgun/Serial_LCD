// 
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 0023 chipKIT MPIDE 0023 Library
// ----------------------------------
//
//  energy_main.pde
//  Sketch 
//  ----------------------------------
//  Developed with embedXcode
//
// Apr 28, 2012 release 101
// See README.txt
//
// © Rei VILO, 2010-2012
//   CC = BY NC SA
//   http://embeddedcomputing.weebly.com/serial-lcd.html
//   http://github.com/rei-vilo/Serial_LCD
//
// For 
//   4D Systems Goldelox and Picaso SGC Command Set
//   http://www.4dsystems.com.au/
//
//

// Core library
#if defined (__AVR_ATmega328P__) || defined (__AVR_ATmega2560__) // Arduino specific
#include "WProgram.h" // — for Arduino 0023
// #include  "Arduino.h" // — for Arduino 1.0
#elif defined(__32MX320F128H__) || defined(__32MX795F512L__) // chipKIT specific 
#include "WProgram.h"
#elif defined(__AVR_ATmega644P__) // Wiring specific
#include "Wiring.h"
#elif defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) // LaunchPad specific
#include "Energia.h"
#endif

// Include application, user and local libraries
#include "proxySerial.h"
#include "Serial_LCD.h"
#include "Energy.h"
#include "GUI.h"

// Define variables and constants
ProxySerial myPort(&Serial1);
Serial_LCD myLCD(&myPort);
Energy myEnergy;
uint32_t ui;
button b3;

// Add setup code 
void setup() {                
  Serial.begin(9600);
  Serial.print("\n\n\n***\n");

  Serial1.begin(9600);
  myLCD.begin(4);
  myLCD.setTouch(true);

  myLCD.setFontSolid(true);    
  myLCD.setFont(0);
  myLCD.gText( 0, 210, myLCD.WhoAmI());

  b3.dStringDefine(&myLCD, 240, 160, 60, 40, "Stop",   whiteColour, redColour);
  b3.enable(true);
  b3.draw();

  myEnergy.begin(&myLCD, 2000);
  ui = millis();
}

uint8_t c;
uint16_t x, y;

// Add loop code 
void loop() {
  myLCD.setFontSolid();
  myLCD.setFont(1);
  myLCD.gText(0, 0, ftoa(millis()-ui, 0, 6));

  c = myLCD.getTouchActivity();
  myEnergy.check( c );

  if ( c ) {
    myLCD.getTouchXY(x, y);
    myLCD.setFont(0);
    myLCD.gText(200, 0,  ftoa(x, 0, 5), greenColour); 
    myLCD.gText(200, 15, ftoa(y, 0, 5), redColour); 

    // quit
    if (b3.check()) {
      myLCD.off();
      Serial.print("\n END");
      while(true);
    }

    ui = millis();
  }

}

