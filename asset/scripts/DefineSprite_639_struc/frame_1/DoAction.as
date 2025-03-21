adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
if(_rotation == 0)
{
   _Y = -12;
}
else
{
   _Y = -39;
}
gone = 0;
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
   }
   if(_root.pause == 0 && _root.scroll == 1)
   {
      _Y = _Y + 0.8333333333333334;
   }
   if(_Y >= 389)
   {
      gotoAndStop(2);
   }
};
stop();
