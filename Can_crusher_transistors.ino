// Arduino controlled 3 dimentional can crusher

int button2=11;
int button1=12;

void setup() {
// writing the relay pins high to make sure they are not on when the program starts
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);

  pinMode(3,OUTPUT);  //Pin 3 for crush sequence #1
  pinMode(4,OUTPUT);   //Pin 4 for crush sequence #2
  pinMode(5,OUTPUT);   //Pin 5 for crush sequence #3
  pinMode(6,OUTPUT);   //Pin 6 for blowrer
  pinMode(7,OUTPUT);  //Pin 7 for feeder
  pinMode(8,OUTPUT);  //Pin 8 for buzzer
  pinMode(11,INPUT_PULLUP); // Pin 11 for table (remote) start button
  pinMode(12,INPUT_PULLUP);   //Pin 12 for board start button

Serial.begin(9600);

}

void loop() {
int buttonState1 = digitalRead(button1);
  int buttonState2 = digitalRead(button2);
  Serial.print("button 1= ");
  Serial.print(buttonState1);
  Serial.print ("  button 2= ");
  Serial.println(buttonState2);
  //delay(1000);
 //if ((digitalRead(button1) == LOW))
 if ((digitalRead(button1) == LOW) &&(digitalRead(button2) == LOW))
{ 
int buttonState = digitalRead(button1);
  // print out the state of the button:
 // Buzzer
 //delay(500);
 digitalWrite(8,HIGH);
 delay(150);
 digitalWrite(8,LOW);
 Serial.println("Buzzer");
 delay(1000);
// Load can
  digitalWrite(7,HIGH);
  delay(1000);
  //indexcans
  digitalWrite(7,LOW);
   Serial.println("Index");
  delay(1000);  
    // Crush step 1
    digitalWrite(3,HIGH);
     Serial.println("crush1");
  delay(1000);
  //Crush step 2
  digitalWrite(4,HIGH);
  
 Serial.println("Crush2");
  delay(1500);
 //Crush step 3
  digitalWrite(5,HIGH);
  
 Serial.println("Crush3");
  delay(1500);
  //Retract step 3
  digitalWrite(5,LOW);
  
 Serial.println("Crush retract 1");
  delay(500);
  //Retract step 2
  digitalWrite(4,LOW);
   Serial.println("Crush retract 2"); 
  delay(100); 
  //blower warning
  digitalWrite(6,HIGH);
   Serial.println("blower");
  delay(100);
  digitalWrite(6,LOW);
  //Retract step 1  
  digitalWrite(3,LOW); 
   Serial.println("Crush retract 3");
  delay(1000);
  //Eject
  digitalWrite(6,HIGH);
   Serial.println("blower");
  delay(300);
  digitalWrite(6,LOW);
  delay(500);

}
}
