adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_Y = 368;
gone = 0;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
   }
   if(_loc1_.plane._y < yp)
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793 - _rotation;
   }
   else
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793 + 180 - _rotation;
   }
   if(_loc1_.pause == 0 && gone == 0)
   {
      _Y = _Y - 1.6666666666666667;
      play();
   }
   else
   {
      stop();
   }
   if(_Y <= -18)
   {
      gotoAndStop(167);
   }
};
