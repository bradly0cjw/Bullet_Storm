adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 68;
_Y = -62;
gone = 0;
bsound = new Sound();
bsound.attachSound("eneshot");
_root.id = _root.id + 1;
io = new Object();
io._x = _X - 40;
io._y = _Y + 25;
_root.lv1.grn.attachMovie("submtank","en" + _root.id,_root.id,io);
_root.id = _root.id + 1;
io = new Object();
io._x = _X + 40;
io._y = _Y + 25;
_root.lv1.grn.attachMovie("submtank","en" + _root.id,_root.id,io);
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
   }
   if(_root.pause == 0 && _root.scroll == 1 && gone == 0)
   {
      _Y = _Y + 0.8333333333333334;
      play();
   }
   else
   {
      stop();
   }
   if(_Y >= 384)
   {
      gotoAndStop(137);
   }
};
