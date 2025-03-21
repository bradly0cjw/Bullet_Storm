if(_root.plane._y < yp - 30)
{
   rt1 = Math.atan((xp - _root.plane._x) / (_root.plane._y + yp - 30)) * 180 / 3.141592653589793;
}
else
{
   rt1 = Math.atan((xp - _root.plane._x) / (_root.plane._y + yp - 30)) * 180 / 3.141592653589793 + 180;
}
if(_root.plane._y < yp)
{
   rt4 = Math.atan((xp - 30 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793;
   rt7 = Math.atan((xp - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793;
   rt10 = Math.atan((xp + 30 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793;
}
else
{
   rt4 = Math.atan((xp - 30 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793 + 180;
   rt7 = Math.atan((xp - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793 + 180;
   rt10 = Math.atan((xp + 30 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793 + 180;
}
