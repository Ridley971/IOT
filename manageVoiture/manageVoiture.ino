
//ultrasons
int trig = 12;
int echo = 11;

long lecture_echo;
long cm;
int cpt = 0;//compteur
long[30] datas; //Estimation 30 datas to made 360°

//Right Motors
const int pwmMotor1 = 3;
const int in1 = 2;
const int in2 = 4;

//Left Motors
const int pwmMotor2 = 6;
const int in3 = 5;
const int in4 = 7;

void setup() {
  //configuration ultrasons
   pinMode(trig,OUTPUT);
  digitalWrite(trig,LOW);
  pinMode(echo, INPUT);

  //configuration motors
  pinMode(pwmMotor1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  analogWrite(pwmMotor1,0);
  

  
  pinMode(pwmMotor2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  analogWrite(pwmMotor2,0);

  Serial.begin(9600);
}

void loop() {
  if( Serial.available() )
  {
      char lu = Serial.read();
  
     switch(lu) 
     {
  
       case 'z'  :
          Serial.println("forward");
          analogWrite(pwmMotor1,50);      
          analogWrite(pwmMotor2,50);
    
          //Right
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          //Left
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
    
          delay(2000);
          break; 
     
       case 's'  :
          Serial.println("backward");
          analogWrite(pwmMotor1, 50);      
          analogWrite(pwmMotor2, 50);
    
          //Right
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          //Left
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
    
          delay(2000);
          break; 
       case 'q'  :
          Serial.println("Left");
    
          analogWrite(pwmMotor1, 50);      
          analogWrite(pwmMotor2, 50);
    
          while(cpt<30) //Estimation to made 360° 
          {
            //Right
            digitalWrite(in1, HIGH);
            digitalWrite(in2, LOW);
            
            //Left
            digitalWrite(in3, LOW);
            digitalWrite(in4, HIGH);
      
            delay(2000);//Turn during 2secs
      
            // Get ultrasons data
            digitalWrite(trig, HIGH);      
            delayMicroseconds(10);
            digitalWrite(trig,LOW);
            lecture_echo = pulseIn(echo,HIGH);
            cm = lecture_echo / 58;
      
            datas[cpt]=cm;// Add datas to table
            cpt++;
      
            
            Serial.print("Distance : ");
            Serial.println(cm);
            delay(500);
          }
          break; 
     
       case 'd' :
          Serial.println("Right");
    
          
          analogWrite(pwmMotor1, 50);      
          analogWrite(pwmMotor2, 50);
    
          while(cpt<30)
          {
            //Right
            digitalWrite(in1, LOW);
            digitalWrite(in2, HIGH);
            
            //Left
            digitalWrite(in3, HIGH);
            digitalWrite(in4, LOW);
          
            // Get ultrasons data
            digitalWrite(trig, HIGH);      
            delayMicroseconds(10);
            digitalWrite(trig,LOW);
            
            lecture_echo = pulseIn(echo,HIGH);
            cm = lecture_echo / 58;
      
            datas[cpt]=cm;// Add datas to table
            cpt++;
      
            
            Serial.print("Distance : ");
            Serial.println(cm);
            delay(500);
          }
          break;     
    }
 }
}
