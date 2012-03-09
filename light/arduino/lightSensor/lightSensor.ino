//
// lightSensor.ino
//

//
// setup()
//
void setup()
{
  // setup an input pin for the light sensor
  pinMode(2,INPUT);	

  // setup the output pins for the LEDs
  pinMode(13,OUTPUT); 
  pinMode(12,OUTPUT); 
  pinMode(11,OUTPUT); 
  pinMode(10,OUTPUT); 
  pinMode(9,OUTPUT); 
  pinMode(8,OUTPUT); 
  pinMode(7,OUTPUT); 
  pinMode(6,OUTPUT); 
  pinMode(5,OUTPUT); 
  
  Serial.begin(9600);
}


//
// loop()
//
void loop()
{
  // read the light sensor input value
  int reading = analogRead(2);
  Serial.print("analog = ");
  Serial.println(reading);

  // the higher the value, the greater number of LEDs to light up
  setLED(13,reading,100);
  setLED(12,reading,200);
  setLED(11,reading,300);
  setLED(10,reading,400);
  setLED(9,reading,500);
  setLED(8,reading,600);
  setLED(7,reading,700);
  setLED(6,reading,800);
  setLED(5,reading,900);
}

//
// setLED()
//
// Turn on/off one of the LEDs based on a threshold
//
void setLED(int pin,int reading, int threshold)
{
  if ( reading > threshold )
    digitalWrite(pin,HIGH);
  else
    digitalWrite(pin,LOW);
}



