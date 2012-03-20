//
// midiBot.ino
//

#define LEFT_FORWARD_PIN 8
#define LEFT_REVERSE_PIN 9
#define RIGHT_FORWARD_PIN 10
#define RIGHT_REVERSE_PIN 11
#define SOUND_PIN 12

int playingSound;

//
// setup()
//
void setup()
{
  // setup serial for receiving MIDI input
  Serial.begin(31250);
  
  pinMode(LEFT_FORWARD_PIN,OUTPUT);
  pinMode(LEFT_REVERSE_PIN,OUTPUT);
  pinMode(RIGHT_FORWARD_PIN,OUTPUT);
  pinMode(RIGHT_REVERSE_PIN,OUTPUT);
  pinMode(SOUND_PIN,OUTPUT);
  playingSound = 0;
}

//
// loop()
//
void loop()
{
  // read commands from the MIDI input
  if ( Serial.available() > 2 )
  {
    byte message = Serial.read(); 
    byte note = Serial.read();
    byte velocity = Serial.read();
    
    if ( note == 0 )
    {
      digitalWrite(SOUND_PIN,HIGH);
      playingSound = 1;
    }
    else if ( note == 1 )
    {
      digitalWrite(LEFT_FORWARD_PIN,HIGH);
      digitalWrite(LEFT_REVERSE_PIN,LOW);
      digitalWrite(RIGHT_FORWARD_PIN,HIGH);
      digitalWrite(RIGHT_REVERSE_PIN,LOW);
    }
    else if ( note == 2 )
    {
      digitalWrite(LEFT_FORWARD_PIN,LOW);
      digitalWrite(LEFT_REVERSE_PIN,HIGH);
      digitalWrite(RIGHT_FORWARD_PIN,LOW);
      digitalWrite(RIGHT_REVERSE_PIN,HIGH);
    }
    else if ( note == 3 )
    {
      digitalWrite(LEFT_FORWARD_PIN,LOW);
      digitalWrite(LEFT_REVERSE_PIN,HIGH);
      digitalWrite(RIGHT_FORWARD_PIN,HIGH);
      digitalWrite(RIGHT_REVERSE_PIN,LOW);
    }
    else if ( note == 4 )
    {
      digitalWrite(LEFT_FORWARD_PIN,HIGH);
      digitalWrite(LEFT_REVERSE_PIN,LOW);
      digitalWrite(RIGHT_FORWARD_PIN,LOW);
      digitalWrite(RIGHT_REVERSE_PIN,HIGH);
    }
    else if ( note == 5 )
    {
      digitalWrite(LEFT_FORWARD_PIN,LOW);
      digitalWrite(LEFT_REVERSE_PIN,LOW);
      digitalWrite(RIGHT_FORWARD_PIN,LOW);
      digitalWrite(RIGHT_REVERSE_PIN,LOW);
    }
  }

  if ( playingSound >= 1 )
  {
    playingSound++;
    if ( playingSound > 4 )
    {
      digitalWrite(SOUND_PIN,LOW);
      playingSound = 0;     
    }
  }

  delay(100);	
}
