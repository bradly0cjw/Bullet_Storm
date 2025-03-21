adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_Y = -22;
gone = 0;
rota = 180;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
   }
   if(_loc1_.pause == 0 && _loc1_.scroll == 1 && gone == 0)
   {
      if(_loc1_.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      play();
   }
   else
   {
      stop();
   }
   if(_Y >= 372)
   {
      gotoAndStop(169);
   }
};
