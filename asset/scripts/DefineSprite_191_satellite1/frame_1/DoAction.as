adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = random(201) + 50;
_Y = -32;
gone = 0;
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y + fly._y;
      if(_root.pause == 0 && gone == 0)
      {
         play();
      }
      else
      {
         stop();
      }
   }
};
