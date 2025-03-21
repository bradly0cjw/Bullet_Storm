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
io._y = 102;
grn.attachMovie("tank2","en" + _root.id,_root.id,io);
