_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
initObject._rotation = _parent._rotation;
_root.debris.attachMovie("strucexp","debris" + _root.id,_root.id,initObject);
_root.score += Math.round(_root.dif * 560 / 10) * 10;
_parent.gone = 1;
_parent.gotoAndStop(2);
