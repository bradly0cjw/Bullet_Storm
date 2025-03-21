adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = -16;
_Y = 32;
gone = 0;
sht = random(3);
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(gone == 0)
   {
      xp = _X + fly._x;
      yp = _Y + fly._y;
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
      play();
   }
   else
   {
      stop();
   }
};
