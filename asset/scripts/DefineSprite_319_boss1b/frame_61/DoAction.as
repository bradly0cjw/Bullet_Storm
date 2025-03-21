if(_root.plane._y < yp)
{
   bearing = Math.atan((xp - _root.plane._x) / (_root.plane._y - yp)) * 180 / 3.141592653589793;
}
else
{
   bearing = Math.atan((xp - _root.plane._x) / (_root.plane._y - yp)) * 180 / 3.141592653589793 + 180;
}
if(bearing < 0)
{
   bearing += 360;
}
else if(bearing >= 360)
{
   bearing -= 360;
}
fly.fly.fly.fly._rotation += bearing / 60;
