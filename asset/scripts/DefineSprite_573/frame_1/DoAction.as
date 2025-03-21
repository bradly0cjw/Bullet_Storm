function generate()
{
   var _loc1_ = _root;
   var _loc2_ = _parent;
   _loc1_.id = _loc1_.id + 1;
   initObject = new Object();
   initObject._x = _loc2_.xp;
   initObject._y = _loc2_.yp;
   if(_loc2_.col == 0)
   {
      initObject.lty = 10;
   }
   else
   {
      initObject.lty = 8;
   }
   _loc1_.itemc.attachMovie("pdebris","debris" + _loc1_.id,_loc1_.id,initObject);
}
hp = _root.dif * 1200;
gotoAndPlay(2);
