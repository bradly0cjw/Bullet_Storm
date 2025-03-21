_root.id = _root.id + 1;
initObject = new Object();
initObject._y = -16;
attachMovie("fly","enemy" + _root.id,1011,initObject);
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = 47;
initObject._y = -16;
attachMovie("tank","enemy" + _root.id,-13,initObject);
