this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0 && _loc1_.scroll == 1)
   {
      _Y = _Y + 1.6666666666666667;
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
stop();
