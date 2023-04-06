#include <math.h>

float x;
int o3, o5, o6, i, i2, loopnum;
//const int potPin1 = A0;
//const int potPin2 = A1;
//const int potPin3 = A2;
//const int potPin4 = A3;
//const int potPin5 = A4;
const int motorPin1 = 3;
const int motorPin2 = 5;
const int motorPin3 = 6;
const int motorPin4 = 9;
const int motorPin5 = 10;
int scene;
long previousMillis = 0;                           // will store last time LED was updated
long previousIntervalMillis = 0;                   // will store last time LED was updated
long previousIronBoardThresholdIntervalMillis = 0; // will store last time LED was updated
long previousMattressThresholdIntervalMillis = 0;  // will store last time LED was updated
long previousRakeThresholdIntervalMillis = 0;      // will store last time LED was updated
long previousChairThresholdIntervalMillis = 0;
long previousBroomThresholdIntervalMillis = 0;
// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 200;
long interval_interval = 1000;
long ironboard_threshold_interval = 400;
int iron_board_threshold = 180;
long maitresse_threshold_interval = 100;
int maitresse_threshold = 150;
long rake_threshold_interval = 70;
int rake_threshold = 160;
long chair_threshold_interval = 100;
int chair_threshold = 100;
long broom_threshold_interval = 50;
int broom_threshold = 150;
byte perm[] = {151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96,
               53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23, 190, 6,
               148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177,
               33, 88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139,
               48, 27, 166, 77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92,
               41, 55, 46, 245, 40, 244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132,
               187, 208, 89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109, 198,
               173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147, 118, 126, 255, 82, 85,
               212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42, 223, 183, 170, 213, 119,
               248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9, 129, 22, 39, 253,
               19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251, 34,
               242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
               49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4,
               150, 254, 138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66,
               215, 61, 156, 180
              };

