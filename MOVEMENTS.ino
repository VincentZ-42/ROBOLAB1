///////////////////////////////////////////////////////////////// MOVEMENTS ///////////////////////////////////////////////////////

void goUp(int vol)
{
  if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, vol);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, vol);
}

void goUp_v2(int volL, int volR)
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

void goDown(int vol)
{
  if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, vol);
    
    analogWrite(RPWMOutputRight, vol);
    analogWrite(LPWMOutputRight, 0);
}

void goDown_v2(int volL, int volR)
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

void goRight(int vol)
{
  if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, vol);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, vol);
    analogWrite(LPWMOutputRight, 0);
}

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

void goLeft(int vol)
{
  if (vol >= 255)
    vol = 255;    
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, vol);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, vol);
}

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

void goUpRight(int vol)
{
    if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputRight, vol);
    analogWrite(LPWMOutputRight, 0);
}

void goDownLeft(int vol)
{
    if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, vol);
}

void goUpLeft(int vol)
{
    if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, vol);
}

void goDownRight(int vol)
{
    if (vol >= 255)
    vol = 255;
    analogWrite(RPWMOutputLeft, vol);
    analogWrite(LPWMOutputLeft, 0);
}

void doStop()
{
    analogWrite(RPWMOutputLeft, 0);
    analogWrite(LPWMOutputLeft, 0);
    
    analogWrite(RPWMOutputRight, 0);
    analogWrite(LPWMOutputRight, 0);
}

///////////////////////////////////////////////////////////////// SQUARE ///////////////////////////////////////////////////////

void square_v2()
{
    Serial.print("Encoder Left = ");
    Serial.println(encoderLeft);
    Serial.print("Encoder Right = ");
    Serial.println(encoderRight);
    Serial.println("start left");

//    spray();
    while (1)
    {
      goLeft_v2(195, 125);   //155, 100
      if ((encoderLeft > (encLprev + encL * 2.5)) && (encoderRight > (encRprev + encR * 2.5)))
      {
        doStop();
        encoderLeft = 0;
        encoderRight = 0;
        encLprev = encoderLeft;
        encRprev = encoderRight;
        break ;
      }
    } 
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
    Serial.print("Encoder Left = ");
    Serial.println(encoderLeft);
    Serial.print("Encoder Right = ");
    Serial.println(encoderRight);
    Serial.println("start down");
    while (1)
    {
      goDown_v2(90, 140);
      if ((encoderLeft < (encLprev - encL * 0.5)) && (encoderRight > (encLprev + encR * 0.5)))
      {
        doStop();
        encoderLeft = 0;
        encoderRight = 0;
        encLprev = encoderLeft;
        encRprev = encoderRight;
        break ;
      }
    }
    Serial.print("Encoder Left = ");
    Serial.println(encoderLeft);
    Serial.print("Encoder Right = ");
    Serial.println(encoderRight);
    Serial.println("start right");
//    spray();
    while (1)
    {
      goRight_v2(120, 150); //100 : 150
      if ((encoderLeft < (encLprev - encL * 2.1)) && (encoderRight < (encRprev - encR * 2.1)))
      {
        doStop();
        encoderLeft = 0;
        encoderRight = 0;
        encLprev = encoderLeft;
        encRprev = encoderRight;
        break ;
      }
    }
     
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
    Serial.print("Encoder Left = ");
    Serial.println(encoderLeft);
    Serial.print("Encoder Right = ");
    Serial.println(encoderRight);
    Serial.println("start down");
    while (1)
    {
      goDown_v2(100, 140);
      if ((encoderLeft < (encLprev - encL * 0.5)) && (encoderRight > (encLprev + encR * 0.5)))
      {
        doStop();
        encoderLeft = 0;
        encoderRight = 0;
        encLprev = encoderLeft;
        encRprev = encoderRight;
        break ;
      }
    }
    Serial.print("Encoder Left = ");
    Serial.println(encoderLeft);
    Serial.print("Encoder Right = ");
    Serial.println(encoderRight);
    Serial.println("start left");
//    spray();
    while (1)
    {
      goLeft_v2(125, 165); // 15 left : 19 right
      if ((encoderLeft > (encLprev + encL * 1.9)) && (encoderRight > (encRprev + encR * 1.9)))
      {
        doStop();
        encoderLeft = 0;
        encoderRight = 0;
        encLprev = encoderLeft;
        encRprev = encoderRight;
        break ; 
      }
    }
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
    Serial.print("Encoder Left = ");
    Serial.println(encoderLeft);
    Serial.print("Encoder Right = ");
    Serial.println(encoderRight);
    Serial.println("end");
}

bool joystick(const int VRx, const int VRy, int encoderLeft, int encoderRight, int vol)
{
    readX = analogRead(VRx);
    readY = analogRead(VRy);
    Serial.print("X-axis: ");
    Serial.println(readX);
    Serial.print("Y-axis: ");
    Serial.println(readY);
    Serial.print(encoderLeft);
    Serial.print(" - ");
    Serial.println(encoderRight);
    Serial.print("\n\n");

    while (readX < 300 && readY > 600)
    {
      goDownRight(vol);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readY > 600 && readX < 300)
    {
      goUpRight(vol);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readY < 300 && readX < 300)
    {
      goDownRight(vol);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readY > 600 && readX > 600)
    {
      goUpLeft(vol);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readX < 300)
    {
//      goRight_v2(140, 200);
      goRight(vol);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readX > 700)
    {
//      goLeft_v2(150, 165);
      goLeft(vol);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readY < 300)
    {
//      goDown_v2(145, 200);
      goDown(vol);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
    while (readY > 700)
    {
//      goUp_v2(145, 200);
      goUp(vol);
      readX = analogRead(VRx);
      readY = analogRead(VRy);
    }
    doStop();
}
