const int enable = 3;
const int in1 = 2;
const int in2 = 4;

const int potar = 0;

void setup() {
 pinMode(enable, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);

  Serial.begin(115200);

  analogWrite(enable,0);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
}

void loop() {
  char str[100];
  int vitesse =analogRead(potar);

 /* if(true)
  {
    //digitalWrite(in1, LOW);
    //digitalWrite(in2, HIGH);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }*/
   //vitesse /=4;

   analogWrite(enable, 99);

  sprintf(str,"%d",vitesse);
   Serial.println(str);
   delay(50);

}
