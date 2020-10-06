#include "pitches.h" 

#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send AC
void Display();

#include <Wire.h>
long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;

int score=0,negscore=5,num=0,spd=2000;
char *pos[] = {"LEFT","DOWN","RIGHT","FRONT","UP","BACK"};
unsigned long tim=0;
