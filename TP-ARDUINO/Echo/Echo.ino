void setup() {
  // put your setup code here, to run once:
  // Bien changer en 9600 baud dans la console pour pouvoir afficher 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // lorsqu'on envoit un character, il l'écrit dans la console en numero ASCI
  if( Serial.available() ){
    
    int lu = Serial.read();
    Serial.println(lu);
    delay ( 1000 );
  }else{
    Serial.println("hello");
  }
  
  Serial.println();
  delay ( 1000 );
}

//
