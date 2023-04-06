/*
  SparkFun Inventor's Kit
  Example sketch 07

  PHOTORESISTOR

  Read a photoresistor (light sensor) to detect "darkness" and turn on an LED when it
  is "dark" and turn back off again when it is "bright.

  This sketch was written by SparkFun Electronics,
  with lots of help from the Arduino community.
  This code is completely free for any use.
  Visit http://learn.sparkfun.com/products/2 for SIK information.
  Visit http://www.arduino.cc to learn about the Arduino.
*/


const byte Amsterdam = 3;
const byte Naarden = 5; 
//unsigned long previousTime;
int HKW = 0;
int KW = 0;
int GW = 0;
int LW = 0;
int P = 0; 
int LP = 0;

int SH = 0;
int SKW = 0;
int SGW = 0;
int SLW = 0;
//int SP = 0; 
int SLP = 0; 

void setup()
{
//  // We'll set up the LED pin to be an output.
TCCR0B = TCCR0B & B11111000 | B00000101; // for Naarden (D5) frequency 60Hz
  pinMode(Amsterdam, OUTPUT);
  pinMode(Naarden, OUTPUT);
  digitalWrite(Amsterdam, LOW);
  Serial.begin(9600);
}


void loop()
{
 HKW = random (20, 50);
 KW = random(30,80);
 GW = random(25,100);
 LW = 50;
 P = random(100, 300);
 LP = random (200, 800);
 SH = random(180, 256);
 SKW = random(200, 256);
 SGW = random(100, 150);
 SLW = 30;
 
 digitalWrite(Amsterdam,HIGH);
 delay(50);
 digitalWrite(Amsterdam,HIGH);
 analogWrite(Naarden, LW);
 delay(1);
 digitalWrite(Amsterdam,HIGH);
 delay(5);
 analogWrite(Naarden, 0);
 delay(60);
    analogWrite(Naarden, LW);
 delay(KW);
     analogWrite(Naarden, LW);
 delay(KW);
    analogWrite(Naarden, 0);
  analogWrite(Naarden, 0);
 delay(P);
    analogWrite(Naarden, LW);
 delay(HKW);
   analogWrite(Naarden, LW);
 delay(KW);
    analogWrite(Naarden, 0);
 delay(P);
    analogWrite(Naarden, LW);
 delay(KW);
    analogWrite(Naarden, 0);
    analogWrite(Naarden, LW);
 delay(KW);
    analogWrite(Naarden, 0);
    analogWrite(Naarden, LW);
 delay(KW);

    analogWrite(Naarden, SH);
 delay(KW);
    analogWrite(Naarden, 0);
   analogWrite(Naarden, SH);
 delay(HKW);
  analogWrite(Naarden, 0);
 delay(P);
     analogWrite(Naarden, SH);
 delay(KW);
    analogWrite(Naarden, 0);
 delay(0);
 digitalWrite(Amsterdam, HIGH);
 delay(500);
 HKW = random (20, 50);
 KW = random(30,80);
 GW = random(25,100);
 P = random(100, 300);
    analogWrite(Naarden, LW);
 delay(KW);
     analogWrite(Naarden, LW);
 delay(KW);
    analogWrite(Naarden, 0);
  analogWrite(Naarden, 0);
 delay(P);
    analogWrite(Naarden, LW);
    digitalWrite(Amsterdam, LOW);
 delay(5);
  digitalWrite(Amsterdam,HIGH);
  analogWrite(Naarden, LW);
 delay(KW);
    analogWrite(Naarden, 0);
 delay(P);
    analogWrite(Naarden, LW);
 delay(KW);
    analogWrite(Naarden, 0);
    digitalWrite(Amsterdam, LOW);
   delay(10);
  digitalWrite(Amsterdam,HIGH);
    analogWrite(Naarden, LW);
 delay(KW);
    analogWrite(Naarden, 0);
    analogWrite(Naarden, LW);
 delay(KW);
  digitalWrite(Amsterdam, LOW);
   delay(10);
  digitalWrite(Amsterdam,HIGH);

    analogWrite(Naarden, SH);
 delay(KW);
    analogWrite(Naarden, 0);
   analogWrite(Naarden, SH);
 delay(HKW);
  analogWrite(Naarden, 0);
 
  
}
