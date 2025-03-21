if(_root.plane._x > 150)
{
   _root.id = _root.id + 1;
   sky.attachMovie("vulturer","en" + _root.id,_root.id);
}
else
{
   _root.id = _root.id + 1;
   sky.attachMovie("vulturel","en" + _root.id,_root.id);
}
_root.id = _root.id + 1;
io = new Object();
io._x = 106;
grn.attachMovie("tank4","en" + _root.id,_root.id,io);
_root.id = _root.id + 1;
io = new Object();
io._x = 146;
grn.attachMovie("tank4","en" + _root.id,_root.id,io);
_root.id = _root.id + 1;
io = new Object();
io._x = 186;
grn.attachMovie("tank4","en" + _root.id,_root.id,io);
_root.id = _root.id + 1;
io = new Object();
io._x = 226;
grn.attachMovie("tank4","en" + _root.id,_root.id,io);
