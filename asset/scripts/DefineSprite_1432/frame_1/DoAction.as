function getPosition()
{
   var _loc1_ = _parent;
   if(targ.yp < _loc1_._y)
   {
      bearing = Math.atan((_loc1_._x - targ.xp) / (targ.yp - _loc1_._y)) * 180 / 3.141592653589793;
   }
   else
   {
      bearing = Math.atan((_loc1_._x - targ.xp) / (targ.yp - _loc1_._y)) * 180 / 3.141592653589793 + 180;
   }
   if(bearing < 0)
   {
      bearing += 360;
   }
   else if(bearing >= 360)
   {
      bearing -= 360;
   }
   rota = _loc1_._rotation;
   if(rota < 0)
   {
      rota += 360;
   }
   else if(rota >= 360)
   {
      rota -= 360;
   }
   up = bearing + 10;
   down = up - 20;
   orota = bearing - rota;
   if(orota < 0)
   {
      orota += 360;
   }
   else if(orota >= 360)
   {
      orota -= 360;
   }
   if(rota < up && rota > down)
   {
      rota = bearing;
   }
   else if(orota <= 180)
   {
      rota += 20;
   }
   else
   {
      rota -= 20;
   }
   _loc1_._rotation = rota;
}
function getMovement()
{
   var _loc1_ = _parent;
   xSpeed += 3 * Math.sin(_loc1_._rotation * 3.141592653589793 / 180);
   ySpeed += 3 * Math.cos(_loc1_._rotation * 3.141592653589793 / 180);
   xSpeed *= 0.8;
   ySpeed *= 0.8;
   _loc1_._x += xSpeed;
   _loc1_._y -= ySpeed;
   if(_loc1_._x < -10)
   {
      gotoAndStop(1);
   }
   else if(_loc1_._y < -40)
   {
      gotoAndStop(1);
   }
   else if(_loc1_._x > 310)
   {
      gotoAndStop(1);
   }
   else if(_loc1_._y > 350)
   {
      gotoAndStop(1);
   }
}
function getdir()
{
   var _loc1_ = _root;
   if(targ.xp == undefined || targ.gone == 1)
   {
      targ = _loc1_.lv1.planeArray[random(_loc1_.lv1.planeArray.length)];
      getMovement();
   }
   else if(_loc1_.mhm == 0)
   {
      getMovement();
   }
   else
   {
      getPosition();
      getMovement();
   }
}
function getdir2()
{
   if(targ.xp == undefined || targ.gone == 1 || _root.mhm == 0)
   {
      getMovement();
   }
   else
   {
      getPosition();
      getMovement();
   }
}
xSpeed = 0;
ySpeed = 0;
_parent._x = _root.plane._x;
_parent._y = _root.plane._y;
dm = 6;
stop();
