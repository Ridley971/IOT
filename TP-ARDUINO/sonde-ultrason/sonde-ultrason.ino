int trig = 12;
int echo = 11;

long lecture_echo;
long cm;
int cpt = 0;
int tab[100];

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  digitalWrite(trig,LOW);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  lecture_echo = pulseIn(echo,HIGH);
  cm = lecture_echo / 58;
  Serial.print("Distance : ");
  Serial.println(cm);
  delay(500);
  if(cpt == 99) {
    for(int i= 0 ; i < cpt ; i++){
        Serial.print("Distance numero");
        Serial.print(i+1);
        Serial.print(" : ");
        Serial.println(tab[i]);
    }
  }
  else {
    tab[cpt] = cm;
    cpt++;
  }
  
}
