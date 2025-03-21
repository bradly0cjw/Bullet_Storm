_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent._x;
initObject._y = _parent._y;
_root.cont.attachMovie("preblast2","blast" + _root.id,_root.id,initObject);
_parent.gotoAndStop(1);
stop();
