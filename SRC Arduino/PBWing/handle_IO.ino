
void swHandle(int swNum, int state) {
  sw[swNum] = state;  
  led[swNum] = state;
  //Serial.println(swNum);
  // handle midi
  if (state == 0) {
    MIDI.sendNoteOff(noteTran[swNum]+OFFSET, 0, 1);
    usbMIDI.sendNoteOff(noteTran[swNum]+OFFSET, 0, 1);
  } else {
    MIDI.sendNoteOn(noteTran[swNum]+OFFSET, 127, 1);
    usbMIDI.sendNoteOn(noteTran[swNum]+OFFSET, 127, 1);
  }
  dispSw(swNum, noteTran[swNum]+OFFSET, state);
}


void doShift() {

  latch();

  // shift out LED, shift in all switches
  for (int i = 0; i < MAXBUTTONS; i++) {

    // clock low
    digitalWrite(IO_CLOCK, 0);

    // read switch state
    swState[i] = (digitalRead(SW_DATA) ^ 1);

    // check for change in state
    if (swState[i] == swPrevState[i]) {
      swPrevState[i] = swState[i];            // no change
    } else {

      swPrevState[i] = swState[i];            // switch state changed

      if (millis() - swTimer[i] > SW_SLOWDOWN) {
        swTimer[i] = millis();                // update sw counter
        swHandle(swTran[i], swState[i]);        // translate shift-in to switch position and call handler
      }      
    }

    // shift out LED data
    digitalWrite(LED_DATA, led[ledTran[i]] );    

    // Clock High
    digitalWrite(IO_CLOCK, 1);
  }
  unLatch();
}


void latch() {
  digitalWrite(LED_LATCH, LOW);
  digitalWrite(SW_LATCH, 1);
}

void unLatch() {
  digitalWrite(LED_LATCH, HIGH);
  digitalWrite(SW_LATCH, 0);
}


void myNoteOn(byte channel, byte note, byte velocity){
  if ( (note-OFFSET <= MAXBUTTONS) && ( note >= OFFSET ) ) {
    led[noteTran[note-OFFSET]] = 1;   
    dispLed(noteTran[note-OFFSET], note, 1);
  }
}

void myNoteOff(byte channel, byte note, byte velocity){
  if ( (note-OFFSET <= MAXBUTTONS) && ( note >= OFFSET ) ) {
    led[noteTran[note-OFFSET]] = 0;  
    dispLed(noteTran[note-OFFSET], note, 0);
  }
}

