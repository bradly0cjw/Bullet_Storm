sc = 6;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0 && _loc1_.lv1.bossdead == 0)
   {
      sc += 0.03333333333333333;
      if(sc >= 6)
      {
         sc = 0;
         _loc1_.id = _loc1_.id + 1;
         _loc1_.lv1.sky.attachMovie("fly3","en" + _loc1_.id,_loc1_.id);
         _loc1_.id = _loc1_.id + 1;
         _loc1_.lv1.sky.attachMovie("fly3","en" + _loc1_.id,_loc1_.id);
         _loc1_.id = _loc1_.id + 1;
         _loc1_.lv1.sky.attachMovie("fly3","en" + _loc1_.id,_loc1_.id);
      }
   }
};
