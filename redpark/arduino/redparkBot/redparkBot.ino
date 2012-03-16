//
// redparkBot sketch
//
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while ( Serial.available() <= 0 )
  {
    Serial.println("Hello World");
    delay(3000);
  }
  Serial.println("goodbye");
  while(1) { }
}


