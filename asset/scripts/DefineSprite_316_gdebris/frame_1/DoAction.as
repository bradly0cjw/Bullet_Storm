function generate()
{
   var _loc1_ = _root;
   _loc1_.id = _loc1_.id + 1;
   initObject = new Object();
   initObject._x = _loc1_.plane._x;
   initObject._y = _loc1_.plane._y;
   initObject.lty = _loc1_.plane.lty;
   _loc1_.itemc.attachMovie("pdebris","debris" + _loc1_.id,_loc1_.id,initObject);
}
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
gotoAndStop(2);
