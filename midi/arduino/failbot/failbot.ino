/*
  Failbot
*/
#define RIGHT_BACKWARD 8
#define RIGHT_FORWARD 9
#define LEFT_BACKWARD 10
#define LEFT_FORWARD 11


void setup()
{
  pinMode(RIGHT_BACKWARD,OUTPUT);
  pinMode(RIGHT_FORWARD,OUTPUT);
  pinMode(LEFT_BACKWARD,OUTPUT);
  pinMode(LEFT_FORWARD,OUTPUT);
}

void loop()
{
  forward();
  delay(2000);
  backward();
  delay(1000);
  turnRight();
  delay(200);
  forward();
  delay(2500);
  turnRight();
  delay(200);
  forward();
  delay(1500);
  turnLeft();
  delay(2000);
  backward();
  delay(1000);
  turnRight();
  delay(2500);
}

void forward()
{
  digitalWrite(RIGHT_BACKWARD,LOW);
  digitalWrite(RIGHT_FORWARD,HIGH);
  digitalWrite(LEFT_BACKWARD,LOW);
  digitalWrite(LEFT_FORWARD,HIGH);
}

void backward()
{
  digitalWrite(RIGHT_BACKWARD,HIGH);
  digitalWrite(RIGHT_FORWARD,LOW);
  digitalWrite(LEFT_BACKWARD,HIGH);
  digitalWrite(LEFT_FORWARD,LOW);
}

void stop()
{
  digitalWrite(RIGHT_BACKWARD,LOW);
  digitalWrite(RIGHT_FORWARD,LOW);
  digitalWrite(LEFT_BACKWARD,LOW);
  digitalWrite(LEFT_FORWARD,LOW);
}

void turnRight()
{
  digitalWrite(RIGHT_BACKWARD,HIGH);
  digitalWrite(RIGHT_FORWARD,LOW);
  digitalWrite(LEFT_BACKWARD,LOW);
  digitalWrite(LEFT_FORWARD,HIGH);
}

void turnLeft()
{
  digitalWrite(RIGHT_BACKWARD,LOW);
  digitalWrite(RIGHT_FORWARD,HIGH);
  digitalWrite(LEFT_BACKWARD,HIGH);
  digitalWrite(LEFT_FORWARD,LOW);
}


