///////////////////////////////////////////////////////////////// SQUARE ///////////////////////////////////////////////////////

void square_v2()
{
    Serial.print("Encoder Left = ");
    Serial.println(leftMotorEnc.read());
    Serial.print("Encoder Right = ");
    Serial.println(rightMotorEnc.read());
    Serial.println("start left");

//    spray();
    while (1)
    {
      goLeft_v2(195, 135);   //155, 100
      Serial.print(leftMotorEnc.read());
      Serial.print(" - ");
      Serial.println(rightMotorEnc.read());
      if ((encoderLeft > (encLprev + encL * 1.5)) && (encoderRight > (encRprev + encR * 1)))
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
      goDown_v2(120, 130);
      Serial.println(encoderLeft);
      Serial.println(encoderRight);
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
      goRight_v2(160, 190); //100 : 150
      Serial.println(encoderLeft);
      Serial.println(encoderRight);
      if ((encoderLeft < (encLprev - encL * 1.1)) && (encoderRight < (encRprev - encR * 1)))
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
      goDown_v2(100, 160);
      Serial.println(encoderLeft);
      Serial.println(encoderRight);
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
      goLeft_v2(185, 155); // 15 left : 19 right
      Serial.println(encoderLeft);
      Serial.println(encoderRight);
      if ((encoderLeft > (encLprev + encL * 1)) && (encoderRight > (encRprev + encR * 1)))
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

// move left until both encoder values meet more than pos value.
void moveLeft(int volL, int volR, long pos)
{
  while (1)
  {
    goLeft_v2(volL, volR);   //155, 100
//    Serial.print(leftMotorEnc.read());
//    Serial.print(" - ");
//    Serial.println(RightMotorEnc);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft < -pos) && (encoderRight < -pos))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

// move down until both encoder values meet more than pos value.
void moveDown(int volL, int volR, long posH)
{
  while (1)
  {
    goDown_v2(volL, volR);
//    Serial.print(leftMotorEnc.read());
//    Serial.print(" - ");
//    Serial.println(encoderRight);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft > posH) && (encoderRight < -posH))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

// move right until both encoder values meet more than pos value.
void moveRight(int volL, int volR, long pos)
{
  while (1)
  {
    goRight_v2(volL, volR); //100 : 150
//    Serial.print(leftMotorEnc.read());
//    Serial.print(" - ");
//    Serial.println(encoderRight);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft > pos) && (encoderRight > pos))
    {
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

////////////////////////////////////////////////////////////// SQUARE v4 /////////////////////////////////////////////////////////

/*
  Make path for painting 3ft by 2ft square.
  1. Left
  2. Down
  3. Right
  4. Down
  5. Left
  6. Down
  7. Right
  8. 
*/
void square_v4(long pos, long posH)
{   
//  Serial.print("Encoder Left = ");
//  Serial.println(leftMotorEnc.read());
//  Serial.print("Encoder Right = ");
//  Serial.println(rightMotorEnc.read());
//  Serial.print("1 - ");
//  Serial.println("start left");

  spray();
  moveLeft(230, 130, pos * 1.3);
  moveLeft(210, 130, pos * 1);

    while (1) {
      if (stopSpraying()) {
        break ;
      }
    }
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("2 - ");
//  Serial.println("start down");
      
  moveDown(200, 140, posH * 0.35);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("3 - ");
//  Serial.println("start right");  
  
  spray();
  moveRight(140, 200, pos * 1);
  moveRight(150, 180, pos * 1);

    while (1) {
      if (stopSpraying()) {
        break ;
      }
    }

    
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("4 - ");
//  Serial.println("start down");

  moveDown(140, 230, posH * 0.85);

  spray();
  moveLeft(180, 170, pos * 1);
  moveLeft(160, 170, pos * 1);

    while (1) {
      if (stopSpraying()) {
        break ;
      }
    }
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("2 - ");
//  Serial.println("start down");
      
  moveDown(200, 140, posH * 0.7);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("3 - ");
//  Serial.println("start right");  
  
  spray();
  moveRight(140, 180, pos * 1);
  moveRight(150, 140, pos * 0.6);

    while (1) {
      if (stopSpraying()) {
        break ;
      }
    }

    
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("4 - ");
//  Serial.println("start down");

  moveDown(140, 230, posH * 0.85);
 
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("5 - ");
//  Serial.println("start left");  
  
  spray();
  moveLeft(160, 170, pos * 1);
  moveLeft(150, 190, pos * 0.6);

    while (1) {
      if (stopSpraying()) {
        break ;
      }
    }

//  moveDown(200, 140, posH * 0.45);
//
//  spray();
//  moveRight(140, 200, pos * 1);
//  moveRight(150, 180, pos * 1);
//
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
    
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("6 - ");
//  Serial.println("start down");

//  moveDown(200, 160, posH * 1.8);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("7 - ");
//  Serial.println("start right");  
  
//  spray();
//  moveRight(200, 200, pos * 0.8);
//  moveRight(200, 160, pos * 0.6);
//  
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("8 - ");
//  Serial.println("start down");
//
//  moveDown(160, 200, posH * 1);
//  
////  Serial.print("Encoder Left = ");
////  Serial.println(encoderLeft);
////  Serial.print("Encoder Right = ");
////  Serial.println(encoderRight);
////  Serial.print("9 - ");
////  Serial.println("start left");  
//  
//  moveLeft(180, 180, encL * 2);
//  moveLeft(160, 200, encL * 2);
  
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }

//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("10 - ");
//  Serial.println("end");
   doStop();
}


////////////////////////////////////////////////////////////// SQUARE v5 /////////////////////////////////////////////////////////

void square_v5(long pos, long posH)
{   
//  Serial.print("Encoder Left = ");
//  Serial.println(leftMotorEnc.read());
//  Serial.print("Encoder Right = ");
//  Serial.println(rightMotorEnc.read());
//  Serial.print("1 - ");
//  Serial.println("start left");

//    spray();
  moveLeft(230, 130, pos * 1);
  moveLeft(210, 130, pos * 1);

//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("2 - ");
//  Serial.println("start down");
      
  moveDown(200, 140, posH * 0.5);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("3 - ");
//  Serial.println("start right");  
  
  moveRight(140, 200, pos * 0.9);
  moveRight(150, 180, pos * 0.9);

//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("4 - ");
//  Serial.println("start down");

  moveDown(140, 200, posH * 0.5);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("5 - ");
//  Serial.println("start left");  

  moveLeft(180, 150, pos * 1);
  moveLeft(170, 180, pos * 1);

//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("6 - ");
//  Serial.println("start down");

  moveDown(200, 160, posH * 0.8);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("7 - ");
//  Serial.println("start right");  

  moveRight(200, 200, pos * 0.7);
  moveRight(200, 160, pos * 0.7);
  
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("8 - ");
//  Serial.println("start down");

  moveDown(160, 200, posH * 0.5);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("9 - ");
//  Serial.println("start left");  
  
  moveLeft(180, 180, encL * 2);
  moveLeft(160, 200, encL * 1.9);
  
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }

//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("10 - ");
//  Serial.println("end");
   doStop();
}
