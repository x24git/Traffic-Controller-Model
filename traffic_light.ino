int eastWest = 0;
int northSouth = 1;
double IRBase = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int startPin = 5;

   // 4-9 are the output pins
  for (int i=4; i <= 9; i++)
    pinMode(i, OUTPUT);

  // 10-13 are the input pins
  for (int i=10; i <= 13; i++)
    pinMode(i, INPUT);

  for (int i=4; i <= 9; i++)
    digitalWrite(i, HIGH);

  for(int i=0; i < 100; i++){
    IRBase += analogRead(0);
    Serial.println(IRBase);
  }
  IRBase = IRBase/100;
  Serial.println(IRBase);
  delay(5000);
  for (int i=4; i <= 9; i++)
    digitalWrite(i, LOW);

  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  /**            R Y G
   east-west =   7,8,9
   north-south = 4,5,6 
  **/
  start:
  while(analogRead(0) <= IRBase - 4)
  {
    override:
    if (northSouth == 1)
    {    
      digitalWrite(6, LOW);
      digitalWrite(5, HIGH);
      delay(2000);
      digitalWrite(5, LOW);
      northSouth = 0;
    }
    if (eastWest == 1)
    {
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
      delay(2000);
      digitalWrite(8, LOW);
      eastWest = 0;
    }
    digitalWrite(7,HIGH);
    digitalWrite(4,HIGH);
    goto wait;
  }
  if (digitalRead(10) == 0 || digitalRead(12) == 0) 
  {
    delay(5000);
    if (northSouth == 1)
    {    
      digitalWrite(6, LOW);
      
      digitalWrite(5, HIGH);
      delay(2000);
      digitalWrite(5, LOW);
      
      northSouth = 0;
    }
    digitalWrite(7, LOW);
    digitalWrite(9, HIGH);
    
    digitalWrite(4, HIGH);
    eastWest = 1;
    goto wait;
  }

  if (digitalRead(11) == 0 || digitalRead(13) == 0) 
  {
    delay(5000);
    if (eastWest == 1)
    {
      digitalWrite(9, LOW);
      
      digitalWrite(8, HIGH);
      delay(2000);
      digitalWrite(8, LOW);
      
      eastWest = 0;
    }
    digitalWrite(7, HIGH);
    
    digitalWrite(6, HIGH);
    digitalWrite(4, LOW);
    northSouth = 1;
    goto wait;
  }
  goto start;
  wait:
   for (int i=0; i<10; i++)
  {
    delay(1000);
    if(analogRead(0) <= IRBase - 4)
      goto override;
  }
  goto start;
}
