adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
if(_X < _root.plane._x)
{
   dist = _root.plane._x - _X + 48;
}
else
{
   dist = _root.plane._x - _X - 48;
}
gone = 0;
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y + fly._y;
   }
   if(_root.pause == 0 && gone == 0)
   {
      play();
   }
   else
   {
      stop();
   }
};
