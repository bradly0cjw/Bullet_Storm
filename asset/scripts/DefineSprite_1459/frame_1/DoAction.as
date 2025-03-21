this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0)
   {
      if(Key.isDown(90) && _loc1_.shoot == 1 && _loc1_.gps > 0)
      {
         _rotation = _rotation + 5;
         gotoAndStop(_loc1_.gps + 1);
      }
      else
      {
         gotoAndStop(1);
      }
   }
};
