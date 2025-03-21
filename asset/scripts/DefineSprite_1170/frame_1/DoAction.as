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
_X = Math.random() * 300 - 180;
_Y = 666;
colour = random(4);
gotoAndStop(random(15) + 2);
