_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent._parent._parent._parent.xp;
initObject._y = _parent._parent._parent._parent.yp;
_root.itemc.attachMovie("ruby","ruby" + _root.id,_root.id,initObject);
