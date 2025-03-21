stop();
this.onEnterFrame = function()
{
   if(_root.pause == 1)
   {
      play();
   }
   else
   {
      gotoAndStop(1);
   }
};
