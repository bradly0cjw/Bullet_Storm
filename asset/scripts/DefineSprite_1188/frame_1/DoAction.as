this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(cm == 1)
   {
      gotoAndStop(Math.floor(_loc1_.imusic1.position / _loc1_.imusic1.duration * 215) + 2115);
   }
   else
   {
      gotoAndStop(Math.floor(_loc1_.imusic2.position / _loc1_.imusic2.duration * 2114) + 1);
   }
};
