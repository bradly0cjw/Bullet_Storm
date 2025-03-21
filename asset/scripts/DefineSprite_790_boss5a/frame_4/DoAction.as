if(_Y < 120)
{
   if(_root.scroll == 1 && _root.pause == 0)
   {
      _Y = _Y + 0.8333333333333334;
   }
   if(_root.pause == 0)
   {
      gotoAndPlay(2);
   }
   else
   {
      gotoAndPlay(3);
   }
}
else
{
   _Y = 120;
   takeoff = 1;
   gotoAndPlay(5);
}
