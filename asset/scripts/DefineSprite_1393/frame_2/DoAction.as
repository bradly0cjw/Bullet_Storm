_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent._parent._x - _Y * Math.sin(_parent._parent._rotation * 3.141592653589793 / 180);
initObject._y = _parent._parent._y + _Y * Math.cos(_parent._parent._rotation * 3.141592653589793 / 180);
initObject._rotation = _parent._parent._rotation;
_root.itemc.attachMovie("hity","hit" + _root.id,_root.id,initObject);
_parent.gotoAndStop(1);
stop();
