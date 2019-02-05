int redLed = 3;
int yellowLed = 6;
int greenLed = 9; 
int lockLed = 11;
int potIn = A0;
int potVal = 0;
int ledsLit = 0;
int combination[6] = {79, 32, 54};

bool checking = false;
bool locked = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(lockLed, OUTPUT);
  pinMode(potIn, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potIn) / 10;
  Serial.println(potVal);
  Serial.println('\0');
  
  if (locked){
    digitalWrite(lockLed, HIGH);
  
    switch(ledsLit){

      case 0: 
       if (potVal == combination[0]){
        if(!checking){
          CheckPin(redLed);     
          }
          
         break;
      }
          
       

       case 1: 
        if (potVal == combination[1]){
          if(!checking){
           CheckPin(yellowLed);
          }
          
          break;
       }

       

       case 2: 
        if (potVal == combination[2]){
          if(!checking){
            CheckPin(greenLed);
          }
          
          
          break;
       }
        
       

       default: break;
    }
    if(ledsLit == 3){
      locked = false;
    }
    }
    else{
      digitalWrite(lockLed, LOW);
    }
    
}

void CheckPin(int pin){
  checking = true;
  Flash(pin);
  delay(950);
  potVal = analogRead(potIn) / 10;
  if(potVal == combination[ledsLit]){
    digitalWrite(pin, HIGH);
    ledsLit++;
  
  }
  checking = false;
}

void Flash(int pin){
  digitalWrite(pin, HIGH);

  delay(50);
  
  digitalWrite(pin, LOW);
}


