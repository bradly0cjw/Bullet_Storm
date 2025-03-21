adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 80;
_Y = -60;
gone = 0;
col = 1;
bsound = new Sound();
bsound.attachSound("eneshot");
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y + fly._y;
   }
   shad._x = 6;
   shad._y = fly._y + 10;
   if(_root.pause == 0 && gone == 0)
   {
      play();
      if(_root.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
   }
   else
   {
      stop();
   }
};
