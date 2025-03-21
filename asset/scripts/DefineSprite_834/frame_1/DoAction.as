this.onEnterFrame = function()
{
   var _loc1_ = _parent;
   if(_root.pause == 0 && _loc1_.gone == 0)
   {
      _loc1_.play();
   }
   else
   {
      _loc1_.stop();
   }
};
