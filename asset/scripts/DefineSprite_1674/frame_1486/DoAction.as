sc = 0;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   _loc1_.ctrl = 0;
   _loc1_.shoot = 0;
   _loc1_.bomb = 0;
   _quality = "BEST";
   if(_loc1_.pause == 0)
   {
      sc++;
      if(sc > 60)
      {
         _loc1_.gotoAndStop("lev6");
      }
   }
};
