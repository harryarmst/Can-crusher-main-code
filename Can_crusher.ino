// Arduino controlled 3 dimentional can crusher

int button=12;

void setup() {
// writing the relay pins high to make sure they are not on when the program starts
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);

  pinMode(3,OUTPUT);  //Pin 3 for crush sequence #1
  pinMode(4,OUTPUT);   //Pin 4 for crush sequence #2
  pinMode(5,OUTPUT);   //Pin 5 for crush sequence #3
  pinMode(6,OUTPUT);   //Pin 6 for feed cylinder
  pinMode(12,INPUT);   //Pin 7 for start button


}

void loop() {

 if (digitalRead(button) == HIGH)
{ 

// Load can
  digitalWrite(6,LOW);
  delay(500);
  digitalWrite(6,HIGH);
  delay(500);
  // Crush step 1
  digitalWrite(3,LOW);
  delay(1500);
  //Crush step 2
  digitalWrite(4,LOW);
  delay(2000);
 //Crush step 3
  digitalWrite(5,LOW);
  delay(2500);
  //Retract step 3
  digitalWrite(5,HIGH); 
  delay (1000);
  //Retract step 2
  digitalWrite(4,HIGH); 
  delay (1000); 
  //Retract step 1  
  digitalWrite(3,HIGH); 
  delay (1000);
}
}
