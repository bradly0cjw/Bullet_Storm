adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 260;
_Y = -35;
gone = 0;
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y + fly._y;
      if(_root.pause == 0)
      {
         _X = _X - 0.5;
         _Y = _Y + 1;
         play();
      }
      else
      {
         stop();
      }
   }
   if(_Y >= 385)
   {
      gotoAndStop(49);
   }
};
