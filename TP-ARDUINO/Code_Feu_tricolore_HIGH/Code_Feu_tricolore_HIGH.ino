
int pinR1=8;
int pinO1=9;
int pintG1=10;


int pinR2=11;
int pinO2=12;
int pintG2=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinR1, OUTPUT);
  pinMode(pinO1, OUTPUT);
  pinMode(pinG1, OUTPUT);
  
  pinMode(pinR2, OUTPUT);
  pinMode(pinO2, OUTPUT);
  pinMode(pinG2, OUTPUT);
}

void loop() {
 digitalWrite(pinR1, HIGH);
 digitalWrite(pinG2, HIGH);
 delay(3000);

 digitalWrite(pinG2, LOW);
 digitalWrite(pinO2, HIGH);
 delay(2000);

  digitalWrite(pinO2, LOW);
 digitalWrite(pinR2, HIGH);
 delay(1000);
 
 digitalWrite(pinG1, HIGH);
  delay(3000);

digitalWrite(pinG1, LOW);
  digitalWrite(pinO1, HIGH);
  delay(1000);

  digitalWrite(pinO1, LOW);

}
