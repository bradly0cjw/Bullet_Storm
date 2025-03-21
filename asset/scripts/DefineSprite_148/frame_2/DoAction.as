_parent.gone = 1;
_root.lv1.planeArray[_parent.adt] = null;
_root.lv1.upd();
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
_root.debris.attachMovie("medal","medal" + _root.id,_root.id,initObject);
_root.score += 300;
