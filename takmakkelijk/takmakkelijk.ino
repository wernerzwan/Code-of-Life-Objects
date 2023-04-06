const int motorPin1 = 3;

void setup()
{ 
  TCCR2B = TCCR2B & B11111000 | B00000111; // for PWM frequency of 30.64 Hz
  pinMode(3, OUTPUT); 
}
void loop()
{
analogWrite(motorPin1, random(200, 250));
delay(random(300, 1500));
analogWrite(motorPin1, 0);
delay(random(4000, 20000));
}
