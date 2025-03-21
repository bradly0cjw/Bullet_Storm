_root.id = _root.id + 1;
initObject = new Object();
initObject._y = -16;
attachMovie("fly","enemy" + _root.id,1017,initObject);
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = 72;
initObject._y = -16;
attachMovie("container","enemy" + _root.id,-17,initObject);
