_root.id = _root.id + 1;
grn.attachMovie("turret","en" + _root.id,_root.id);
_root.id = _root.id + 1;
io = new Object();
io._x = 270;
grn.attachMovie("box","en" + _root.id,_root.id,io);
