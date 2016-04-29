import processing.serial.*;
import cc.arduino.*;

Arduino arduino;
int ledPin = 13;

void setup()
{
  println(Arduino.list());
  //arduino = new Arduino(this, Arduino.list()[1]); // v2
  arduino = new Arduino(this, Arduino.list()[1], 115200); // v1
  arduino.pinMode(ledPin, Arduino.OUTPUT);
}

void draw()
{
  arduino.digitalWrite(ledPin, Arduino.HIGH);
  delay(3000);
  arduino.digitalWrite(ledPin, Arduino.LOW);
  delay(1000);
}