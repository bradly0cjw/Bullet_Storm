adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = -5;
_Y = random(200) + 50;
gone = 0;
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X + fly._x;
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
