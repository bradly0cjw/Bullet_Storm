this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      count += 0.027777777777777776;
   }
   if(count >= _parent.d)
   {
      count = 0;
      _parent.nextFrame();
   }
};
