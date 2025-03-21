if(_root.plane._y < yp + 50)
{
   rt1 = Math.atan((xp - 15 - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793;
}
else
{
   rt1 = Math.atan((xp - 15 - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793 + 180;
}
if(_root.plane._y < yp + 50)
{
   rt2 = Math.atan((xp - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793;
}
else
{
   rt2 = Math.atan((xp - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793 + 180;
}
if(_root.plane._y < yp + 50)
{
   rt3 = Math.atan((xp + 14 - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793;
}
else
{
   rt3 = Math.atan((xp + 14 - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793 + 180;
}
