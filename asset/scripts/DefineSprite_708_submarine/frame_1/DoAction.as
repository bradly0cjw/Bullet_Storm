adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
if(_rotation == 0)
{
   _Y = -144;
}
else
{
   _Y = -36;
}
gone = 0;
if(_rotation == 0)
{
   _root.id = _root.id + 1;
   io = new Object();
   io._x = _X;
   io._y = _Y + 96;
   _root.lv1.grn.attachMovie("subtank","en" + _root.id,_root.id,io);
}
else
{
   _root.id = _root.id + 1;
   io = new Object();
   io._x = _X - 96;
   io._y = _Y;
   _root.lv1.grn.attachMovie("subtank2","en" + _root.id,_root.id,io);
}
bsound = new Sound();
bsound.attachSound("eneshot");
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
   }
   if(_loc1_.plane._y < yp)
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793 - _rotation;
   }
   else
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793 + 180 - _rotation;
   }
   if(_loc1_.pause == 0 && _loc1_.scroll == 1 && gone == 0)
   {
      _Y = _Y + 0.8333333333333334;
      play();
   }
   else
   {
      stop();
   }
   if(_Y >= 372)
   {
      gotoAndStop(106);
   }
};
