_parent.gone = 1;
if(_parent.removed == 0)
{
   _root.lv1.planeArray[_parent.adt] = null;
   _root.lv1.upd();
   _parent.removed = 1;
}
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
_root.debris.attachMovie("tankdead","debris" + _root.id,_root.id,initObject);
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
_root.debris.attachMovie("medal","medal" + _root.id,_root.id,initObject);
fly.gotoAndStop(1);
_root.score += Math.round(_root.dif * 320 / 10) * 10;
