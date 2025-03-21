scale = Math.random() * 50 + 30;
_X = random(12) - 6;
_yscale = scale;
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
