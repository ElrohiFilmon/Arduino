/* @file encoder_with_lcd.ino
|| @version 1.0
|| @author ELrohi Filmon
|| @contact elrohifilmon@gmail.com
||
|| @description
|| | Demonstrates how we can use a rotary encoder with a I2C crystal lcd display.
|| #
*/

#include <Wire.h>
#include <hd44780.h>                       // main hd44780 header
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header
// Rotary Encoder Inputs
const int encoderPinA = 3;
const int encoderPinB = 2;

int angle = 0;

int encoderPos = 0;
ßint encoderStepsPerRevolution = 16;
boolean encoderALast = LOW;  //remembers the previous state of the encoder pin A

hd44780_I2Cexp lcd; // declare lcd object: auto locate & auto config expander chip

// LCD geometry
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

void setup()
{

  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  digitalWrite(encoderPinA, HIGH);
  digitalWrite(encoderPinB, HIGH);
  Serial.begin(9600);
int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if(status) // non zero status means it was unsuccesful
  {
    hd44780::fatalError(status); // does not return
  }
}

void loop() {
  boolean encoderA = digitalRead(encoderPinA);

  if ((encoderALast == HIGH) && (encoderA == LOW)) {
    if (digitalRead(encoderPinB) == LOW) {
      encoderPos--;
    } else {
      encoderPos++;
    }
    angle = (encoderPos % encoderStepsPerRevolution) * 360 / encoderStepsPerRevolution;
    lcd.setCursor(0,0);
    lcd.print("Angle: ");
    lcd.print(angle);
    lcd.setCursor(0,1);
    lcd.print("Counter: ");
    lcd.print(encoderPos);

  }
  encoderALast = encoderA;
  }
  
