#include <MIDI.h>

//Konfiguration:

 //Anzahl der verbauten Potis/Fader
#define pZ 2
//Anzahl der verbauten Buttons
#define bZ 1

// Created and binds the MIDI interface to the default hardware Serial port
 MIDI_CREATE_DEFAULT_INSTANCE();
 
//Buffer for potivalues
 
int potiwert[pZ];
 
//MidiNoteNumber array
int noteNum[bZ];


//Buttonpin array
int buttonPin[bZ];


 

 
 void setup()
 {
     
     MIDI.begin(4);  // Listen to all incoming messages
     Serial.begin(115200);
     pinMode(2, INPUT_PULLUP);
     

     //Poti Zwischenspeicher auf null setzen
    for (int i = 0; i < pZ; i = i + 1) {
        potiwert[i] = 0;
      }
    //MidiNoteNumber button configuration
    noteNum[0] = 42;

    //Buttonpin configuration
    buttonPin[0] = 2;
 }




 

 void loop()
 {   
  midiPoti(0, 81, 1); 
  potiFresh();
  buttonFresh();
  while (MIDI.read()) {
    }
  delay(10);  
 }
//LOOP ENDE












//++++++++++++++++++++Nützliche Funktionen++++++++++++++++++++

//Alle Potiwerte aktualisieren: potiFresh
void potiFresh(){
  for (int i = 0; i < pZ; i = i + 1) {
      potiwert[i] = averead(i);
     }
  delay(5);
}

//Poti auslesen und bei Veränderung Midi Signal senden: midiPoti( Potipin, Controllernummer, Midi-Channel(eigentlich immer 1))

void midiPoti(int pPin, int ctnr, int channel){
  int wert = averead(pPin)/8;
  if(wert != potiwert[pPin]/8){
    MIDI.sendControlChange(ctnr, wert, channel);
  }
}

//Alle Knöpfe kontrollieren und Status per Note auf Midi-Channel 1 senden: buttonFresh
void buttonFresh(){
  for (int i = 0; i < bZ; i = i + 1) {
    if(digitalRead(buttonPin[i]) == LOW){
      MIDI.sendNoteOn(noteNum[i], 50, 1);
      while(digitalRead(buttonPin[i]) == LOW){
        delay(2);
      }
    }
  }
}      


//Glättungsfunktion averead
 int averead(int apin){
  int werte[8];
  int sum = 0;
  
  for (byte i = 0; i < 8; i = i + 1) {
    werte[i]=analogRead(apin);
    delay(1);
   }
  
  for (byte i = 0; i < 8; i = i + 1) {
    sum = sum + werte[i];
   }

  return sum/8;
 }
