#include <LiquidCrystal.h>
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_DATA4, LCD_DATA5, LCD_DATA6, LCD_DATA7);


//--[Hardware MIDI]-------------
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
//------------------------------

void setup() {

  MIDI.setHandleNoteOn(myNoteOn);
  MIDI.setHandleNoteOff(myNoteOff);
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();

  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleNoteOff(myNoteOff);

  //usbMIDI.sendNoteOn(40, 99, 0);
  //delay(100);
  //usbMIDI.sendNoteOff(40, 0, 0);
 
    
  // Serial for debugging
  Serial.begin(9600);
    
  // set up the LCD's number of columns and rows: 
  lcd.begin(40, 2);
  // Print a message to the LCD.
  lcd.print("Hello World");
  
  // IO CLOCK PIN
  pinMode(IO_CLOCK, OUTPUT);  

  // Pins for LED shift
  pinMode(LED_LATCH, OUTPUT);
  pinMode(LED_DATA, OUTPUT); 
  
  // Pins for SWITCH shift
  pinMode(SW_LATCH, OUTPUT);
  pinMode(SW_DATA, INPUT);


// lightshow
  clearLEDs();
  delay(FLASHSPEED);
  lightLEDs();
  delay(FLASHSPEED);

  clearLEDs();
  delay(FLASHSPEED);
  lightLEDs();
  delay(FLASHSPEED);

  clearLEDs();
  delay(FLASHSPEED);
  lightLEDs();
  delay(500);

  clearLEDs();
  delay(FLASHSPEED);
  
}
