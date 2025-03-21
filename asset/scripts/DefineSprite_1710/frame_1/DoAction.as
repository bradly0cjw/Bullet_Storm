sc = 0;
delay = random(7) + 1;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0)
   {
      sc++;
      if(sc >= delay)
      {
         sc = 0;
         delay = random(9) + 1;
         _loc1_.id = _loc1_.id + 1;
         _loc1_.lv1.air.attachMovie("crystal","en" + _loc1_.id,_loc1_.id);
      }
   }
};
gotoAndStop(2);
