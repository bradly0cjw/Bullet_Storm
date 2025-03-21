_root.id = _root.id + 1;
initObject = new Object();
initObject._y = -16;
attachMovie("fly","enemy" + _root.id,1009,initObject);
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = 264;
initObject._y = -16;
attachMovie("tank","enemy" + _root.id,-11,initObject);
