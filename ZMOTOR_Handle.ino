//------------------------------------------------Functions associated with handling the ZMotor

void main_ZMotor(int click_status, int spin_direction)
{
    while (click_status == CLICKED) {
    spinZMotor(Clockwise);
    int released = digitalRead(SW);
    if (released) {
      spinZMotor(Stop);
      break;
    }
}
void spinZMotor(int turnDirection) {
   //turns in endless circle
   if (turnDirection == Clockwise) {
       analogWrite(ZMOTOR_A_Output, SRPAY_MAX_VOLTAGE);
       analogWrite(ZMOTOR_B_Output, 0);
   } else if (turnDirection == CounterClockwise) {
       analogWrite(ZMOTOR_A_Output, 0);
       analogWrite(ZMOTOR_B_Output, SRPAY_MAX_VOLTAGE);
   } else if (turnDirection == Stop) {
       analogWrite(ZMOTOR_A_Output, 0);
       analogWrite(ZMOTOR_B_Output, 0);
   }
}

void spray() {
//    EEPROM.write(sprayStatusCacheAddr, 1);
   analogWrite(ZMOTOR_A_Output, 0);
   analogWrite(ZMOTOR_B_Output, SRPAY_MAX_VOLTAGE);
   delay(spraySwitchDistance);
   analogWrite(ZMOTOR_A_Output, 0);
   analogWrite(ZMOTOR_B_Output, 0);
}

int stopSpraying() {
//    EEPROM.write(sprayStatusCacheAddr, 0);
   analogWrite(ZMOTOR_A_Output, SRPAY_MAX_VOLTAGE);
   analogWrite(ZMOTOR_B_Output, 0);
   //less power needed to turn off zMotor when
   delay(spraySwitchDistance * (zMotorMode == HandleOn ? 0.8 : 1));
   analogWrite(ZMOTOR_A_Output, 0);
   analogWrite(ZMOTOR_B_Output, 0);
   return (1);
}
