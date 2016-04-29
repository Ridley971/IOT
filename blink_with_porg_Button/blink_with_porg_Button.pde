import processing.serial.*;

import cc.arduino.*;

Arduino arduino;
int ledPin=13;
int rectX, rectY;      // Position of square button
int rectSize = 90;     // Diameter of rect
color rectColor,rectHighlight;

color currentColor;
boolean rectOver = false;

void setup()
{
  size(640, 360);
  rectColor = color(0);
  rectHighlight = color(51);
  
  rectX = width/2-rectSize-10;
  rectY = height/2-rectSize/2;
  
  arduino= new Arduino(this, Arduino.list()[3], 57600);
  arduino.pinMode(13,Arduino.OUTPUT);
  println(Arduino.list());
}

void draw()
{
  
  //update(mouseX, mouseY);
  arduino.digitalWrite(ledPin, Arduino.HIGH);
  delay(1000);
  arduino.digitalWrite(ledPin, Arduino.LOW);
  delay(1000);
}

boolean overRect(int x, int y, int width, int height)  {
  if (mouseX >= x && mouseX <= x+width && 
      mouseY >= y && mouseY <= y+height) {
    return true;
  } else {
    return false;
  }
}