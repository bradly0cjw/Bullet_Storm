_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
_root.debris.attachMovie("supplyd","debris" + _root.id,_root.id,initObject);
_root.score += Math.round(_root.dif * 1200 / 10) * 10;
_parent.gone = 1;
_parent.gotoAndStop(2);
