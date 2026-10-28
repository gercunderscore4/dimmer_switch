/*
 * Taken from a Korok Puzzle I designed.
 * 
 *      PD6  -| \/ |-  PC5
 *      PD0  -|    |-  PC4
 *      PD1  -|    |-  PC3
 *      PD2  -|    |-  PC2
 *      PD3  -|    |-  PC1
 *      PD4  -|    |-  PC0
 *      VCC  -|    |-  GND
 *      GND  -|    |-  AREF
 *      PB6  -|    |-  AVCC
 *      PB7  -|    |-  PB5  SCK
 *      PD5  -|    |-  PB4  DO
 *      PD6  -|    |-  PB3  DI
 *      PD7  -|    |-  PB2
 * CS   PB0  -|____|-  PB1  sound
 *
 * PB0 -> D8  -> CS
 * PB1 -> D9  -> sound
 * PB3 -> D11 -> DI
 * PB4 -> D12 -> DO
 * PB5 -> D13 -> SCK
 */

#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>

#define SPEAKER_PIN 9

#define SD_SCHIP_SELECT_PIN 8

TMRpcm tmrpcm;

void play_fanfare() {
  tmrpcm.play("fanfare.wav");
  while(tmrpcm.isPlaying());
}

void play_yahaha() {
  tmrpcm.play("yahaha.wav");
  while(tmrpcm.isPlaying());
}

void play_item() {
  tmrpcm.play("item.wav");
  while(tmrpcm.isPlaying());
}

void setup(){
  Serial.println("setup start");

  tmrpcm.speakerPin = SPEAKER_PIN;

  Serial.begin(9600);
  Serial.println("Serial started");  
  if (!SD.begin(SD_SCHIP_SELECT_PIN)) {
    Serial.println("SD fail");  
  }

}

void loop(){  
  Serial.println("Playing fanfare");  
  play_fanfare();
  Serial.println("Playing yahaha");  
  play_yahaha();
  Serial.println("Playing item");  
  play_item();
}
