this.onEnterFrame = function()
{
   if(_root.gls > 0)
   {
      gotoAndStop(2);
   }
   else if(_root.gps > 0)
   {
      gotoAndStop(3);
   }
   else
   {
      gotoAndStop(1);
   }
};
