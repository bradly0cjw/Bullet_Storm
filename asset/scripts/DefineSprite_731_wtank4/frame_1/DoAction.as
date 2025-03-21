adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_Y = -14;
gone = 0;
rota = 180;
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
   }
   if(_root.pause == 0 && gone == 0)
   {
      if(_root.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      play();
   }
   else
   {
      stop();
   }
   if(_Y >= 364)
   {
      gotoAndStop(169);
   }
};
