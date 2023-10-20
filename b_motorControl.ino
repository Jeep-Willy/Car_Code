void motorControl() {

  if (RadioManager.available())
  {
    
 // Wait for a message addressed to us from the client
    uint8_t len = sizeof(buf);
    uint8_t from;
    if (RadioManager.recvfromAck(buf, &len, &from))
 
    {
 
      // Serial Print the values of joystick
      Serial.print(": MotorA = ");
      Serial.print(buf[0]);
      Serial.print(" Dir = ");
      Serial.println(buf[2]);
      
      // Set Motor Direction
      if (buf[2] == 1)
      {

    // Motors are backwards
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    }else{

    // Motors are forwards
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

     }
 
      analogWrite(enA, buf[0]);
     
      // Send a reply back to the originator client, check for error
      if (!RadioManager.sendtoWait(ReturnMessage, sizeof(ReturnMessage), from))
        Serial.println("sendtoWait failed");
    }
  }              
}