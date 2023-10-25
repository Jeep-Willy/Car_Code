void receiveData() {

  if (RadioManager.available()) {
    
    // Wait for a message addressed to us from the client
    uint8_t len = sizeof(buf);
    uint8_t from;

    if (RadioManager.recvfromAck(buf, &len, &from)) {
 
      // Serial Print the values of the motor and servo
      Serial.print("Rear Motor: ");
      Serial.print(buf[0]);
      Serial.print(" Dir: ");
      Serial.println(buf[1]);
      Serial.print("Servo Motor: ");
      Serial.println(buf[2]);

      // Call motor/servoControl()
      motorControl();
      servoControl();

      // Send a reply back to the originator client, check for error
      if (!RadioManager.sendtoWait(ReturnMessage, sizeof(ReturnMessage), CLIENT_ADDRESS))
        Serial.println("sendtoWait failed");

    }

  }

}