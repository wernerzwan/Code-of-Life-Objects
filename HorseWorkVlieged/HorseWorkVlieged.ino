#include <Adafruit_NeoPixel.h>
#include "FastLED.h"
#define PIN 3
#define NUM_LEDS 96
CRGB leds[NUM_LEDS];
//int d = 50;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(96, PIN, NEO_GRB + NEO_KHZ800);
FastLED.addLeds<WS2811, PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );


void setup() {
strip.begin();
strip.show(); // Initialize all pixels to 'off'
}

void loop() {
int d = 200;
int m = 0;
//int d = random(200, 300);
//int m = random(0, 40);
strip.show();
delay(1 * d + m * 5);
setGroup(4, strip.Color(0, 0, 0));
setGroup(5, strip.Color(0, 0, 0));
setGroup(0, strip.Color(255, 255, 255));

strip.show();
delay(1.3 * d - m);
setGroup(0, strip.Color(0, 0, 0));
setGroup(1, strip.Color(255, 255, 255));

strip.show();
delay(d - m * 2);
setGroup(1, strip.Color(0, 0, 0));
setGroup(2, strip.Color(255, 255, 255));

strip.show();
delay(1.3 * d - m * 3);
setGroup(2, strip.Color(0, 0, 0));
setGroup(3, strip.Color(255, 255, 255));

strip.show();
setGroup(2, strip.Color(0, 0, 0));
for (int i = 255; i >= 0; i--) {

setGroup(3, strip.Color(i, i, i));
strip.show();
delay(1);
}



delay(d - m * 4);
setGroup(3, strip.Color(0, 0, 0));
setGroup(4, strip.Color(170, 200, 255));
setGroup(5, strip.Color(170, 200, 255));

strip.show();
delay(4 * d - m * 4);

//setGroup(3, strip.Color(0, 0, 0));
//setGroup(4, strip.Color(170, 200, 255));
//setGroup(5, strip.Color(170, 0, 255));
//
//strip.show();
//delay(0.2 * d - m * 4);



for (int g = 200; g >= 0; g --){
  setGroup(4, strip.Color(127, g, 255));
  setGroup(5, strip.Color(127, g, 255));
  strip.show();
  delay(2);
}

setGroup(3, strip.Color(0, 0, 0));

setGroup(4, strip.Color(0, 100, 255));
setGroup(5, strip.Color(0, 100, 255));



strip.show();

     Fire(170,200,255);
delay(4 * d - m * 4);


//setGroup(2, strip.Color(0, 0, 255)); //goes up to group 5


}
// Fill the dots one after the other with a color

void setGroup(uint8_t g, uint32_t c) {
int firstPixel = g * 16;
for(uint8_t i=0; i<16; i++) {
strip.setPixelColor(firstPixel + i, c);
}
}


void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[NUM_LEDS];
  int cooldown;
 
  // Step 1.  Cool down every cell a little
  for( int i = 0; i < NUM_LEDS; i++) {
    cooldown = random(0, ((Cooling * 10) / NUM_LEDS) + 2);
   
    if(cooldown>heat[i]) {
      heat[i]=0;
    } else {
      heat[i]=heat[i]-cooldown;
    }
  }
 
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k= NUM_LEDS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }
   
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160,255);
    //heat[y] = random(160,255);
  }

  // Step 4.  Convert heat to LED colors
  for( int j = 0; j < NUM_LEDS; j++) {
    setPixelHeatColor(j, heat[j] );
  }

  strip.show();
  delay(SpeedDelay);
}

void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature/255.0)*191);
 
  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252
 
  // figure out which third of the spectrum we're in:
  if( t192 > 0x80) {                     // hottest
    setPixel(Pixel, 255, 255, heatramp);
  } else if( t192 > 0x40 ) {             // middle
    setPixel(Pixel, 255, heatramp, 0);
  } else {                               // coolest
    setPixel(Pixel, heatramp, 0, 0);
  }
}

void showStrip() {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.show();
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   FastLED.show();
 #endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
   // NeoPixel
   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[Pixel].r = red;
   leds[Pixel].g = green;
   leds[Pixel].b = blue;
 #endif
}

void setAll(byte red, byte green, byte blue) {
  for(int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
