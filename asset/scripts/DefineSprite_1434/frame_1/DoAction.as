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
   up = bearing + 13.5;
   down = up - 27;
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
      rota += 27;
   }
   else
   {
      rota -= 27;
   }
   _loc1_._rotation = rota;
}
function getMovement()
{
   var _loc1_ = _parent;
   xSpeed += 20 * Math.sin(_loc1_._rotation * 3.141592653589793 / 180);
   ySpeed += 20 * Math.cos(_loc1_._rotation * 3.141592653589793 / 180);
   xSpeed /= 2;
   ySpeed /= 2;
   _loc1_._x += xSpeed;
   _loc1_._y -= ySpeed;
   if(_loc1_._x < -30)
   {
      gotoAndStop(1);
   }
   else if(_loc1_._y < -30)
   {
      gotoAndStop(1);
   }
   else if(_loc1_._x > 330)
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
   var _loc1_ = _parent;
   var _loc2_ = _root;
   if(targ.xp == undefined || targ.gone == 1)
   {
      targ = _loc2_.lv1.planeArray[random(_loc2_.lv1.planeArray.length)];
      if(_currentframe > 10)
      {
         if(targ.yp < _loc1_._y)
         {
            bearing = Math.atan((_loc1_._x - targ.xp) / (targ.yp - _loc1_._y)) * 180 / 3.141592653589793;
         }
         else
         {
            bearing = Math.atan((_loc1_._x - targ.xp) / (targ.yp - _loc1_._y)) * 180 / 3.141592653589793 + 180;
         }
         orota = bearing - _loc1_._rotation;
         if(orota < 0)
         {
            orota += 360;
         }
         else if(orota >= 360)
         {
            orota -= 360;
         }
         if(orota > 105 && orota < 255)
         {
            delete targ;
         }
      }
      getMovement();
   }
   else if(_loc2_.mhm == 0)
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
