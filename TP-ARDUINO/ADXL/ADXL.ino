const int xpin = 0;
const int ypin = 1;
const int zpin = 2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int x = analogRead(xpin);
  delay(1);
  int y = analogRead(ypin);
  delay(1);
  int z = analogRead(zpin);
  delay(1);
  
  float zero_G = 512.0;
  float scale = 102.3;
 /* 
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.print(z);
  Serial.print("\n");
  */
  Serial.print("X : ");
  Serial.print(((float)x - 331.5) / 65 * 9.8);
  Serial.print("\t");
  Serial.print("Y : ");
  Serial.print(((float)y - 329.5) / 68.5 * 9.8);
  Serial.print("\t");
  Serial.print("Z : ");
  Serial.print(((float)z - 340) / 68 * 9.8);
  Serial.print("\n");
  
  delay(300);
}
