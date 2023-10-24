
void setup()
{
  // Setup Serial Monitor
  Serial.begin(9600);
  
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);

  // Set servo pin
  myServo.attach(servPin);
  
  // Initialize RadioManager with defaults - 2.402 GHz (channel 2), 2Mbps, 0dBm
  if (!RadioManager.init())
    Serial.println("init failed");
} 
 
void loop()
{

receiveData();

}