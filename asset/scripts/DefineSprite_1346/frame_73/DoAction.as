_root.id = _root.id + 1;
initObject = new Object();
initObject._x = 40;
initObject._y = -16;
attachMovie("box","enemy" + _root.id,-31,initObject);
_root.id = _root.id + 1;
initObject = new Object();
initObject._y = -16;
attachMovie("fly","enemy" + _root.id,1038,initObject);
