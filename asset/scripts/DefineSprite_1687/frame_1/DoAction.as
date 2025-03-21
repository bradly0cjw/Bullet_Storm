sc = 0;
delay = random(12) + 1;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0)
   {
      sc++;
      if(sc >= delay)
      {
         sc = 0;
         delay = random(12) + 1;
         _loc1_.id = _loc1_.id + 1;
         _loc1_.lv1.air.attachMovie("emerald","en" + _loc1_.id,_loc1_.id);
      }
   }
};
gotoAndStop(2);
