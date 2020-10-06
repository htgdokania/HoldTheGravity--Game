int decide(){
  int pin=1;
  if(gForceZ>90)
    pin=5; //front
   else if(gForceX<-90)
    pin=6; //up
   else if(gForceX>90)
    pin=3; //down
   else if(gForceY>90)
    pin=4; //right
   else if(gForceY<-90)
    pin=2; //left
   else if(gForceZ<-90)
    pin=7; //back
    
  return pin;
}
