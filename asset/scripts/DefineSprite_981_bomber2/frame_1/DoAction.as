adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 160;
_Y = -27;
gone = 0;
bsound = new Sound();
bsound.attachSound("eneshot");
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
