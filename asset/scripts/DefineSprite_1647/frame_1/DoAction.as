if(_root.levelno == 6)
{
   gotoAndStop(2);
}
else
{
   stop();
   this.onEnterFrame = function()
   {
      if(_root.pause == 0 && _root.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      if(_Y > 350)
      {
         gotoAndStop(2);
      }
   };
}
