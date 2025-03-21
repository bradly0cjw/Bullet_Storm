this.onEnterFrame = function()
{
   var _loc1_ = _root;
   var _loc2_ = _parent;
   if(_loc1_.pause == 0)
   {
      _Y = _Y - _loc1_.bspd;
   }
   if(hitTest(_loc1_.b1) || hitTest(_loc1_.b2) || hitTest(_loc1_.b3))
   {
      _loc1_.score += 10;
      _loc2_.gotoAndStop(2);
   }
   else if(hitTest(_loc1_.plane.ha))
   {
      _loc1_.plane.dd = 1;
      _loc2_.gotoAndStop(2);
   }
   else if(hitTest(_loc1_.tborder) || hitTest(_loc1_.rborder) || hitTest(_loc1_.bborder) || hitTest(_loc1_.lborder))
   {
      _loc2_.gotoAndStop(2);
   }
};
