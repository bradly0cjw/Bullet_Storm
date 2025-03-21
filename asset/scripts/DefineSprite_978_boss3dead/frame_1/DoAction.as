this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0)
   {
      if(_loc1_.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      if(_loc1_.scroll == 1 && _loc1_.lv1.advance == 1)
      {
         _Y = _Y + 1.3333333333333333;
      }
   }
   if(_Y >= 430)
   {
      this.removeMovieClip();
   }
};
