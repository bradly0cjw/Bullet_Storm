_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent._parent._x + _X;
initObject._y = _parent._parent._y + _Y - 24;
_root.itemc.attachMovie("hitb","hit" + _root.id,_root.id,initObject);
_parent.gotoAndStop(1);
stop();
