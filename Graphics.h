// 
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 0023 chipKIT MPIDE 0023 Wiring 1.0
// ----------------------------------
//
// May 01, 2012 release 109
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
#define GRAPHICS_RELEASE 108

#ifndef Graphics_h
#define Graphics_h

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
#if SERIAL_LCD_RELEASE < 128
#error required SERIAL_LCD_RELEASE 128
#endif

class gClock {
public:
    gClock();
    
    void dDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, uint16_t backColour=blackColour, uint16_t frontColour=greenColour, uint16_t hourColour=redColour, uint16_t minuteColour=blueColour, uint16_t secondColour=yellowColour);
    void define(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t backColour=blackColour, uint16_t frontColour=greenColour, uint16_t hourColour=redColour, uint16_t minuteColour=blueColour, uint16_t secondColour=yellowColour);
    void draw(uint8_t hour, uint8_t minute, uint8_t second);
    
private:
    Serial_LCD * _pscreen;
    uint16_t _x0, _y0, _radius;
    uint16_t _backColour, _frontColour;
    uint16_t _hourColour, _minuteColour, _secondColour;
    uint8_t _oldHour, _oldMinute, _oldSecond;
};


class gYaw {
public:
    gYaw();
    void dDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour);
    void define(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour);
    void draw(float degrees);
    
private:
    Serial_LCD * _pscreen;
    uint16_t _x0, _y0, _radius;
	uint16_t _backColour, _frontColour, _gridColour, _valueColour;
    float _oldDegrees;
};


class gPitch {
public:
	gPitch();
	void dDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour);
	void define(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour);
	void draw(float degrees);
	
private:
	Serial_LCD * _pscreen;
	uint16_t _x0, _y0, _radius;
	uint16_t _backColour, _frontColour, _gridColour, _valueColour;
	float _oldDegrees;
};


class gRoll {
public:
	gRoll();
	void dDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour);
	void define(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t radius, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour);
	void draw(float degrees);
	
private:
	Serial_LCD * _pscreen;
	uint16_t _x0, _y0, _radius;
	uint16_t _backColour, _frontColour, _gridColour, _valueColour;
	float _oldDegrees;
};


class gHistogram {
public:
    gHistogram();
    void dDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, float valueMin, float valueMax, uint32_t lapse=0, uint16_t memory=8, uint16_t gridX=4, uint16_t gridY=0, boolean continous=false, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour, uint16_t minColour=greenColour, uint16_t maxColour=redColour);
    void define(Serial_LCD * lcd0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, float valueMin, float valueMax, uint32_t lapse=0, uint16_t memory=8, uint16_t gridX=4, uint16_t gridY=0, boolean continous=false, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour, uint16_t minColour=greenColour, uint16_t maxColour=redColour);
    void draw(float value);
    
private:
    Serial_LCD * _pscreen;
    uint16_t _x0, _y0, _dx, _dy;
    float _valueMin, _valueMax;
    uint16_t _min, _max;
    uint16_t _n, _amnesiaMin, _amnesiaMax;
    boolean _continous; 
    uint16_t _lapse, _memory, _gridX, _gridY, _gridC;
    uint16_t _backColour, _frontColour, _gridColour, _valueColour, _minColour, _maxColour;
    uint32_t _chrono;
};


class gGauge {
public:
    gGauge();
    void define(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t radius, float valueMin, float valueMax, uint16_t memory=8, uint16_t grid=8, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour, uint16_t minColour=greenColour, uint16_t maxColour=redColour);
    void dDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, float valueMin, float valueMax, uint16_t memory=8, uint16_t grid=8, uint16_t backColour=blackColour, uint16_t frontColour=whiteColour, uint16_t gridColour=yellowColour, uint16_t valueColour=blueColour, uint16_t minColour=greenColour, uint16_t maxColour=redColour);
    void draw(float value, String sValue="");
    
private:
    Serial_LCD * _pscreen;
    uint16_t _x0, _y0, _dx, _dy, _radius;
    float _valueMin, _valueMax, _oldZ;
    float _min, _max;
    uint16_t _n, _amnesiaMin, _amnesiaMax;
    uint32_t _lapse;
    uint16_t _memory, _grid;
    uint16_t _backColour, _frontColour, _gridColour, _valueColour, _minColour, _maxColour;
};

#endif


