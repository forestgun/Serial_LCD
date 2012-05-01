// 
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 0023 chipKIT MPIDE 0023 Wiring 1.0
// ----------------------------------
//
// May 01, 2012 release 104
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
#define GALLERY_RELEASE 104

#ifndef Gallery_h
#define Gallery_h

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

// Other libraries
#include "Serial_LCD.h"
#include "vector_t.h"

// Test release
#if SERIAL_LCD_RELEASE < 128
#error required SERIAL_LCD_RELEASE 128
#endif

class Gallery {
public:
    Gallery(); // constructor
    ~Gallery(); // destructor
    uint8_t begin(Serial_LCD * lcd0, String name);
    uint8_t number();
    uint8_t index();
    uint8_t showNext();
    uint8_t showPrevious();
    uint8_t showImage(uint8_t i=0);
    
private:
    struct image_t {
        //    String name;
        uint16_t msb, lsb, x, y;
    };
    
    Serial_LCD * _pscreen;
    String _name;
    uint8_t _index;
    Vector_t <image_t> _gallery;
};


#endif
