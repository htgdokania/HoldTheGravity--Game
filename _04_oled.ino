void setupOled(){
    // assign default color value
  if (u8g.getMode() == U8G_MODE_R3G3B2)
  {
    u8g.setColorIndex(255);     // white
  }
  else if (u8g.getMode() == U8G_MODE_GRAY2BIT)
  {
    u8g.setColorIndex(3);         // max intensity
  }
  else if (u8g.getMode() == U8G_MODE_BW)
  {
    u8g.setColorIndex(1);         // pixel on
  }
  else if (u8g.getMode() == U8G_MODE_HICOLOR)
  {
    u8g.setHiColorByRGB(255, 255, 255);
  }
  


}
void Display(int pin,int score,int negscore)
{
  u8g.firstPage();
  do
  {
    u8g.setFont(u8g_font_fub11);
    u8g.setFontRefHeightExtendedText();
    u8g.setDefaultForegroundColor();
    u8g.setFontPosTop();
    u8g.drawStr(3,0, "lives");
    u8g.setPrintPos(50,0);
    u8g.print(negscore);
    u8g.drawStr(3,20, "Position");
    u8g.setPrintPos(70, 20);
    if(pin>=2)
      u8g.print(pos[pin-2]);  
    u8g.drawStr(3, 40, "score");
    u8g.setPrintPos(60, 40);
    u8g.print(score);
  }
  while (u8g.nextPage());
}

void DisplayWin()
{
  u8g.firstPage();
  do
  {
    u8g.setFont(u8g_font_fub11);
    u8g.setFontRefHeightExtendedText();
    u8g.setDefaultForegroundColor();
    u8g.setFontPosTop();
    u8g.drawStr(10, 30, "YOU WIN!!");       //<---------------------
   }
  while (u8g.nextPage());
}

void DisplayGameOver()

{
  u8g.firstPage();
  do
  {
    u8g.setFont(u8g_font_fub11);
    u8g.setFontRefHeightExtendedText();
    u8g.setDefaultForegroundColor();
    u8g.setFontPosTop();
    u8g.drawStr(10, 30, "GAME OVER!!");   //<-----------------------
   }
  while (u8g.nextPage());
}
