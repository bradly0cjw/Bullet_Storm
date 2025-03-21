if(_root.plane._y < yp)
{
   rt1 = Math.atan((xp - 61 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793;
}
else
{
   rt1 = Math.atan((xp - 61 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793 + 180;
}
if(_root.plane._y < yp)
{
   rt2 = Math.atan((xp + 59 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793;
}
else
{
   rt2 = Math.atan((xp + 59 - _root.plane._x) / (_root.plane._y + yp)) * 180 / 3.141592653589793 + 180;
}
