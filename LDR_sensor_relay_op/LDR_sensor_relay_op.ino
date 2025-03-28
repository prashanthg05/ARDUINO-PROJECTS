#define SENSOR_PIN 9
#define RELAY_PIN 10
#define START_DELAY 1000  //1 seconds 
#define ON_TIME 2000      //2 seconds Sprinkler on time

unsigned long previousTime = millis();

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);  
}

void loop() 
{
  //If there is fire then the sensor value will be LOW else the value will be HIGH
  int sensorValue = digitalRead(SENSOR_PIN);

  //There is fire
  if (sensorValue == LOW)
  {

    if (millis() - previousTime > START_DELAY)  //We will wait for few seconds before sprinkler can be started once fire is detected.
    {
      digitalWrite(RELAY_PIN, HIGH);                       //Relay is low level triggered relay so we need to write LOW to switch on the light 
      delay(SPRINKLER_ON_TIME);                           //Keep sprinkler on for sometime.
    }
  }
  else
  {    
    digitalWrite(RELAY_PIN, LOW); 
    previousTime = millis();  
  }
} 
