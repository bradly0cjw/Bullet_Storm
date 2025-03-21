function generate()
{
   var _loc1_ = _root;
   _loc1_.id = _loc1_.id + 1;
   initObject = new Object();
   initObject._x = _parent.xp;
   initObject._y = _parent.yp;
   initObject.lty = 5;
   _loc1_.itemc.attachMovie("pdebris","debris" + _loc1_.id,_loc1_.id,initObject);
}
hp = _root.dif * 450;
gotoAndPlay(2);
