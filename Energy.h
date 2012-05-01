// 
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 0023 chipKIT MPIDE 0023 Wiring 1.0
// ----------------------------------
//
//  Energy.h 
//  Library header
//  ----------------------------------
//  Developed with embedXcode
//
// Apr 29, 2012 release 102
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

#define ENERGY_RELEASE 101

#ifndef Energy_h
#define Energy_h

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

// Test release
#if SERIAL_LCD_RELEASE < 126
#error required SERIAL_LCD_RELEASE 126
#endif

class Energy {
public:
    Energy();
    void begin(Serial_LCD * lcd0, uint32_t ms=1000);
    void check(boolean &b);
    
private:
    Serial_LCD * _pscreen;
    uint32_t _ms;
    uint32_t _chrono;
    boolean _state;
};



#endif
