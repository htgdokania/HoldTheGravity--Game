void game(){

  int pos;
  pos=decide(); // Call the Decide Function to update the current Orientation.
  if(score>0)
    spd=2000-score*15;// increase speed  as score increase
  
  if(millis()-tim>=spd) // check in every spd milli sec duration  
  {
    if(num==pos){
      score+=1;// update Score 
      // Play coin sound
      tone(11,NOTE_B5,100);
      delay(50);
      tone(11,NOTE_E6,850);
      delay(400);
      noTone(11);
    }
    else
    if(num!=0){  
      score-=1; //decrease score by 1
      negscore-=1; //decrese negscore/Remaining Lives
      // Play -ve score sound
      tone(11,NOTE_G4,35);delay(35);tone(11,NOTE_G5,35);delay(35);tone(11,NOTE_G6,35);delay(35);
      noTone(11);
      tone(11,NOTE_G4,35);delay(35);tone(11,NOTE_G5,35);delay(35);tone(11,NOTE_G6,35);delay(35);
      noTone(11);

    }
    
    num=random(2,8);    // Generate a random number between 2-7   each indicating one of the 6 faces of the Game
    int i;
    for (i=2;i<=7;i++){
      digitalWrite(i,0);
    }
    digitalWrite(num,1); // Turn ON the target face only for the player to move accordingly
    
    tim=millis();         //reset the timer
        
  }

  Display(num,score,negscore); //Update the lives, Score and Position on the oLED display 
 
}
