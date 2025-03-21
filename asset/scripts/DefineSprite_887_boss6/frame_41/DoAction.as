if(_root.plane._y < yp - 16)
{
   rt1 = Math.atan((xp - 30 - _root.plane._x) / (_root.plane._y + yp - 16)) * 180 / 3.141592653589793;
}
else
{
   rt1 = Math.atan((xp - 30 - _root.plane._x) / (_root.plane._y + yp - 16)) * 180 / 3.141592653589793 + 180;
}
if(_root.plane._y < yp - 16)
{
   rt2 = Math.atan((xp + 30 - _root.plane._x) / (_root.plane._y + yp - 16)) * 180 / 3.141592653589793;
}
else
{
   rt2 = Math.atan((xp + 30 - _root.plane._x) / (_root.plane._y + yp - 16)) * 180 / 3.141592653589793 + 180;
}
