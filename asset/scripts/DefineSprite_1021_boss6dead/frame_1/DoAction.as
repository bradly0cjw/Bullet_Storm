this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0 && _loc1_.scroll == 1)
   {
      if(_loc1_.lv1.lv6warp == 0)
      {
         _Y = _Y + 0.8333333333333334;
      }
      else
      {
         _Y = _Y + 3;
      }
   }
   if(_Y >= 430)
   {
      this.removeMovieClip();
   }
};
