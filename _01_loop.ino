
void loop() {
  
  setupMPU();
  //next 4 lines just to refresh the sensor
  Wire.beginTransmission(0b1101000); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(0x6B); //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b00000000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();  
  recordAccelRegisters();  
  game();

  //GAME OVER IF 5 MISTAKES ARE MADE
  if(negscore<=0){
    DisplayGameOver();
    
    int i;
    for (i=2;i<=7;i++)
      digitalWrite(i,0);
    digitalWrite(2,1);
    digitalWrite(4,1);
    
    while(1){
        tone(11,NOTE_B5); // Game Over constant beep sound
      }
  }
  
  if(score>=50){
    DisplayWin();
    int v =0;
    while(1){
      // Play +ve Score sound
      tone(11,NOTE_B5,100);
      delay(100);
      tone(11,NOTE_E6,100);
      delay(100);
      noTone(11);

      // Blink all the LEDS indicating "YOU WIN!!"
      if (v==1)
        v=0;
      else
        v=1;
      int i;
      for (i=2;i<=7;i++){
        digitalWrite(i,v);
      delay(10);
    }
    }
  }
}
