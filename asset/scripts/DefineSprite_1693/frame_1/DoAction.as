_root.plane._y = 250;
sc = 0;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0)
   {
      sc++;
      if(sc > 30)
      {
         _loc1_.lv1.str = 1;
         _loc1_.ctrl = 1;
         _loc1_.shoot = 1;
         _loc1_.bomb = 1;
         gotoAndStop(2);
      }
   }
};
stop();
