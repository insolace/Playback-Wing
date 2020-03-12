void clearLEDs() {
  memset(led,0,sizeof(led));  // clear all LEDs
  doShift();  
}

void lightLEDs() {
  memset(led,1,sizeof(led));  // set all LEDs on
  doShift();  
}

void dispVALs() {
    //lcd.setCursor(0,0);  

// sw 1-40
    for (int i = 0; i < 40; i++) {
      //lcd.print(swState[i]);
    }
    
    //lcd.setCursor(0,1);  
     
// sw 41-80
    for (int i = 40; i < 80; i++) {
      //lcd.print(swState[i]);
    }
}

void print3dig(int p3d) {
  if (p3d < 100) {
    //lcd.print(" ");
  }
  if (p3d < 10) {
    //lcd.print(" ");
  }
  //lcd.print(p3d);
}

void dispSw(int sw, int note, int state) {
  lcd.setCursor(0,1);
  lcd.print("                                        ");
  lcd.setCursor(0,1);
  lcd.print("Switch: ");
  lcd.print(sw);
  lcd.print(" Midi Note: ");
  lcd.print(note);
  lcd.print(" State: ");
  lcd.print(state);
}

void dispLed(int led, int note, int state) {
  lcd.setCursor(0,0);
  lcd.print("                                        ");
  lcd.setCursor(0,0);
  lcd.print("Midi Note: ");
  lcd.print(note);
  lcd.print(" State: ");
  lcd.print(state);
  lcd.print(" Led: ");
  lcd.print(led);
}

