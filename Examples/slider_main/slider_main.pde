//
//  GUI_main.pde
//  Sketch 
//  ----------------------------------
//  Developed with embedXcode
//
//  Project GUI_main
//  Created by Rei VILO on 25/04/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
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
#include "Wire.h"
#include "proxySerial.h"
#include "Serial_LCD.h"
#include "GUI.h"

// test release
#if GUI_RELEASE < 109
#error required GUI_RELEASE 109
#endif

// === Serial port choice ===

// uncomment for I2C serial interface
//#define __I2C_Serial__

// --- I2C Case -
#if defined(__I2C_Serial__)
#include "Wire.h"
#include "I2C_Serial.h"
I2C_Serial mySerial(0);
ProxySerial myPort(&mySerial);

// --- Software Serial Case
#elif defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328P__)
#include "NewSoftSerial.h"
NewSoftSerial mySerial(2, 3); // RX, TX
ProxySerial myPort(&mySerial);

// --- Hardware Serial Case
#elif defined(__PIC32MX__) || defined(__AVR_ATmega2560__)
ProxySerial myPort(&Serial1);

#else
#error Non defined board
#endif 

// === End of Serial port choice ===


// Define variables and constants
Serial_LCD myLCD( &myPort); 
uint16_t x, y;
uint32_t l;
button b2, b3;
uint16_t ui=255;



// Add setup code 
void setup() {
  Serial.begin(9600);
  Serial.print("\n\n\n***\n");

  // === Serial port initialisation ===
#if defined(__I2C_Serial__)
  Serial.print("i2c Serial\n");
  Wire.begin();
  mySerial.begin(9600);

#elif defined(__AVR_ATmega328P__) 
  Serial.print("Software Serial\n");
  mySerial.begin(9600);

#elif defined(__32MX320F128H__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega644P__)
  Serial.print("Hardware Serial\n");
  Serial1.begin(9600);

#endif 
  // === End of Serial port initialisation ===

  myLCD.begin(4);  // 9600 at start-up

  // === Serial port speed change ===
  if (false) {
    myLCD.setSpeed(38400);

#if defined(__I2C_Serial__)
    mySerial.begin(38400);

#elif defined(__AVR_ATmega328P__) 
    mySerial.begin(38400);

#elif defined(__PIC32MX__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega644P__)
    Serial1.begin(38400);

#endif 
  }
  // === End of Serial port speed change ===

  myLCD.setOrientation(0x03);

  myLCD.initSD();

  myLCD.setPenSolid(true);
  myLCD.setFontSolid(true);    
  myLCD.setFont(0);
  myLCD.gText( 0, 210, myLCD.WhoAmI());

  myLCD.setTouch(true);

  //    myLCD.setFont(3);
  //    myLCD.gText(0,  0, "         1         2    ");
  //    myLCD.gText(0, 20, "12345678901234567890123456"); 
  //    myLCD.gText(0, 60, ftoa(myLCD.fontX(), 0, 8)); 
  //
  //    myLCD.setFont(2);
  //    myLCD.gText(0,  80, "         1         2         3         4");
  //    myLCD.gText(0, 100, "1234567890123456789012345678901234567890"); 
  //    myLCD.gText(0, 120, ftoa(myLCD.fontX(), 0, 8)); 

  myLCD.setFont(1);
  myLCD.gText(0,  0, "         1         2         3         4");
  myLCD.gText(0, 20, "1234567890123456789012345678901234567890"); 
  myLCD.gText(0, 60, ftoa(myLCD.fontX(), 0, 8)); 

  myLCD.setFont(0);
  myLCD.gText(0,  80, "         1         2         3         4         5");
  myLCD.gText(0, 100, "12345678901234567890123456789012345678901234567890123"); 
  myLCD.gText(0, 120, ftoa(myLCD.fontX(), 0, 8)); 

  b2.dStringDefine(&myLCD, 180, 160, 60, 40, "Slider", whiteColour, greenColour);
  b3.dStringDefine(&myLCD, 240, 160, 60, 40, "Stop",   whiteColour, redColour);
  b2.enable(true);
  b3.enable(true);
  b2.draw();
  b3.draw();

  dLabel(&myLCD, 180, 120, 60, 40, ftoa(ui),     greenColour, blackColour, 0, 2, 2);
}

uint8_t c;
boolean b=true;


// Add loop code 
void loop() {

  if ( myLCD.getTouchActivity() ) {
    myLCD.getTouchXY(x, y);
    myLCD.setFont(0);
    myLCD.gText(200, 0,  ftoa(x, 0, 5), greenColour); 
    myLCD.gText(200, 15, ftoa(y, 0, 5), redColour); 

    // slider
    if (b2.check()) {
      if (slider(&myLCD, ui)) {
        dLabel(&myLCD, 180, 120, 60, 40, ftoa(ui), greenColour, blackColour, 0, 2, 2);
        Serial.print("\n slider > \t");
        Serial.print(ftoa(ui));
      } 
    }
    // quit
    else if (b3.check()) {
      myLCD.off();
      Serial.print("\n END");
      while(true);
    }
  }

  myLCD.setFont(0);
  myLCD.setFontSolid(true);
  myLCD.gText( 250, 225, ftoa(millis()-l, 0, 6));
  l=millis();

}




