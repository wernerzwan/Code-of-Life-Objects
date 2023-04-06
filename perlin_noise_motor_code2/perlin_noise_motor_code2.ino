
#include <math.h>

float x;
int o3,o5,o6, avg, avg2, i, loopnum;
const int sensorPin1 = 0;
const int sensorPin2 = 1;
const int potPin1 = 3;
const int potPin2 = 4;
const int motorPin1 = 3;
const int motorPin2 = 5;
int potVal1;
int potVal2;
int lightVal1;
int lightVal2;
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;  

byte perm[] = {   151,160,137,91,90, 15,131, 13,201,95,96,
53,194,233, 7,225,140,36,103,30,69,142, 8,99,37,240,21,10,23,190, 6,
148,247,120,234,75, 0,26,197,62,94,252,219,203,117, 35,11,32,57,177,
33,88,237,149,56,87,174,20,125,136,171,168,68,175,74,165,71,134,139,
48,27,166, 77,146,158,231,83,111,229,122, 60,211,133,230,220,105,92,
41,55,46,245,40,244,102,143,54,65,25,63,161, 1,216,80,73,209,76,132,
187,208, 89, 18,169,200,196,135,130,116,188,159, 86,164,100,109,198,
173,186, 3,64,52,217,226,250,124,123,5,202,38,147,118,126,255,82,85,
212,207,206, 59,227, 47,16,58,17,182,189, 28,42,223,183,170,213,119,
248,152,2,44,154,163,70,221,153,101,155,167,43,172, 9,129,22,39,253,
19,98,108,110,79,113,224,232,178,185,112,104,218,246, 97,228,251,34,
242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,
49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,
150,254,138,236,205, 93,222,114, 67,29,24, 72,243,141,128,195,78,66,
215,61,156,180
};

void setup()
{
 Serial.begin(9600);
 pinMode(3, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(inputPin, INPUT);     // declare sensor as input
 analogWrite(3,0);
 analogWrite(5,0);
}

void loop()
{
 val = digitalRead(inputPin);
 if (val == HIGH){
 Serial.println("Motion detected!");
 lightVal1 = analogRead(sensorPin1);
 lightVal2 = analogRead(sensorPin2);
 potVal1 =  analogRead(potPin1);
 potVal2 = analogRead(potPin2);
 Serial.println("Sensing light...");
 Serial.println(lightVal1); 
 if (lightVal1 < potPin1){
 loopnum = random(0, 100);
 Serial.println("Dark enough, starting life");
 for(i = 0; i < loopnum; i ++){
 x = float(millis())/200.0f;
 o3 = fastFloor(128*generate(x + 19082) + 128);
 o5 = fastFloor(128*generate(x + 5728) + 128);
 o6 = fastFloor(128*generate(x) + 128);
 delay(1);
 avg =  o3 - o5;
 if (avg < 0) {
  avg =  avg * -1;
 }
 avg2 = o5 - o6;
 if (avg2 < 0) {
  avg2 = avg2 * -1;
 }
 Serial.println(avg);
 Serial.println(avg2);
 analogWrite(3, avg);
 analogWrite(5, avg);
 } delay(loopnum * 20);
 }
 else {
 analogWrite(3, 0);
 }
} else {
  Serial.println("No one there!");
}
}
 
float generate(float x)
{
  int i0 = fastFloor(x);
  int i1 = i0 + 1;
  float x0 = x - i0;
  float x1 = x0 - 1.0f;

  float n0, n1;

  float t0 = 1.0f - x0 * x0;
  t0 *= t0;
  n0 = t0 * t0 * grad(perm[i0 & 0xff], x0);

  float t1 = 1.0f - x1 * x1;
  t1 *= t1;
  n1 = t1 * t1 * grad(perm[i1 & 0xff], x1);
  // The maximum value of this noise is 8*(3/4)^4 = 2.53125
  // A factor of 0.395 scales to fit exactly within [-1,1]
  return 0.395f * (n0 + n1);
}

int fastFloor(float x)
{
  return (x > 0) ? ((int)x) : (((int)x) - 1);
}

float grad(int hash, float x)
{
    int h = hash & 15;
    float grad = 1.0f + (h & 7);    // Gradient value 1.0, 2.0, ..., 8.0
    if ((h & 8) != 0) grad = -grad; // Set a random sign for the gradient
    return (grad * x);              // Multiply the gradient with the distance
}
