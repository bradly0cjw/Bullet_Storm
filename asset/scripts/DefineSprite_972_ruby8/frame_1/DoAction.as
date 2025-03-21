adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 150;
_Y = 175;
gone = 0;
sc = 0;
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X + fly._x + fly.fly.fly.fly._x;
      yp = _Y + fly._x;
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
