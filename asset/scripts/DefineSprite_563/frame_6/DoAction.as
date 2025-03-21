_parent.gone = 1;
_root.lv1.planeArray[_parent.adt] = null;
_root.lv1.upd();
if(_root.levelno == 8)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = _parent.xp;
   initObject._y = _parent.yp;
   _root.debris.attachMovie("medal","tankmedal" + _root.id,_root.id + 65536,initObject);
}
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
_root.debris.attachMovie("tankdead","debris" + _root.id,_root.id,initObject);
fly.gotoAndStop(1);
_root.score += Math.round(_root.dif * 240 / 10) * 10;
