this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      play();
   }
   else
   {
      stop();
   }
};
gotoAndStop(random(10) + 2);
