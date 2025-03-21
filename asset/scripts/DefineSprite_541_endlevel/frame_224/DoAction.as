if(_root.levelno !== 5)
{
   if(_root.back._y >= 0 && sc > 120)
   {
      count3.start(0,999);
      gotoAndPlay(225);
   }
   else
   {
      gotoAndPlay(223);
   }
}
else if(_root.back._y >= 0 && sc > 90)
{
   count3.start(0,999);
   gotoAndPlay(225);
}
else
{
   gotoAndPlay(223);
}
