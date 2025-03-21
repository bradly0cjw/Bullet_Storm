this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      _parent.play();
   }
   else
   {
      _parent.stop();
   }
};
