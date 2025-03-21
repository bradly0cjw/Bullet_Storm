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
io._x = 10;
grn.attachMovie("tank","en" + _root.id,_root.id,io);
_root.id = _root.id + 1;
io = new Object();
io._y = 24;
grn.attachMovie("tank2z","en" + _root.id,_root.id,io);
