#define SONAR_TRIGGER_PIN              2
#define SONAR_ECHO_PIN                 3

unsigned int measure_distance()
{
   // send the sensor a 10 microsecond pulse:
   digitalWrite(SONAR_TRIGGER_PIN, HIGH);
   delayMicroseconds(10);
   digitalWrite(SONAR_TRIGGER_PIN, LOW);
   
   if
   (digitalRead(SONAR_ECHO_PIN)==HIGH)
   {Serial.println("fucked!");}
   
   // wait for the pulse to return. The pulse
   // goes from low to HIGH to low, so we specify
   // that we want a HIGH-going pulse below:
   unsigned long pulse_length = pulseIn(SONAR_ECHO_PIN, HIGH);

   // can't send more than one pulse each 50 ms or
   // we could get interference
   delay(500);

   // convert to inches and return
   return( (unsigned int) (pulse_length / 148) );
   // return(pulse_length);
}


void setup()
{
   pinMode(SONAR_TRIGGER_PIN,          OUTPUT);
   pinMode(SONAR_ECHO_PIN,             INPUT);
   Serial.begin(9600);
   Serial.println("hellooooo");
}


void loop()
{
   unsigned int current_distance = measure_distance();
   Serial.println(current_distance);
}
