#include <Wire.h>


#include <hd44780.h>

/* @file lcd_new.ino
|| @version 1.0
|| @author Elrohi Filmon
|| @contact elrohidevb@gmail.com
||
|| @description
|| | Demonstrates how we can use the I2C crystal display.
|| #
*/

#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header

hd44780_I2Cexp lcd; // declare lcd object: auto locate & auto config expander chip

// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
byte heart[8] = {0b00000, 0b01010, 0b11111, 0b11111, 0b11111, 0b01110, 0b00100, 0b00000}; 
byte armsDown[8] = { 0b00100, 0b01010, 0b00100, 0b00100, 0b01110, 0b10101, 0b00100, 0b01010};

void setup()
{
int status;

  // initialize LCD with number of columns and rows: 
  // hd44780 returns a status from begin() that can be used
  // to determine if initalization failed.
  // the actual status codes are defined in <hd44780.h>
  // See the values RV_XXXX
  //
  // looking at the return status from begin() is optional
  // it is being done here to provide feedback should there be an issue
  //
  // note:
  //  begin() will automatically turn on the backlight
  // 
  
  lcd.createChar(0, heart);
  lcd.createChar(3, armsDown); 
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if(status) // non zero status means it was unsuccesful
  {
    // hd44780 has a fatalError() routine that blinks an led if possible
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }

  // initalization was successful, the backlight should be on now

  // Print a message to the LCD'
  
 
  lcd.setCursor(0, 0);
  lcd.write("I am working don't worry");
}

void loop() {}
