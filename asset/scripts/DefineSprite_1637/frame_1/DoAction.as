this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      count += 0.022222222222222223;
   }
   if(count >= _parent.d)
   {
      count = 0;
      _parent.nextFrame();
   }
};
