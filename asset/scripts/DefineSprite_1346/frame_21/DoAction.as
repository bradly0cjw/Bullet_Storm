_root.id = _root.id + 1;
initObject = new Object();
initObject._x = 72;
initObject._y = -27;
attachMovie("bomber","enemy" + _root.id,11,initObject);
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = 207;
initObject._y = -16;
attachMovie("tank","enemy" + _root.id,-10,initObject);
