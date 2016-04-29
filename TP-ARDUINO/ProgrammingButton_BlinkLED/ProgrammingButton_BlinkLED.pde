/**
 * Button. 
 * 
 * Click on one of the colored squares in the 
 * center of the image to change the color of 
 * the background. 
 */
 
import processing.serial.*;
import cc.arduino.*;

int rectX, rectY;      // Position of square button
int rectSize = 90;     // Diameter of rect
color rectColor,  baseColor;
color rectHighlight;
color currentColor;
boolean rectOver = false;
boolean light=true;

Arduino arduino;
int ledPin = 13;
void setup()
{
  size(640, 360);
  rectColor = color(0);
  rectHighlight = color(51);
  baseColor = color(102);
  currentColor = baseColor;
  rectX = width/2-rectSize-10;
  rectY = height/2-rectSize/2;
  
  println(Arduino.list());
  arduino = new Arduino(this, Arduino.list()[1], 115200); // v1
  arduino.pinMode(ledPin, Arduino.OUTPUT);
}

void draw() {  
      
  update(mouseX, mouseY);
  background(currentColor);
  
  if (rectOver) {
    fill(rectHighlight);
  } else {
    fill(rectColor);
  }
  stroke(255);
  rect(rectX, rectY, rectSize, rectSize);
  
 
}

void update(int x, int y) {
  if ( overRect(rectX, rectY, rectSize, rectSize) ) {
    rectOver = true;
  } else {
   rectOver = false;
  }
}

boolean overRect(int x, int y, int width, int height)  {
  if (mouseX >= x && mouseX <= x+width && 
      mouseY >= y && mouseY <= y+height) {
    return true;
  } else {
    return false;
  }
}

void mousePressed() {
  if(light)
  {
      arduino.digitalWrite(13, Arduino.HIGH);
      currentColor=color(200);
      
  }
  else
  {
    arduino.digitalWrite(13, Arduino.LOW);    
  }
  light = !light;
}