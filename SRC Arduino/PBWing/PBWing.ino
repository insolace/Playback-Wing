// pruning down code from MIDIALF for actual JONAH hardware/PCB

//********** Define Pins and I/O
#define   LCD_DATA4	  19
#define   LCD_DATA5	  18
#define   LCD_DATA6	  17
#define   LCD_DATA7	  16
#define   LCD_RS	    21
#define   LCD_EN	    20

#define   IO_CLOCK	  11

#define   SW_DATA	    0
#define   SW_LATCH	  22

#define   LED_DATA	  1  // PCB rev 1 this has to be hand wired, oops!
#define   LED_LATCH	  23

#define   MAXBUTTONS  80
#define   OFFSET      24       // offet for MIDI notes

//**********

#define PULSE_WIDTH_USEC   5
#define SW_SLOWDOWN 10  // slowdown in MS
#define FLASHSPEED  100

int led[MAXBUTTONS];       // 80 LEDs
int sw[MAXBUTTONS];        // 80 switches

int swState[MAXBUTTONS];       // 80 switches
int swPrevState[MAXBUTTONS];     // Previous switch state

int noteTran[] = {

  70, 71, 72, 73, 74, 75, 76, 77, 78, 79,       
  60, 61, 62, 63, 64, 65, 66, 67, 68, 69,       
  50, 51, 52, 53, 54, 55, 56, 57, 58, 59,       
  40, 41, 42, 43, 44, 45, 46, 47, 48, 49,       

  30, 31, 32, 33, 34, 35, 36, 37, 38, 39,       
  20, 21, 22, 23, 24, 25, 26, 27, 28, 29,       
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,       
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9        
};

unsigned long swTimer[MAXBUTTONS];

int swTran[] = {
  30, 20, 10, 0,       70, 60, 50, 40, 
  31, 21, 11, 1,       71, 61, 51, 41, 
  32, 22, 12, 2,       72, 62, 52, 42, 
  33, 23, 13, 3,       73, 63, 53, 43, 
  34, 24, 14, 4,       74, 64, 54, 44,   
  35, 25, 15, 5,       75, 65, 55, 45,   
  36, 26, 16, 6,       76, 66, 56, 46,   
  37, 27, 17, 7,       77, 67, 57, 47,   
  38, 28, 18, 8,       78, 68, 58, 48,   
  39, 29, 19, 9,       79, 69, 59, 49           
};

int ledTran[] = {                 // Translate the shift-out to the relative LED positions  
  49, 59, 69, 79, 9, 19, 29, 39, 
  8, 18, 28, 38, 48, 58, 68, 78, 
  47, 57, 67, 77, 7, 17, 27, 37, 
  6, 16, 26, 36, 46, 56, 66, 76, 
  45, 55, 65, 75, 5, 15, 25, 35, 
  4, 14, 24, 34, 44, 54, 64, 74, 
  43, 53, 63, 73, 3, 13, 23, 33, 
  2, 12, 22, 32, 42, 52, 62, 72, 
  41, 51, 61, 71, 1, 11, 21, 31, 
  0, 10, 20, 30, 40, 50, 60, 70 
};


