adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_Y = 24;
gone = 0;
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y + fly._y;
   }
};
fly.fly.gotoAndStop(2);
fly._alpha = 0;
stop();
