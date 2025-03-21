function position()
{
   _root.plane._x += xpl;
   _root.plane._y += ypl;
}
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.back._y >= 0 && _loc1_.levelno !== 6)
   {
      _loc1_.back._y = 0;
      _loc1_.scroll = 0;
   }
   else
   {
      _loc1_.scroll = 1;
   }
   _loc1_.ctrl = 0;
   _loc1_.shoot = 0;
   _loc1_.bomb = 0;
   _loc1_.pau = 0;
   if(_loc1_.levelno !== 5)
   {
      _quality = "BEST";
   }
   else
   {
      _quality = "LOW";
   }
};
