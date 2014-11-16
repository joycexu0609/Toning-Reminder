//#include <elapsedMillis.h>
#include "pitches.h"

//array of notes
int melody[] = {
  /*NOTE_G4,NOTE_G4,NO_SOUND,NOTE_G4,NOddTE_G4,NO_SOUND,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,
   NOTE_B3,NOTE_G3,NOTE_C4,NOTE_G3,NOTE_CS4,NOTE_G3,NOTE_C4,NOTE_G3,NOTE_B3,NOTE_G3,NOTE_C4,NOTE_G3,NOTE_CS4,NOTE_G3,NOTE_C4,NOTE_G3,
   NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
   NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4,*/
   //Introduction
  NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_DS5,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_B4,
  NOTE_E4,NOTE_G4,NOTE_DS5,NOTE_D5,NOTE_G4,NOTE_B4,
  NOTE_B4,NOTE_FS5,NOTE_F5,NOTE_B4,NOTE_D5,NOTE_AS5,
  NOTE_A5,NOTE_F5,NOTE_A5,NOTE_DS6,NOTE_D6
};

// note duration: 1 = whole note, 2 = half note, 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  /*8,8,2,8,8,2,16,8,16,8,8,
   2,4,2,4,2,4,2,4,2,4,2,4,2,4,2,4,
   8,16,16,8,4,8,8,8,
   8,16,16,8,4,8,8,8,*/
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8,
  8,16,16,8,4,8,8,8, 
  8,16,16,8,4,8,8,8,
  8,2,8,8,1,
  8,4,8,4,8,8,
  8,8,4,8,4,8,
  4,8,4,8,3
};

int pace = 1450; // change pace of music("speedy")

//elapsedMillis timeElapsed; //declare global if you don't want it reset every time loop runs

// Pin 13 has an LED connected on most Arduino boards.
int ledPin = 13;
int speakerPin = 8;
int flexiForcePin = A2; //analog pin 0
int pressure = 0;
int counter = 0;
int Note=0;
// delay in milliseconds between blinks of the LED
//unsigned int interval = 5000;
int interval = 2500;

void setup() 
{ 
  
  
  Serial.begin(9600);
  // initialize the digital pin as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);  
  //music
 
}

void loop(){
  
   Serial.println(counter);
   
  pressure = analogRead(flexiForcePin);
  Serial.println(pressure);
  if(pressure < 400){
    counter++;
    digitalWrite(ledPin, LOW);
  }
  else{
    counter=0;
    digitalWrite(ledPin, HIGH);
    noTone(speakerPin);
  }

  if (counter >= interval && pressure<400 ){
    digitalWrite(ledPin, LOW);
//    tone(speakerPin, 300);
 //  for (int Note = 0; Note <54; Note++) {//counter of Notes (54 limit the array)
  
      Note++;
    int duration = pace/noteDurations[Note];//Adjust duration with the pace of music
    tone(8, melody[Note],duration); //Play note
        delay(duration*1.2);
 }
    else{
    noTone(speakerPin);
    Note=0;
   
    }

// to distinguish the notes, set a minimum time between them.

    
  
//}

  }
  
  





