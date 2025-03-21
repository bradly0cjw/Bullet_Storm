if(_root.plane._y < yp + 7)
{
   rt1 = Math.atan((xp - 35 - _root.plane._x) / (_root.plane._y + yp + 7)) * 180 / 3.141592653589793;
}
else
{
   rt1 = Math.atan((xp - 35 - _root.plane._x) / (_root.plane._y + yp + 7)) * 180 / 3.141592653589793 + 180;
}
if(_root.plane._y < yp + 7)
{
   rt2 = Math.atan((xp + 35 - _root.plane._x) / (_root.plane._y + yp + 7)) * 180 / 3.141592653589793;
}
else
{
   rt2 = Math.atan((xp + 35 - _root.plane._x) / (_root.plane._y + yp + 7)) * 180 / 3.141592653589793 + 180;
}
