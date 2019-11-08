void moveLeft(int volL, int volR, long pos, long *prevL, long *prevR)
{
  while (1)
  {
    goLeft_v2(volL, volR);   //155, 100
    Serial.print(encoderLeft);
    Serial.print(" - ");
    Serial.println(encoderRight);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft < -pos) && (encoderRight < -pos))
    {
      *prevL = encoderLeft >= 0L ? (+ encoderLeft) : (- encoderLeft);
      *prevR = encoderRight >= 0L ? (+ encoderRight) : (- encoderRight);
      doStop();
      Serial.println("done");
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      Serial.println("are we good?");
      break ;
    }
  }
  delay(10);
}

void moveDown(int volL, int volR, long posH, long *prevL, long *prevR)
{
  while (1)
  {
    goDown_v2(volL, volR);
    Serial.print(encoderLeft);
    Serial.print(" - ");
    Serial.println(encoderRight);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft > posH) && (encoderRight < -posH))
    {
      *prevL = encoderLeft >= 0L ? (+ encoderLeft) : (- encoderLeft);
      *prevR = encoderRight >= 0L ? (+ encoderRight) : (- encoderRight);
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

void moveRight(int volL, int volR, long pos, long *prevL, long *prevR)
{
  while (1)
  {
    goRight_v2(volL, volR); //100 : 150
    Serial.print(encoderLeft);
    Serial.print(" - ");
    Serial.println(encoderRight);
    encoderLeft = leftMotorEnc.read();
    encoderRight = rightMotorEnc.read();
    if ((encoderLeft > pos) && (encoderRight > pos))
    {
      *prevL = encoderLeft >= 0L ? (+ encoderLeft) : (- encoderLeft);
      *prevR = encoderRight >= 0L ? (+ encoderRight) : (- encoderRight);
      doStop();
      leftMotorEnc.write(0);
      rightMotorEnc.write(0);
      break ;
    }
  }
  delay(10);
}

void square_v4_track(long pos, long posH, long *prevL, long *prevR)
{   
//  Serial.print("Encoder Left = ");
//  Serial.println(leftMotorEnc.read());
//  Serial.print("Encoder Right = ");
//  Serial.println(rightMotorEnc.read());
//  Serial.print("1 - ");
//  Serial.println("start left");

//    spray();
  moveLeft(230, 130, pos * 1.3, *prevL, *prevR);
  moveLeft(210, 130, pos * 1, *prevL, *prevR);

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
      
  moveDown(200, 140, posH * 0.9, *prevL, *prevR);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("3 - ");
//  Serial.println("start right");  
  
  moveRight(140, 200, pos * 1, *prevL, *prevR);
  moveRight(150, 180, pos * 1, *prevL, *prevR);

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

  moveDown(140, 200, posH * 1.7, *prevL, *prevR);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("5 - ");
//  Serial.println("start left");  

  moveLeft(180, 150, pos * 1, *prevL, *prevR);
  moveLeft(170, 180, pos * 0.8, *prevL, *prevR);

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

  moveDown(200, 160, posH * 1.8, *prevL, *prevR);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("7 - ");
//  Serial.println("start right");  

  moveRight(200, 200, pos * 0.8, *prevL, *prevR);
  moveRight(200, 160, pos * 0.6, *prevL, *prevR);
  
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

  moveDown(160, 200, posH * 1, *prevL, *prevR);
  
//  Serial.print("Encoder Left = ");
//  Serial.println(encoderLeft);
//  Serial.print("Encoder Right = ");
//  Serial.println(encoderRight);
//  Serial.print("9 - ");
//  Serial.println("start left");  
  
  moveLeft(180, 180, encL * 2, *prevL, *prevR);
  moveLeft(160, 200, encL * 2, *prevL, *prevR);
  
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


void square_v3(long pos, long posH)
{   
  Serial.print("Encoder Left = ");
  Serial.println(leftMotorEnc.read());
  Serial.print("Encoder Right = ");
  Serial.println(rightMotorEnc.read());
  Serial.print("1 - ");
  Serial.println("start left");

//    spray();
  moveLeft(165, 110, pos * 1.1);
  moveLeft(170, 130, pos * 1.1);

//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
  Serial.print("Encoder Left = ");
  Serial.println(encoderLeft);
  Serial.print("Encoder Right = ");
  Serial.println(encoderRight);
  Serial.print("2 - ");
  Serial.println("start down");
      
  moveDown(135, 130, posH);
  
  Serial.print("Encoder Left = ");
  Serial.println(encoderLeft);
  Serial.print("Encoder Right = ");
  Serial.println(encoderRight);
  Serial.print("3 - ");
  Serial.println("start right");  
  
  moveRight(100, 165, pos * 1.05);
  moveRight(105, 145, pos * 1.05);

//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
  Serial.print("Encoder Left = ");
  Serial.println(encoderLeft);
  Serial.print("Encoder Right = ");
  Serial.println(encoderRight);
  Serial.print("4 - ");
  Serial.println("start down");

  moveDown(100, 165, posH);
  
  Serial.print("Encoder Left = ");
  Serial.println(encoderLeft);
  Serial.print("Encoder Right = ");
  Serial.println(encoderRight);
  Serial.print("5 - ");
  Serial.println("start left");  

  moveLeft(165, 155, pos * 0.95);
  moveLeft(125, 155, pos * 0.95);

//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
  Serial.print("Encoder Left = ");
  Serial.println(encoderLeft);
  Serial.print("Encoder Right = ");
  Serial.println(encoderRight);
  Serial.print("6 - ");
  Serial.println("start down");

  moveDown(95, 170, posH);
  
  Serial.print("Encoder Left = ");
  Serial.println(encoderLeft);
  Serial.print("Encoder Right = ");
  Serial.println(encoderRight);
  Serial.print("7 - ");
  Serial.println("start right");  

  moveRight(110, 155, pos * 0.85);
  moveRight(145, 125, pos * 0.85);
  
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }
  Serial.print("Encoder Left = ");
  Serial.println(encoderLeft);
  Serial.print("Encoder Right = ");
  Serial.println(encoderRight);
  Serial.print("8 - ");
  Serial.println("start down");

  moveDown(90, 170, encL * 0.5);
  
  Serial.print("Encoder Left = ");
  Serial.println(encoderLeft);
  Serial.print("Encoder Right = ");
  Serial.println(encoderRight);
  Serial.print("9 - ");
  Serial.println("start left");  
  
  moveLeft(160, 155, encL *  1.9);
  moveLeft(95, 150, encL *  1.9);
  
//    while (1) {
//      if (stopSpraying()) {
//        break ;
//      }
//    }

  Serial.print("Encoder Left = ");
  Serial.println(encoderLeft);
  Serial.print("Encoder Right = ");
  Serial.println(encoderRight);
  Serial.print("10 - ");
  Serial.println("end");
}
