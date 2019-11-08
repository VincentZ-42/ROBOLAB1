bool joystick(const int VRx, const int VRy, int encoderLeft, int encoderRight)
{
    readX = analogRead(VRx);
    readY = analogRead(VRy);
//    Serial.print("X-axis: ");
//    Serial.println(readX);
//    Serial.print("Y-axis: ");
//    Serial.println(readY);
//    Serial.print(encoderLeft);
//    Serial.print(" - ");
//    Serial.println(encoderRight);
//    Serial.print("\n\n");
    while (readX < 300)
    {
      goRight_v2(200, 200);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readX > 700)
    {
      goLeft_v2(200, 200);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readY < 300)
    {
      goUp_v2(200, 200);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readY > 700)
    {
      goDown_v2(200, 200);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
}
