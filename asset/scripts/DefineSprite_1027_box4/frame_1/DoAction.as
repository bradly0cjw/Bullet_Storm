adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_Y = -14;
gone = 0;
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
      if(_Y >= 364)
      {
         gone = 1;
         gotoAndStop(12);
      }
   }
   if(_root.pause == 0 && _root.scroll == 1)
   {
      _Y = _Y + 0.8333333333333334;
   }
};
