adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_Y = -58;
gone = 0;
rota = 180;
_root.id = _root.id + 1;
io = new Object();
io._x = _X + 40;
io._y = _Y - 1;
_root.lv1.grn.attachMovie("subgtank","en" + _root.id,_root.id,io);
_root.id = _root.id + 1;
io = new Object();
io._x = _X - 32;
io._y = _Y + 34;
_root.lv1.grn.attachMovie("subgtank","en" + _root.id,_root.id,io);
_root.id = _root.id + 1;
io = new Object();
io._x = _X - 32;
io._y = _Y - 38;
_root.lv1.grn.attachMovie("subgtank","en" + _root.id,_root.id,io);
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
   if(_Y >= 405)
   {
      gotoAndStop(14);
   }
};
