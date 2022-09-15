// C++ code
//SMART HOME

const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int tempPin=0;
void setup()
{
  Serial.begin(9600); // Starting Serial Terminal
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(3,OUTPUT);
}

void loop()
{
  long distcm,duration;
  float temp;
  temp=analogRead(tempPin);
  temp=temp*0.4882815;
  if(temp>70)
  {  
  	digitalWrite(3, HIGH);
  }
  else
  {  
  	digitalWrite(3,LOW);
  }
    
  delay(1000);
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  distcm = duration*0.0343/2;
  // Turns the LED ON when the water level drops below 100cm.
  if(distcm<100)
  {  
  	digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
  	digitalWrite(LED_BUILTIN, LOW);
  }
}