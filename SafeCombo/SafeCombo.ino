int redLed = 3;
int yellowLed = 6;
int greenLed = 9; 
int lockLed = 11;
int potIn = A1;
int potVal = 0;
int ledsLit = 0;
int button = 2;
int vib = 13;
//int combination[6] = {random(99), random(99), random(99)};
int combination[6] = {84, 10, 64};

bool checking = false;
bool locked = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
//  Serial.println(randomSeed);
//  Serial.println('\0');
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(lockLed, OUTPUT);
  pinMode(potIn, INPUT);
  pinMode(button, INPUT);
  pinMode(vib, OUTPUT);
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

    if(digitalRead(button) == HIGH){
      Reset();
    }
    
}

void CheckPin(int pin){
  checking = true;
  Flash(pin);
  delay(950);
  
  potVal = analogRead(potIn) / 10;
  if(potVal == combination[ledsLit]){
    digitalWrite(pin, HIGH);
    digitalWrite(vib, HIGH);
    delay(500);
    digitalWrite(vib, LOW);
    ledsLit++;
  
  }
  checking = false;
}

void Flash(int pin){
//  digitalWrite(pin, HIGH);

//  delay(50);
  
//  digitalWrite(pin, LOW);

  digitalWrite(vib, HIGH);

  delay(50);

  digitalWrite(vib, LOW);
}

void Reset(){
  randomSeed(analogRead(A1));
//  combination[6] = new int[6] {random(99), random(99), random(99)};
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
  ledsLit = 0;
  locked = true;
  digitalWrite(vib, HIGH);
  delay(10);
  digitalWrite(vib, LOW);
  
}

