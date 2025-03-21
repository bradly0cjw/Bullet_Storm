adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 316;
gone = 0;
rota = 180;
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
