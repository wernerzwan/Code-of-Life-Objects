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

//To do: Sensor Pin Constants
const byte photoPin = A0;
const byte potPin = A1;

//To do: Variables for Timed Events
const long eventTime_1_photo = 100;
const long event_1_movement = 1000;
const long event_2_movement = 5000;
const long event_3_movement = 7000;
const long event_4_movement = 12000;
const long event_5_movement = 15000; 
const long event_6_movement = 18000; 
const long event_7_movement = 20000;
const long event_8_movement = 23000;
const long event_9_movement = 25000;
const long event_10_movement = 30000;
const long event_11_movement = 32000; 
const long event_12_movement = 34000; 
const long event_13_movement = 36000;
const long event_14_movement = 39000;
const long event_15_movement = 40000;
const long event_16_movement = 41000;
const long event_17_movement = 45000; 
const long event_18_movement = 51000;
const long event_19_movement = 60000; 

unsigned long previousTime_1 = 0;
unsigned long previousTime_2 = 0;
//
int lightRead = 0;
int lightVal = 100;

const byte motorPin = 3;
int scene = 0;
int PWM = 0;
//unsigned long previousTime;


void setup()
{
//  // We'll set up the LED pin to be an output.
TCCR2B = TCCR2B & B11111000 | B00000111; // for PWM frequency of 3.16 Hz
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  unsigned long currentTime = millis();

  if ( currentTime - previousTime_1 >= eventTime_1_photo) {
    Serial.print("Light intensity is: ");
    Serial.println(analogRead(photoPin));
    previousTime_1 = currentTime;   
  }
 if (currentTime - previousTime_2 >= event_1_movement) {
    analogWrite(motorPin, 255);
    
  } else if (currentTime - previousTime_2 >= event_2_movement) {
    analogWrite(motorPin, 0);
    lightRead = analogRead(photoPin);
    if (lightVal < lightRead) {
      analogWrite(motorPin, 255);
    } else if (currentTime - previousTime_2 >= event_3_movement)
    analogWrite(motorPin, 0);
    previousTime_2 = currentTime;
  
//
//  
//    
//  } else if (currentTime - previousTime_2 >= event_3_movement) { 
//    
//  } else if (currentTime - previousTime_2 >= event_4_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_5_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_6_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_7_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_8_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_9_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_10_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_11_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_12_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_13_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_14_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_15_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_16_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_17_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_18_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_19_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_20_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_21_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_22_movement) {
//    
//  } else if (currentTime - previousTime_2 >= event_23_movement) {
//    
  }

////  previousTime = millis();
////  Serial.println(previousTime);
//  PWM = map(analogRead(potPin), 0, 1023, 0, 255);
////  Serial.print("PWM = ");
////  Serial.println(PWM);
////TCCR2B = TCCR2B & B11111000 | B00000001;
//  analogWrite(motorPin, PWM);
  
}
