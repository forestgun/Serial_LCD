// 
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 0023 chipKIT MPIDE 0023 Wiring 1.0
// ----------------------------------
//
// May 01, 2012 release 111
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
#define GUI_RELEASE 111

#ifndef GUI_h
#define GUI_h

// Core library
#if defined (__AVR_ATmega328P__) || defined(__AVR_ATmega2560__) // Arduino specific
#include "WProgram.h"	
#elif defined(__32MX320F128H__) || defined(__32MX795F512L__) // chipKIT specific 
#include "WProgram.h"
#elif defined(__AVR_ATmega644P__) // Wiring specific
#include "Wiring.h"
#elif defined(__MSP430G2452__) || defined(__MSP430G2553__) || defined(__MSP430G2231__) // LaunchPad specific
#include "Energia.h"
#elif defined(MCU_STM32F103RB) || defined(MCU_STM32F103ZE) || defined(MCU_STM32F103CB) || defined(MCU_STM32F103RE) // Maple specific
#include "WProgram.h"	
#endif

// Other libraries
#include "Serial_LCD.h"

// Test release
#if SERIAL_LCD_RELEASE < 129
#error required SERIAL_LCD_RELEASE 129
#endif


// Item
struct item {
    uint16_t index;
    char label[16];
};

item setItem(uint8_t index0, String text0);

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))


// Button
class button {
public:
    button();
    
    // item-based button
    void  define(Serial_LCD * lcd0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, item item0, uint16_t textColour1, uint16_t highColour1);
    void dDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, item item0, uint16_t textColour1, uint16_t highColour1);
    void  define(Serial_LCD * lcd0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, item item0, uint16_t textColour1, uint16_t highColour1, uint16_t lowColour1, uint8_t size0);
    void dDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, item item0, uint16_t textColour1, uint16_t highColour1, uint16_t lowColour1, uint8_t size0);
    
    // string-based button
    void  stringDefine(Serial_LCD * lcd0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, String text0, uint16_t textColour1, uint16_t highColour1);
    void dStringDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, String text0, uint16_t textColour1, uint16_t highColour1);
    void  stringDefine(Serial_LCD * lcd0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, String text0, uint16_t textColour1, uint16_t highColour1, uint16_t lowColour1, uint8_t size0);
    void dStringDefine(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, String text0, uint16_t textColour1, uint16_t highColour1, uint16_t lowColour1, uint8_t size0);
    
    boolean state();
    void draw(boolean b1=false);
    void enable(boolean b1=true); 
    boolean check(boolean instant=false);
    uint16_t getIndex();
    
private:
    uint16_t _x1, _y1, _x2, _y2, _xt, _yt;
    uint16_t _textColour, _highColour, _lowColour;
    boolean _enable;  
    String _text;
    uint16_t _index;
    uint8_t _size;
    Serial_LCD * _pscreen;
};


// Dialog box
// kind0 = icon
// default = green + ; 1 = blue ! ; 2 = yellow ? ; 3 = red X
// option: button2
// option: button2, button3
uint8_t dialog(Serial_LCD * lcd0, String text0, uint8_t kind0, uint16_t textColour0, uint16_t highColour0, uint16_t lowColour0, String text1, String button1, uint16_t textColour1, uint16_t highColour1, uint16_t lowColour1, String text2="\0", String button2="\0", uint16_t textColour2=0, uint16_t highColour2=0, uint16_t lowColour2=0, String text3="\0", String button3="\0", uint16_t textColour3=0, uint16_t highColour3=0, uint16_t lowColour3=0);


// Menu
uint16_t menu(Serial_LCD * lcd0, item menuItem0[], uint8_t nItems0, uint16_t textColour0, uint16_t highColourMain0, uint16_t highColourSub0);


// Label
void dLabel(Serial_LCD * lcd0, uint16_t x0, uint16_t y0, uint16_t dx, uint16_t dy, String text0, uint16_t textColour0=whiteColour, uint16_t backColour0=blackColour, uint8_t horizontal0=0, uint8_t vertical0=0, uint8_t size0=9);
void  label(Serial_LCD * lcd0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, String text0, uint16_t textColour0=whiteColour, uint16_t backColour0=blackColour, uint8_t horizontal0=0, uint8_t vertical0=0, uint8_t size0=9);


// Slider
// output = true when OK, output = false when Cancel
boolean slider(Serial_LCD * lcd0, uint16_t &value, uint16_t min=0, uint16_t max=511, uint16_t step=8, uint16_t minColour0=greenColour, uint16_t maxColour0=redColour, String okText0="OK", uint16_t okTextColour0=whiteColour, uint16_t okColour0=blueColour, String cancelText0="Cancel", uint16_t cancelTextColour0=whiteColour, uint16_t cancelColour0=yellowColour);

#endif










