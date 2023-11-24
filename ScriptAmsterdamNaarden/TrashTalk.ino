// Script for installation piece "Trash Talk", for more information see link "https://ververwant.nl/Trash-Talk". 
// You are free to use and adjust it of course. Sweet if you mention where it came from. :) 

const byte Amsterdam = 3;
const byte Naarden = 11; 
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
// Pins D3 and D11 - 30 Hz
TCCR2B = 0b00000111; // x1024
TCCR2A = 0b00000001; // phase correct
  pinMode(Amsterdam, OUTPUT);
  pinMode(Naarden, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
 HKW = random (100, 250);
 KW = random(150,400);
 GW = random(250,800);
 LW = random(1500, 3000);
 P = random(3000, 5000);
 LP = random (2000, 8000);
 SH = random(120, 1800);
 SKW = random(80, 120);
 SGW = random(40, 100);
 SLW = random(20, 60);

 analogWrite(Amsterdam,0);
 analogWrite(Naarden, 0);
delay(random(40000, 180000));
   analogWrite(Amsterdam, 0);
 delay(LP);
     analogWrite(Naarden, SGW);
 delay(KW);

  analogWrite(Amsterdam, SKW);
 delay(KW);
  analogWrite(Amsterdam, SLW);
 delay(LW);
  analogWrite(Amsterdam, SGW);
 delay(GW);
  analogWrite(Amsterdam, 0);
 delay(random(200, 400));


  analogWrite(Naarden, 0);
 delay(P);

    analogWrite(Naarden, 0);
 delay(P);

  analogWrite(Amsterdam, SGW);
 delay(KW);
   analogWrite(Amsterdam, SLW);
 delay(KW);
  analogWrite(Amsterdam, 0);
 delay(P);

   analogWrite(Amsterdam, 0);
 delay(P);

    analogWrite(Naarden, SLW);
 delay(KW);
    analogWrite(Naarden, 0);
  analogWrite(Amsterdam, SGW);
 delay(GW);
  analogWrite(Amsterdam, SGW);
 delay(HKW);
   analogWrite(Amsterdam, SLW);
 delay(KW);
   analogWrite(Amsterdam, 0);
 delay(LP);
  analogWrite(Amsterdam, SGW);
 delay(GW);
    analogWrite(Naarden, SGW);
 delay(KW);
    analogWrite(Naarden, 0);
      analogWrite(Amsterdam, 0);
       analogWrite(Naarden, 0);
 delay(P);
  analogWrite(Amsterdam, SLW);
 delay(LW);
  analogWrite(Amsterdam, SGW);
 delay(KW);
   analogWrite(Amsterdam, 0);
 delay(P);
 delay(random(10000, 20000));
    analogWrite(Naarden, SLW);
 delay(KW);
    analogWrite(Amsterdam, SGW);
 delay(GW);
     analogWrite(Naarden, 0);
   analogWrite(Amsterdam, SLW);
 delay(HKW);
   analogWrite(Amsterdam, SGW);
 delay(KW);

  analogWrite(Amsterdam, 0);
 delay(random(200, 1000));
    analogWrite(Amsterdam, SGW);
 delay(GW);
    analogWrite(Amsterdam, SGW);
 delay(GW);
    analogWrite(Amsterdam, 0);
 delay(LP);

 analogWrite(Amsterdam, SLW);
 delay(LW);
  analogWrite(Amsterdam, random(20, 50));
 delay(LW);
  analogWrite(Amsterdam, SGW);
 delay(HKW);
  analogWrite(Amsterdam, SLW);
 delay(LW);
 analogWrite(Amsterdam, 0);
 delay(P);
//   analogWrite(Amsterdam, SGW);
// delay(GW);
//   analogWrite(Amsterdam, SLW);
// delay(LW);
    analogWrite(Naarden, SGW);
 delay(KW);
    analogWrite(Naarden, 0);
  analogWrite(Amsterdam, 0);
 delay(P);
delay(random(20000, 30000));
 
 analogWrite(Amsterdam, SKW);
 delay(HKW);
   analogWrite(Naarden, SGW);
 delay(HKW);
   analogWrite(Naarden, SH);
 delay(HKW);
    analogWrite(Amsterdam, 0);
 delay(LP);
  analogWrite(Naarden, 0);
 delay(P);
//
//     analogWrite(Naarden, SH);
// delay(KW);
//   analogWrite(Amsterdam, SGW);
// delay(HKW);
// analogWrite(Amsterdam, SH); 
// delay(KW);
//   analogWrite(Amsterdam, 0);
//       analogWrite(Naarden, 0);
// delay(P);
// analogWrite(Amsterdam, SLW);
// delay(HKW);
//    analogWrite(Naarden, SGW);
// delay(KW);
//   analogWrite(Amsterdam, 0);
//       analogWrite(Naarden, 0);
// delay(P);
//
//        analogWrite(Naarden, SH);
// delay(HKW);
//   analogWrite(Naarden, SH);
// delay(KW);
//    analogWrite(Naarden, 0);
// delay(0);
  
}
