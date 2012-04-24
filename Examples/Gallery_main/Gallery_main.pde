// 
// Gallery example
//
// 4D Systems μLCD-μLED-μVGA Serial_LCD Library Suite
// Arduino 0023 chipKIT MPIDE 0023 Library
// ----------------------------------
//
// Apr 24, 2012 
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
#include "Serial_LCD.h"
#include "proxySerial.h"
#include "Gallery.h"

// test release
#if GALLERY_RELEASE < 103
#error required GALLERY_RELEASE 103
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

// --- Arduino SoftwareSerial Case - Arduino only
#elif defined (__AVR_ATmega328P__) || defined (__AVR_ATmega328P__)
#include "NewSoftSerial.h"
NewSoftSerial mySerial(2, 3); // RX, TX
ProxySerial myPort(&mySerial);

// --- chipKIT HardwareSerial Case - chipKIT
#elif defined(__PIC32MX__) || defined (__AVR_ATmega2560__)
ProxySerial myPort(&Serial1);

#else
#error Non defined board
#endif 

// === End of Serial port choice ===

Serial_LCD myLCD( &myPort); 

uint16_t x, y;
uint32_t l;
uint8_t a;

Gallery myGallery;


void setup() {
  Serial.begin(19200);
  Serial.print("\n\n\n***\n");

  // === Serial port initialisation ===
#if defined(__I2C_Serial__)
  Serial.print("i2c\n");
  Wire.begin();
  mySerial.begin(9600);

#elif defined(__AVR_ATmega328P__)
  Serial.print("Arduino: NewSoftSerial\n");
  mySerial.begin(9600);

#elif defined(__PIC32MX__) || defined (__AVR_ATmega2560__)
  Serial.print("chipKIT or mega2560: Serial1\n");
  Serial1.begin(9600);

#endif 
  // === End of Serial port initialisation ===

  Serial.print("\n begin 9600");
  myLCD.begin(4);
  Serial.print("\n LCD begin");

  // === Serial port speed change ===
  myLCD.setSpeed(38400);
#if defined(__I2C_Serial__)
  mySerial.begin(38400);

#elif defined(__AVR_ATmega328P__)
  mySerial.begin(38400);

#elif defined(__PIC32MX__) || defined(__AVR_ATmega2560__)
  Serial1.begin(38400);

#endif 
  // === End of Serial port speed change ===
  Serial.print("\n LCD begin 38400");

  Serial.print("\n readScreenGCI initSD");
  Serial.print("\t");
  a =   myLCD.initSD();
  Serial.print(a, HEX);

  Serial.print("\n readScreenGCI checkSD");
  Serial.print("\t");
  a =   myLCD.checkSD();
  Serial.print(a, HEX);

  myLCD.setOrientation(0x03);

  myLCD.setPenSolid(true);
  myLCD.setFontSolid(true);
  myLCD.setFont(0);

  Serial.print("\n readScreenGCI checkScreenType");
  Serial.print("\t");
  a =   myLCD.checkScreenType();
  Serial.print(a, HEX);  

  Serial.print("\n readScreenGCI WhoAmI");
  myLCD.gText( 0, 210, myLCD.WhoAmI());
  delay(500);

  Serial.print("\n readScreenGCI images.Gci");
  Serial.print("\t");
  a = myLCD.findFile("images.gci");
  Serial.print(a, HEX);

  Serial.print("\n readScreenGCI images.Dat");
  Serial.print("\t");
  a = myLCD.findFile("images.dat");
  Serial.print(a, HEX);

  Serial.print("\n myGallery.begin(images)");
  Serial.print("\t");
  a = myGallery.begin(&myLCD, "images");
  Serial.print(a, DEC);
  Serial.print(" images");

  Serial.print("\n > ");
  Serial.print(Serial1.available(), DEC);

  if ( a==0 ) {
    Serial.print("\n images not available");
    Serial.print("\n *** end");
    myLCD.off();
    while( true );
  }

  Serial.print("\n readScreenGCI setTouch");
  Serial.print("\t");
  a = myLCD.setTouch(true);
  Serial.print(a, HEX);  

  //  Serial.print("* readTextFile");
  //  Serial.print("\n");

  //  a = myLCD.readTextFile("images.dat", 7, callbackReadFile);
  //  Serial.print("* ");
  //  Serial.print(a, HEX);
  //  Serial.print("\n");

  //  a = myLCD.openTextFileDelimiter("images.dat", '\n', callbackReadFile);
  //  Serial.print("* ");
  //  Serial.print(a, HEX);
  //  Serial.print("\n");


  //  a = myLCD.readScreenFAT("160.gci");
  //  Serial.print(a, HEX);
  //  Serial.print("\n");
  //  delay(10000);

  Serial.print("\n > ");
  Serial.print(Serial1.available(), DEC);

}

uint8_t c;

void loop() {

  Serial.print("\n ... ");
  c = myLCD.getTouchActivity();
  Serial.print(c, HEX);
  if (c>0) {
    myLCD.off();
    while(true);
  }


  Serial.print("\n showNext (");
  a = myGallery.showNext();
  Serial.print(myGallery.index(), DEC);
  Serial.print(")\t");
  Serial.print(a, HEX);

  //
  //
  //
  //  myLCD.setFont(0);
  //  myLCD.setFontSolid(true);
  //  myLCD.gText( 250, 225, 0xffff, ftoa(millis()-l, 0, 6));
  //  l=millis();
  delay(3000);
}




