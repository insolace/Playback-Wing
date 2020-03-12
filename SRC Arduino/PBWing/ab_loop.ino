void loop() {


      unsigned long CurrentTime = millis();
      while (millis() - CurrentTime < 1000){
        doShift();
        MIDI.read();
        usbMIDI.read();
      }
/*
      Serial.print("sw0: ");
      Serial.print(sw[0]);
      Serial.print(" sw1: ");
      Serial.print(sw[1]);
      Serial.print(" sw2: ");
      Serial.print(sw[2]);
      Serial.print(" sw3: ");
      Serial.print(sw[3]);
      Serial.print(" sw4: ");
      Serial.println(sw[4]);

    
// debug, count up LEDs

    for (int i = 0; i < MAXBUTTONS; i++) {
      led[i] = 1;
     
      unsigned long CurrentTime = millis();
      while (millis() - CurrentTime < 500){
        doShift();
      }
    }
    memset(led,0,sizeof(led));
*/
    
}
