// 
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 1.0 Library
// ----------------------------------
//
// Apr 09, 2012 release 207
// see README.txt
//
// © Rei VILO, 2010-2012
//   CC = BY NC SA
//   http://embeddedcomputing.weebly.com/serial-lcd.html
//
// For 
//   4D Systems Goldelox and Picaso SGC Command Set
//   http://www.4dsystems.com.au/
//
//
#define PROXYSERIAL_RELEASE 207

#include "Arduino.h"
#include "Stream.h"

// SoftwareSerial 1.0 seems to require a delay
#define securityDelay 2

#ifndef proxy_Serial_h
#define proxy_Serial_h

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
    int8_t available();
    void flush();
    
private:
    uint16_t _millis;
    void _checkSpeed();
    bool _XY16;
    Stream * _proxyPort;
};

#endif





