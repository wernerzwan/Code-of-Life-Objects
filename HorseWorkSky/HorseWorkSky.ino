#include <Adafruit_NeoPixel.h>

#define PIN 3
//int d = 50;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(96, PIN, NEO_GRB + NEO_KHZ800);


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



for (int g = 200; g >= 127; g --){
  setGroup(4, strip.Color(80, g, 255));
  setGroup(5, strip.Color(80, g, 255));
  strip.show();
  delay(2);
}

setGroup(3, strip.Color(0, 0, 0));
setGroup(4, strip.Color(80, 127, 255));
setGroup(5, strip.Color(80, 127, 255));

strip.show();
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
