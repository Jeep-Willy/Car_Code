void motorControl() {
      
  // Set Motor Direction
  if (buf[1] == 1) {

    // Motors are backwards
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

  } else {

    // Motors are forwards
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

  }
 
  // Write values for motor
  analogWrite(enA, buf[0]); 
             
}