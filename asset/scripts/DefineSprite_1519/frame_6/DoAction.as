_root.ictrl.nextFrame();
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _X + 10;
initObject._y = _Y + 10;
_root.itemc.attachMovie(_root.ictrl.ty,"itm" + _root.id,_root.id,initObject);
