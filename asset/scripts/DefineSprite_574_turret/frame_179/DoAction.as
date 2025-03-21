if(_root.plane._y < yp - 30)
{
   rt = Math.atan((xp - _root.plane._x) / (_root.plane._y - (yp - 30))) * 180 / 3.141592653589793;
}
else
{
   rt = Math.atan((xp - _root.plane._x) / (_root.plane._y - (yp - 30))) * 180 / 3.141592653589793 + 180;
}
