//
// SC16IS750 I2C slave bridge to serial
// Arduino + chipKIT Library
//
// May 01, 2012 release 105
// see README.txt
//
// © Rei VILO, 2010-2012
//   CC = BY NC SA
//   http://embeddedcomputing.weebly.com/serial-lcd.html
//   http://github.com/rei-vilo/Serial_LCD
//
//
#define I2C_SERIAL_RELEASE 105

#ifndef I2C_Serial_h
#define I2C_Serial_h

#include "WProgram.h"
#include "Stream.h"
#include "Wire.h"

// I2C_Serial() or 
// I2C_Serial(0)  : _address=0x48; : a0/a1=+/+ : default I2C serial port
// I2C_Serial(1)  : _address=0x49; : a0/a1=-/+ : secondary I2C serial port
// I2C_Serial(2)  : _address=0x4c; : a0/a1=+/- : RFID ID-2 sensor board
// I2C_Serial(12) : _address=0x4d; : a0/a1=-/- : RFID ID-12 sensor board
#define ALL  0xff


class I2C_Serial : public Stream {
public:
    I2C_Serial(uint8_t b=0); // 2 for ID2 or 12 for ID12, default = 0, 1 otherwise
    String WhoAmI();
    void begin(long b=9600);
    
    // write and read functions
    virtual void write(uint8_t byte);
    virtual int read();
    
    // management functions
    virtual int available();
    virtual void flush();
    virtual int peek(); // !
    uint8_t free();       // TX
    
    // tests functions
    boolean test();
    void loopback(boolean b=true);
    
    // I/O functions
    void pinMode(uint8_t pin, uint8_t mode); // pin=0..7, mode=0=INPUT or 1=OUPUT; pin=ALL, mode=bit map
    void digitalWrite(uint8_t pin, uint8_t val); // pin=0..7, val=0=LOW or 1=HIGH; ; pin=ALL, val=bit map
    int digitalRead(uint8_t pin); // pin=0..7, LOW or HIGH; pin=ALL, bit map
	void reset(uint8_t pin, uint8_t val=LOW, uint8_t ms=10); // pin=0..7, reset val=0=LOW or 1=HIGH; ; pin=ALL, val=bit map
    
    
private:
    int8_t _address;
};

#endif




