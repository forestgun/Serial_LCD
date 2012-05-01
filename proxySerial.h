// 
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 0023 chipKIT MPIDE 0023 Wiring 1.0
// ----------------------------------
//
// May 01, 2012 release 108
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
#define PROXYSERIAL_RELEASE 108

#ifndef proxy_Serial_h
#define proxy_Serial_h

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
#include "Stream.h"

const uint32_t securityDelay = 0;

// Utilities
// float to string
String ftoa(float number, uint8_t precision=0, uint8_t size=0);

// hex to string
String htoa(uint32_t number, uint8_t size=0);

// time is ms to string
String ttoa(float number, uint8_t precision=0, uint8_t size=0);

// Objects

class ProxySerial
{
public:
    ProxySerial(Stream * port0);
    
    void begin(uint16_t b);  // to be managed at serial port level
    void setXY16(boolean b);
    void print(int8_t i);
    void print(uint8_t ui);
    void print(int16_t i);
    void print(uint16_t ui);
    void printXY(int16_t i);
    void printXY(uint16_t ui);
    void print(char c);
    void print(String s);
    
    uint8_t read();
    uint16_t read16();
    int8_t available();
    void flush();
    
private:
    uint16_t _millis;
    void _checkSpeed();
    boolean _XY16;
    Stream * _proxyPort;
};

#endif





