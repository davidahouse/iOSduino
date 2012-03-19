//
// redparkBot sketch
//
#include <Servo.h>

int rightMotorPin = 11;
int leftMotorPin = 10;
int bumperPin = 7;
int bumperState = 0;

Servo rightMotor;
Servo leftMotor;

void setup()
{
  rightMotor.attach(rightMotorPin);
  leftMotor.attach(leftMotorPin);
  pinMode(bumperPin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  // check for any new commands from the serial line
  if ( Serial.available() > 1 )
  {
    // try to read 2 bytes from the iPhone. This will be our motor speeds that we should
    // set.
    leftMotor.write(Serial.read());
    rightMotor.write(Serial.read());
  }
  
  // check the status of the bumper switch and send it back to the  
  // iPhone
  if ( digitalRead(bumperPin) == HIGH )
    bumperState = 1;
  else
    bumperState = 0;
   
  Serial.print(bumperState);

  // just a short sleep
  delay(250);
}




