_root.id = _root.id + 1;
initObject = new Object();
initObject._y = -16;
attachMovie("fly2","enemy" + _root.id,1060,initObject);
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = -16;
initObject._y = 340;
attachMovie("tank2","enemy" + _root.id,-49,initObject);
