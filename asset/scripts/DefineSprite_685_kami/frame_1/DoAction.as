adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = random(201) + 50;
_Y = -26;
gone = 0;
dir = _root.plane._x - _X;
if(dir < 0)
{
   dspd = -1;
}
else
{
   dspd = 1;
}
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(gone == 0)
   {
      xp = _X;
      yp = _Y + fly._y;
   }
   if(_loc1_.plane._y < yp)
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793;
   }
   else
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793 + 180;
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
