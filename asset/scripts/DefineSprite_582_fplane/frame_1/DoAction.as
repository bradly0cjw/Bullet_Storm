adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = random(250) + 25;
_Y = -20;
aim = Math.random() * 96;
if(_X < _root.plane._x)
{
   dist = _root.plane._x - _X + aim;
}
else
{
   dist = _root.plane._x - _X - aim;
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
