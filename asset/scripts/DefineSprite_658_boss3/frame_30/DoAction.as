if(_root.plane._y < yp + 32)
{
   rt1 = Math.atan((xp - 24 - _root.plane._x) / (_root.plane._y + yp + 32)) * 180 / 3.141592653589793;
}
else
{
   rt1 = Math.atan((xp - 24 - _root.plane._x) / (_root.plane._y + yp + 32)) * 180 / 3.141592653589793 + 180;
}
if(_root.plane._y < yp + 32)
{
   rt2 = Math.atan((xp + 24 - _root.plane._x) / (_root.plane._y + yp + 32)) * 180 / 3.141592653589793;
}
else
{
   rt2 = Math.atan((xp + 24 - _root.plane._x) / (_root.plane._y + yp + 32)) * 180 / 3.141592653589793 + 180;
}
if(_root.plane._y < yp + 50)
{
   rt3 = Math.atan((xp - 59 - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793;
}
else
{
   rt3 = Math.atan((xp - 59 - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793 + 180;
}
if(_root.plane._y < yp + 50)
{
   rt4 = Math.atan((xp + 59 - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793;
}
else
{
   rt4 = Math.atan((xp + 59 - _root.plane._x) / (_root.plane._y + yp + 50)) * 180 / 3.141592653589793 + 180;
}
