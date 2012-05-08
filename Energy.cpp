// 
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 0023 chipKIT MPIDE 0023 Wiring 1.0
// ----------------------------------
//
//  Energy.cpp 
//  Library C++ code
//  ----------------------------------
//  Developed with embedXcode
//
// May 01, 2012 release 103
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

// Library header
#include "Energy.h"

// Code
Energy::Energy() {
}

void Energy::begin(Serial_LCD * lcd0, uint32_t seconds) {
	_pscreen = lcd0;
    _ms = (uint32_t)seconds*1000;
    _chrono = millis();
    _state = true; // backlight on
}

void Energy::check(boolean &b) {
    if ( b ) {
        _chrono = millis();
        if ( _state==false ) {
            _state = true;
            _pscreen->setBacklight(true); 
            b = 0;
        }
    } else if ( (_state==true) & (millis()>_chrono+_ms) ) {
        _state = false;
        _pscreen->setBacklight(false);   
    }
}