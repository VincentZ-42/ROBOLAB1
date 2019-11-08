///////////////////////////////////////////////////////////////// MOVEMENTS ///////////////////////////////////////////////////////
// move the centerpiece upward with same speed for both motor
void goUp(int vol)
{
  if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, vol);
    
    analogWrite(RPWMOutputRight, vol);
    analogWrite(LPWMOutputRight, 0);
}

// move the centerpiece upward with differnt speed for each motor
void goUp_v2(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, volL);
    
    analogWrite(RPWMOutputRight, volR);
    analogWrite(LPWMOutputRight, 0);
}

// move the centerpiece downward with same speed for both motor
void goDown(int vol)
{
  if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, vol);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, vol);
}

// move the centerpiece upward with differnt speed for each motor
void goDown_v2(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(RPWMOutputLeft, volL);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, volR);
}

// move the centerpiece rightward with same speed for both motor
void goRight(int vol)
{
  if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, vol);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, vol);
    analogWrite(LPWMOutputRight, 0);
}

// move the centerpiece rightward with differnt speed for each motor
void goRight_v2(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(RPWMOutputLeft, volL);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, volR);
    analogWrite(LPWMOutputRight, 0);
}

// move the centerpiece leftward with same speed for both motor
void goLeft(int vol)
{
  if (vol >= 255)
    vol = 255;    
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, vol);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, vol);
}

// move the centerpiece leftward with differnt speed for each motor
void goLeft_v2(int volL, int volR)
{
  if (volL >= 255)
    volL = 255;
  if (volR >= 255)
    volR = 255;
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, volL);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, volR);
}

// move the centerpiece upward and rightward with same speed for both motor
void goUpRight(int vol)
{
    if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputRight, vol);
    analogWrite(LPWMOutputRight, 0);
}

// move the centerpiece downward and leftward with same speed for both motor
void goDownLeft(int vol)
{
    if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, vol);
}

// move the centerpiece upward and leftward with same speed for both motor
void goUpLeft(int vol)
{
    if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, vol);
}

// move the centerpiece downward and rightward with same speed for both motor
void goDownRight(int vol)
{
    if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, vol);
    analogWrite(LPWMOutputLeft, 0);
}

// stop moving left motor
void stopLeft()
{
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, 0);
}

// stop moving right motor
void stopRight()
{
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, 0);
}

// stop moving both motors
void doStop()
{
    stopLeft();
    stopRight();
}

// This function allows the centerpiece to move as well as use the to turn the sprayer on and off
// If the trigger is on, then you will not be able to move the centerpiece
void main_Moving_with_trigger(int click_status)
{
  int spraying = false;
  
  joystick(VRx, VRy, encoderLeft, encoderRight);
  if (click_status == 0 && spraying == false) {
    spray();
    spraying = true;
  }
  while (spraying == true) {
    if (digitalRead(SW) == 0) {
      stopSpraying();
      spraying = false;
    }
  Serial.println(MiddleMotorEnc.read());

    
  }
}
