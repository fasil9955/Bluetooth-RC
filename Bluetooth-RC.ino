  #include <SoftwareSerial.h>
  #include <NewPing.h>

  SoftwareSerial mySerial(10,11);
  char ReceivedData;

  int LM1 = 5;
  int LM2 = 4;
  int RM1 = 2;
  int RM2 = 3;
  int LED = 8;

  void Stop()
  {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
  }
  void Forward()
  {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,HIGH);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
  }
  void Backward()
  {
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
  }
  void SpotRight ()
 {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,80);
    digitalWrite(RM1,80);
    digitalWrite(RM2,LOW);
  }
    void ArcRight ()
  {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,70);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
  }
   void BackArcRight ()
  {
    digitalWrite(LM1,70);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
  }
  void SpotLeft ()
  {
    digitalWrite(LM1,80);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,80);
  }
  void ArcLeft ()
  {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,70);
  }
  void BackArcLeft ()
  {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,70);
    digitalWrite(RM2,LOW);
  }
  void setup()
  {
    pinMode(LM1,OUTPUT);
    pinMode(LM2,OUTPUT);
    pinMode(RM1,OUTPUT);
    pinMode(RM2,OUTPUT);
    Serial.begin(9600);
    mySerial.begin(38400);
  }

  void loop()
  {
    if (mySerial.available()>0)
    {
      ReceivedData = mySerial.read();
    }
    if (ReceivedData =='F')
    {
      Forward();
      Serial.println("Forward");
    }
    else if (ReceivedData =='B')
    {
      Backward();
      Serial.println("Backward");
    }
    else if (ReceivedData =='L')
    {
      SpotLeft();
      Serial.println("Left");
    }
    else if (ReceivedData =='R')
    {
      SpotRight();
      Serial.println("Right");
    }
    else if (ReceivedData =='I')
    {
      ArcRight();
      Serial.println("ArcRight");
    }
    else if (ReceivedData =='G')
    {
      ArcLeft();
      Serial.println("ArcLeft");
    }
    else if (ReceivedData =='J')
    {
      BackArcRight();
      Serial.println("BackArcRight");
    }
     else if (ReceivedData =='H')
    {
      BackArcLeft();
      Serial.println("BackArcLeft");
    }
    else{
      Stop();
      Serial.println("Stop");
    }
    
      
    
      
  }
  
