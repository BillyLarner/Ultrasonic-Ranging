#define trigPin 12          //defines trigPin
#define echoPin 11          //defines echoPin
#define MAX_DISTANCE 200    //sensors maximum range set to 200cm

float timeOut = MAX_DISTANCE * 60;    //defines the timeOut as the maximum range multipiled by 60
int soundVelocity = 340;              //defines the speed of sound in air as 340m/s

void setup() {
  pinMode(trigPin, OUTPUT);   //sets trigPin to output
  pinMode(echoPin, INPUT);    //sets echoPin to input
  Serial.begin(9600);         //opens serial monitor at baud rate 9600

}

void loop() {
  delay (100);                //waits 100ms
  Serial.print("Ping: ");     //prints "ping: "
  Serial.print(getSonar());   //prints the float getSonar
  Serial.println("cm");       //prints "cm" and ends the line 
}

float getSonar() {                                            //creates a float called getSonar
  unsigned long pingTime;                                     //stores pingTime
  float distance;                                             //creates a float called distance
  digitalWrite(trigPin, HIGH);                                //sets trigPin to high
  delayMicroseconds (10);                                     //waits 10 microseconds
  digitalWrite(trigPin, LOW);                                 //sets trigPin to low
  pingTime = pulseIn(echoPin, HIGH, timeOut);                 //waits for ultrasonic wave return and measure time taken
  distance = (float)pingTime * soundVelocity / 2 /  10000;    //uses the time taken for the wave to return to calculate the distance
  return distance;                                            //returns the distance value
}