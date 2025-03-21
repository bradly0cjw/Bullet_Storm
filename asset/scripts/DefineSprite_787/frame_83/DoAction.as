_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent._x;
initObject._y = _parent._y;
_root.debris.attachMovie("boss5dead","debris" + _root.id,_root.id,initObject);
