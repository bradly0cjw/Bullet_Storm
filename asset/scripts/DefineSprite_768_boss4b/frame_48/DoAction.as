if(sc < 120)
{
   gotoAndPlay(47);
}
else
{
   sc = 0;
   if(_root.plane._y < yp)
   {
      rt1 = Math.atan((xp - 16 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793;
   }
   else
   {
      rt1 = Math.atan((xp - 16 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793 + 180;
   }
   if(_root.plane._y < yp)
   {
      rt2 = Math.atan((xp + 16 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793;
   }
   else
   {
      rt2 = Math.atan((xp + 16 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793 + 180;
   }
   gotoAndPlay(4);
}
