if(_root.plane._x < 150)
{
   if(_root.plane._y < 96)
   {
      _root.id = _root.id + 1;
      sky.attachMovie("spirallt","en" + _root.id,_root.id,io);
   }
   else
   {
      _root.id = _root.id + 1;
      sky.attachMovie("spirall","en" + _root.id,_root.id,io);
   }
}
else if(_root.plane._y < 96)
{
   _root.id = _root.id + 1;
   sky.attachMovie("spiralrt","en" + _root.id,_root.id,io);
}
else
{
   _root.id = _root.id + 1;
   sky.attachMovie("spiralr","en" + _root.id,_root.id,io);
}
_root.id = _root.id + 1;
io = new Object();
io._y = 250;
grn.attachMovie("tank2","en" + _root.id,_root.id,io);
