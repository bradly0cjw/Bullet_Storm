adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = random(201) + 50;
_Y = -17;
fly.leave = 0;
gone = 0;
sht = random(3);
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X + fly._x;
      yp = _Y + fly._y;
   }
   if(_root.pause == 0 && gone == 0)
   {
      sc++;
      play();
   }
   else
   {
      stop();
   }
};
