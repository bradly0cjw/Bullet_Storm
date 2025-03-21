_Y = -23;
gone = 0;
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
