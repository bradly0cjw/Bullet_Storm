this.onEnterFrame = function()
{
   if(_root.pause == 0 && spin == 1)
   {
      play();
   }
   else
   {
      stop();
   }
};
