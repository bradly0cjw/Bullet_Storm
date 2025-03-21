_root.ctrl = 0;
_root.shoot = 0;
_root.bomb = 0;
_root.ictrl.nextFrame();
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _X - 10;
initObject._y = _Y - 10;
_root.itemc.attachMovie(_root.ictrl.ty,"itm" + _root.id,_root.id,initObject);
if(_root.gls > 0)
{
   lty = 2;
}
else if(_root.gps > 0)
{
   lty = 3;
}
else
{
   lty = 1;
}
_root.id = _root.id + 1;
_root.attachMovie("gdebris","generator" + _root.id,_root.id);
_root.id = _root.id + 1;
_root.attachMovie("gdebris","generator" + _root.id,_root.id);
_root.bbno = 0;
_root.gvc = 0;
_root.gls = 0;
_root.gps = 0;
_root.mnc = 0;
_root.mhm = 0;
