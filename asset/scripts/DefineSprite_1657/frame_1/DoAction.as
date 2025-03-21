if(_root.levelno == 6)
{
   gotoAndStop(5);
}
else
{
   stop();
   this.onEnterFrame = function()
   {
      var _loc1_ = _root;
      if(_loc1_.pause == 0 && _loc1_.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      if(_loc1_.lv1.bossdead == 1)
      {
         gotoAndStop(2);
      }
      if(_Y > 350)
      {
         gotoAndStop(3);
      }
      if(_Y >= -200)
      {
         _loc1_.level5back.bground.gotoAndStop(2);
      }
   };
}
