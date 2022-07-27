/**********************************
* name:Quiz Buzzer Building a Quiz Buzzer System
* function: first press button 4 to start. If you press button 1 first, you will see the corresponding LED light up and the buzzer will beep. Then press button 4 again to reset before you press other buttons.
* online inspiration:  https://learn.sunfounder.com/lesson-7-building-a-quiz-buzzer-system/
* 
**********************************/

int LEDpin1 = 13;
int LEDpin2 = 4;
int LEDpin3 = 3;
int LEDpin4 = 11;
int LEDpin5 = 10;

int button1pin = 9;
int button2pin = 8;
int button3pin = 7;
int button5pin = 6;
int button4pin = 12;

int buzzerpin = 5;

int button5state;

byte leds = 0;

void setup()
{
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(LEDpin3, OUTPUT);
  pinMode(LEDpin4, OUTPUT);
  pinMode(LEDpin5, OUTPUT);
  pinMode(button1pin, INPUT_PULLUP);
  pinMode(button2pin, INPUT_PULLUP);
  pinMode(button3pin, INPUT_PULLUP);
  pinMode(button4pin, INPUT_PULLUP);
  pinMode(button5pin, INPUT_PULLUP);
  pinMode(buzzerpin, OUTPUT);
}

void loop()
{
  digitalWrite(LEDpin1, LOW);
  digitalWrite(LEDpin2, LOW);
  digitalWrite(LEDpin3, LOW);
  digitalWrite(LEDpin4, LOW);
  digitalWrite(LEDpin5, HIGH);
  button5state = digitalRead(button5pin);
  if(button5state == 0)
  {
    if(button5state == 0)
    {
      leds = 1;
      digitalWrite(LEDpin5, HIGH); 
      delay(200);
    }
  }
  if (digitalRead(button1pin) == LOW)
  {
    if(digitalRead(LEDpin5) == HIGH)  //THIS MAKES IT SO BUTTON5 HAS TO BE HELD DOWN.
    {
      digitalWrite(LEDpin1, HIGH);
      Alarm();
      digitalWrite(LEDpin2, LOW);
      digitalWrite(LEDpin3, LOW);
      digitalWrite(LEDpin4, LOW);
      digitalWrite(LEDpin5, LOW);
      while(digitalRead(button5pin));
    }
  }
  if (digitalRead(button2pin) == LOW)
  {
    if(digitalRead(LEDpin5) == HIGH)
    {
      digitalWrite(LEDpin2, HIGH);
      Alarm();
      digitalWrite(LEDpin1, LOW);
      digitalWrite(LEDpin3, LOW);
      digitalWrite(LEDpin4, LOW);
      digitalWrite(LEDpin5, LOW);
      while(digitalRead(button5pin));
    }
  }
  if (digitalRead(button3pin) == LOW)
  {
    if(digitalRead(LEDpin5) == HIGH)
    {
      digitalWrite(LEDpin3, HIGH);
      Alarm();
      digitalWrite(LEDpin2, LOW);
      digitalWrite(LEDpin1, LOW);
      digitalWrite(LEDpin4, LOW);
      digitalWrite(LEDpin5, LOW);
      while(digitalRead(button5pin));
    }
  }
  if (digitalRead(button4pin) == LOW)
  {
    if(digitalRead(LEDpin5) == HIGH)
    {
      digitalWrite(LEDpin4, HIGH);
      Alarm();
      digitalWrite(LEDpin2, LOW);
      digitalWrite(LEDpin3, LOW);
      digitalWrite(LEDpin1, LOW);
      digitalWrite(LEDpin5, LOW);
      while(digitalRead(button5pin));
    }
  }
  if (digitalRead(button5pin) == LOW)
  {
    digitalWrite(LEDpin1, LOW);
    digitalWrite(LEDpin2, LOW);
    digitalWrite(LEDpin3, LOW);
    digitalWrite(LEDpin4, LOW);
    leds == 1;
  }
}

void Alarm()
{
  
    tone(buzzerpin,880); //the buzzer sound
    delay(200);
    tone(buzzerpin,587);
    delay(200);
    tone(buzzerpin,880); //without sound
    delay(200); //when delay time changed,the frequency changed
    noTone(buzzerpin);
}
