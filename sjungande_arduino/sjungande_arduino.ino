

#include "pitches.h"
//Först talar vi om vart vi kopplat in buzzern
int pinNummer = 12;

//Nu beskriver vi melodin.
//En ton är egentligen bara en frekvens, alltså hur ofta elen ska skickas ut till buzzern
//Genom att kolla i biblioteket så vet arduinon att "NOTE_C5" är tonen C osv
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5,
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5,
  NOTE_E5, NOTE_F5, NOTE_G5, 
  NOTE_E5, NOTE_F5, NOTE_G5};

// Hur lång tonen är i millisekunder (1000 millisekunder är 1 sekund)
int toneDuration = 300;  
 
void setup() {
 
}
 
void loop() {  

  //Vi måste säga till arduinon att spela upp varje not. I listan melody[] har vi 14 noter.
  for (int thisNote = 0; thisNote < 14; thisNote++) {
    //Metoden "tone()" behöver veta exakt vilken pin, vilken ton och hur länge den ska spelas
    tone(pinNummer, melody[thisNote], toneDuration);

    //När vi kommer till not nummer 10 i listan ska något speciellt hända.
    if (thisNote == 10){
      //Delay betyder att fördröja. Hur länge säger man som antal millisekunder
      delay(400);
    }
    delay(300);
  }
  
  // Pausa innan vi börjar om
  delay(1000);
}
