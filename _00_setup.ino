void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Wire.begin();
  setupMPU();
  setupOled();

  //initialize all 6 sides LED connected to pin 2-7 
  int i;
  for (i=2;i<=7;i++){
    pinMode(i,OUTPUT);
  }
  
  //start the timer
  tim=millis();
}
