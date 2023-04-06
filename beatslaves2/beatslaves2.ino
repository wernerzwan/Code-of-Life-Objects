// Arduino Beat Detector By Damian Peckett 2015
// License: Public Domain.

// Our Global Sample Rate, 5000hz
#define SAMPLEPERIODUS 200

// defines for setting and clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif
#define NO_OF_PINS 8
const int motorPin = 6;
int outputPins[NO_OF_PINS] = {6, 7, 8, 9, 10, 11, 12, 13};
int outputPin;
char mystr[1] = "0"; //String data
char bystr[1] = "1";
int i;

void setup() {
    Serial.begin(9600);
    // Set ADC to 77khz, max for 10bit
    sbi(ADCSRA,ADPS2);
    cbi(ADCSRA,ADPS1);
    cbi(ADCSRA,ADPS0);

    //The pin with the LED
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

// 20 - 200hz Single Pole Bandpass IIR Filter
float bassFilter(float sample) {
    static float xv[3] = {0,0,0}, yv[3] = {0,0,0};
    xv[0] = xv[1]; xv[1] = xv[2]; 
    xv[2] = (sample) / 3.f; // change here to values close to 2, to adapt for stronger or weeker sources of line level audio  
    

    yv[0] = yv[1]; yv[1] = yv[2]; 
    yv[2] = (xv[2] - xv[0])
        + (-0.7960060012f * yv[0]) + (1.7903124146f * yv[1]);
    return yv[2];
}

// 10hz Single Pole Lowpass IIR Filter
float envelopeFilter(float sample) { //10hz low pass
    static float xv[2] = {0,0}, yv[2] = {0,0};
    xv[0] = xv[1]; 
    xv[1] = sample / 50.f;
    yv[0] = yv[1]; 
    yv[1] = (xv[0] + xv[1]) + (0.9875119299f * yv[0]);
    return yv[1];
}

// 1.7 - 3.0hz Single Pole Bandpass IIR Filter
float beatFilter(float sample) {
    static float xv[3] = {0,0,0}, yv[3] = {0,0,0};
    xv[0] = xv[1]; xv[1] = xv[2]; 
    xv[2] = sample / 2.7f;
    yv[0] = yv[1]; yv[1] = yv[2]; 
    yv[2] = (xv[2] - xv[0])
        + (-0.7169861741f * yv[0]) + (1.4453653501f * yv[1]);
    return yv[2];
}

void loop() {
    unsigned long time = micros(); // Used to track rate
    float sample, value, envelope, beat, thresh;
    unsigned char i;
    /*digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);*/
     

    for(i = 0;;++i){
        // Read ADC and center so +-512
        sample = (float)analogRead(0)-503.f;
        
        // Filter only bass component
        value = bassFilter(sample);

        // Take signal amplitude and filter
        if(value < 0)value=-value;
        envelope = envelopeFilter(value);

        // Every 200 samples (25hz) filter the envelope 
        if(i == 200) {
                // Filter out repeating bass sounds 100 - 180bpm
                beat = beatFilter(envelope);
                // Threshold it based on potentiometer on AN1
                thresh = 0.02f * (float)300;
                // If we are above threshold, light up LED
                if(beat > thresh) {
                  //Serial.write(mystr,2); //Write the serial data
                  //(6, LOW);
                  //motor();
                  //delay(500);
                  outputPin = outputPins[random(1,8)];
                  digitalWrite(outputPin, LOW);
                  outputPin = outputPins[random(1,8)];
                  digitalWrite(outputPin, LOW);            
                  delay(100);
                  if(digitalRead(7) == LOW){
                    motor();
                  }
                  digitalWrite(6, LOW);
                  digitalWrite(7, HIGH);
                  digitalWrite(8, HIGH);
                  digitalWrite(9, HIGH);
                  digitalWrite(10, HIGH);
                  digitalWrite(11, HIGH);
                  digitalWrite(12, HIGH);
                  digitalWrite(13, HIGH);
                }
                else {
                  //digitalWrite(outputPins[1,2,3,4,5,6], HIGH);
                  //digitalWrite(outputPin, HIGH);
                  //Serial.write(bystr,1);
                  //delay(100);
                  //digitalWrite(6, LOW);
                }

                //Reset sample counter
                i = 0;
        }

        // Consume excess clock cycles, to keep at 5000 hz
        for(unsigned long up = time+SAMPLEPERIODUS; time > 20 && time < up; time = micros());
    }  
}

void motor(){
  for(i = 0;i < 5;i++){
  digitalWrite(6, HIGH);
  delay(40);
  digitalWrite(6, LOW);
  delay(80);
  }
}