void setup()
{
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  //  digitalWrite(3, LOW);
  //  digitalWrite(5, LOW);
  //  digitalWrite(6, LOW);
  //  digitalWrite(9, LOW);
  //  digitalWrite(10, LOW);
}
int NewValue;
void loop()
{
  //long interval = map(analogRead(potPin1), 0, 1024, 1, 20);
  //long interval_interval = map(analogRead(potPin2), 0, 1024, 50, 500);
  //int iron_board_threshold = map(analogRead(potPin3), 0, 1024, 0, 255);
  //1int maitresse_threshold = map(analogRead(potPin4), 0, 1024, 0, 255);
  //int rake_threshold = map(analogRead(potPin5), 0, 1024, 0, 255);

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval)
  {
    // save the last time you blinked the LED
        previousMillis = currentMillis;
        x = float(currentMillis) / 200.0f;
        o5 = fastFloor(128 * generate(x + 5728) + 128);
        o6 = fastFloor(128 * generate(x) + 128);
        o3 = fastFloor(128 * generate(x + 19082) + 128);
        int OldRange = 255;
        int NewMin = 25;

        loopnum = map(o6, 0, 255, 500, 900);
        for (i = 0; i < loopnum; i++)
        {
          
    int broom = broom_func(o5, broom_threshold);
    int rake = rake_func(o6, rake_threshold);
    int mattress = mattress_func(o6, maitresse_threshold);
    int iron_board = ironboard(o5, iron_board_threshold);
    int chair = chair_func(o6, chair_threshold);
//    if (scene == 0)
//    {
//    }
//    else if (scene == 1)
//    {
//      mattress = 0;
//      iron_board = 0;
//      chair = 0;
//    }
//    else if (scene == 2)
//    {
//      chair = 0;
//      rake = 0;
//      broom = 0;
//    }
//    else if (scene == 3)
//    {
//      iron_board = 0;
//      chair = 0;
//      broom = 0;
//    }
//    else if (scene == 4)
//    {
//      rake = 0;
//      broom = 0;
//      mattress = 0;
//      iron_board = 0;
//    }
//    else if (scene == 5)
//    {
//      rake = 0;
//      broom = 0;
//      mattress = 0;
//      chair = 0;
//    }
//    else if (scene == 6)
//    {
//      rake = 0;
//      broom = 0;
//      mattress = 0;
//      chair = 0;
//      iron_board = 0;
//    }

    analogWrite(motorPin5, broom);
    analogWrite(motorPin3, rake);
    analogWrite(motorPin2, mattress);
    analogWrite(motorPin1, iron_board);
    analogWrite(motorPin4, chair);
    Serial.println(scene);
    //      Serial.print(",");
    //      Serial.print(broom);
    //      Serial.print(",");
    //      Serial.print(rake);
    //      Serial.print(",");
    //      Serial.print(mattress);
    //      Serial.print(",");
    //      Serial.print(iron_board);
    //      Serial.print(",");
    //      Serial.print(chair);
    //      Serial.print(",");
    //  }
//
//    if (scene == 4 || scene == 5)
//    {
//      scene++;
//    }
//    else if (scene == 6)
//    {
//      scene = 0;
//    }
//    else
//    {
//      scene = random(0, 6);
//    }
  }
  if (currentMillis - previousIntervalMillis > interval_interval)
  {
    // save the last time you blinked the LED
    previousIntervalMillis = currentMillis;
    interval = map(o5, 0, 255, 200, 400);
  }
  if (currentMillis - previousIronBoardThresholdIntervalMillis > ironboard_threshold_interval)
  {
    // save the last time you blinked the LED
    previousIronBoardThresholdIntervalMillis = currentMillis;
    iron_board_threshold = random(160, 240);
  }
  if (currentMillis - previousMattressThresholdIntervalMillis > maitresse_threshold_interval)
  {
    // save the last time you blinked the LED
    previousMattressThresholdIntervalMillis = currentMillis;
    maitresse_threshold = random(140, 240);
  }
  if (currentMillis - previousRakeThresholdIntervalMillis > rake_threshold_interval)
  {
    // save the last time you blinked the LED
    previousRakeThresholdIntervalMillis = currentMillis;
    rake_threshold = random(170, 240);
  }
  if (currentMillis - previousChairThresholdIntervalMillis > chair_threshold_interval)
  {
    // save the last time you blinked the LED
    previousChairThresholdIntervalMillis = currentMillis;
    chair_threshold = random(100, 240);
  }
  if (currentMillis - previousBroomThresholdIntervalMillis > broom_threshold_interval)
  {
    // save the last time you blinked the LED
    previousBroomThresholdIntervalMillis = currentMillis;
    broom_threshold = random(120, 240);
  }
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
  float grad = 1.0f + (h & 7); // Gradient value 1.0, 2.0, ..., 8.0
  if ((h & 8) != 0)
    grad = -grad;    // Set a random sign for the gradient
  return (grad * x); // Multiply the gradient with the distance
}

int ironboard(int raw_value, int threshold)
{
  int NewValue;
  if (raw_value < threshold)
  {
    NewValue = 0;
  }
  else
  {
    NewValue = raw_value;
    NewValue = map(raw_value, 0, 255, 240, 255);
  }
  return NewValue;
}

int mattress_func(int raw_value, int threshold)
{
  int NewValue;
  if (raw_value < threshold)
  {
    NewValue = 0;
  }
  else
  {
    NewValue = map(raw_value, 0, 255, 240, 255);
  }
  return NewValue;
}

int rake_func(int raw_value, int threshold)
{
  int NewValue;
  if (raw_value < threshold)
  {
    NewValue = 0;
  }
  else
  {
    NewValue = map(raw_value, 0, 255,100, 255);
  }
  return NewValue;
}

int chair_func(int raw_value, int threshold)
{
  int NewValue;
  if (raw_value < threshold)
  {
    NewValue = 0;
  }
  else
  {
    NewValue = map(raw_value, 0, 255, 230, 255);
  }
  return NewValue;
}

int broom_func(int raw_value, int threshold)
{
  int NewValue;
  if (raw_value < threshold)
  {
    NewValue = 0;
  }
  else
  {
    NewValue = map(raw_value, 0, 255, 100, 255);
  }
  return NewValue;
}
