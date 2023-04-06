#include <SPI.h>
#include <SdFat.h>
#include <SFEMP3Shield.h>

SdFat sd;
SFEMP3Shield MP3player;


void setup()
{
  Serial.begin(9600);
  sd.begin(SD_SEL, SPI_HALF_SPEED);
  MP3player.begin();
  MP3player.setVolume(0, 0);                 // set volume of the mp3 player ( 0 = loudest )

}

void loop()
{
    MP3player.playTrack(1);
}
