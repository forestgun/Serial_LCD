//
//  slider_main.pde
//  Sketch 
//  ----------------------------------
//  Developed with embedXcode
//
//  Project slider_main
//  Created by Rei VILO on 20/04/12
//  Copyright (c) 2012 http://embeddedcomputing.weebly.com
//

// Core library
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega2560__) // Arduino specific
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
#include "GUI.h"

// Test release
#if GUI_RELEASE < 109
#error required GUI_RELEASE 109
#endif

// Define variables and constants
ProxySerial myPort(&Serial1);
Serial_LCD	myLCD(&myPort);
uint16_t ui=255;
button b1;
button b2;

// Add setup code 
void setup() {                
    Serial.begin(9600);
    Serial.print("\n\n\n***\n");
    
    Serial1.begin(9600);
    myLCD.begin(4);
    myLCD.initSD();
    myLCD.setOrientation(3);
    
    myLCD.setFont(0);
    myLCD.gText(0, myLCD.maxY()-15, myLCD.WhoAmI());    
    
    myLCD.setTouch(true);
    
    b1.dDefine(&myLCD, 0, 0, 60, 40, setItem(101, "Stop"), whiteColour, redColour);
	b2.dDefine(&myLCD, 0, 80, 60, 40, setItem(102, "Define"), whiteColour, grayColour);
	dLabel(&myLCD, 60, 40, 60, 40, ftoa(ui));
    Serial.print("\r\n > "+ ftoa(ui));
    
    b1.enable(true);
	b2.enable(true);
    b1.draw();
    b2.draw();
}

// Add loop code 
void loop() {
    
    if ( myLCD.getTouchActivity() ) {
        if ( b1.check() ) {
            myLCD.off();
            while (true);
        } else if ( b2.check() ) {
			if (slider(&myLCD, ui)) {
                dLabel(&myLCD, 60, 40, 60, 40, ftoa(ui));
                Serial.print("\r\n > "+ ftoa(ui));
            } 
        } else {
            delay(100);
        }        
    }
}
