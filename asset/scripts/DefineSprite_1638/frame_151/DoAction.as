if(bossdead == 0)
{
   if(_root.back._y < -720)
   {
      _root.scroll = 1;
   }
   else
   {
      _root.back._y = -720;
      _root.scroll = 0;
   }
   gotoAndPlay(150);
}
else
{
   _root.scroll = 1;
   if(_root.back._y <= -720)
   {
      gotoAndPlay(150);
   }
   else
   {
      nextFrame();
   }
}
