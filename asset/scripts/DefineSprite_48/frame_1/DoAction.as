function getPosition()
{
   if(targ.yp < _Y)
   {
      bearing = Math.atan((_X - targ.xp) / (targ.yp - _Y)) * 180 / 3.141592653589793;
   }
   else
   {
      bearing = Math.atan((_X - targ.xp) / (targ.yp - _Y)) * 180 / 3.141592653589793 + 180;
   }
   if(bearing < 0)
   {
      bearing += 360;
   }
   else if(bearing >= 360)
   {
      bearing -= 360;
   }
   rota = _rotation;
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
   _rotation = rota;
}
function getMovement()
{
   xSpeed += 20 * Math.sin(_rotation * 3.141592653589793 / 180);
   ySpeed += 20 * Math.cos(_rotation * 3.141592653589793 / 180);
   xSpeed /= 2;
   ySpeed /= 2;
   _X = _X + xSpeed;
   _Y = _Y - ySpeed;
   if(_X < -10)
   {
      gotoAndStop(1);
   }
   else if(_Y < -18)
   {
      gotoAndStop(1);
   }
   else if(_X > 310)
   {
      gotoAndStop(1);
   }
   else if(_Y > 350)
   {
      gotoAndStop(1);
   }
}
function getdir()
{
   if(targ.xp == undefined || targ.gone == 1)
   {
      targ = _root.eArray[random(_root.eArray.length)];
      if(targ.yp < _Y)
      {
         bearing = Math.atan((_X - targ.xp) / (targ.yp - _Y)) * 180 / 3.141592653589793;
      }
      else
      {
         bearing = Math.atan((_X - targ.xp) / (targ.yp - _Y)) * 180 / 3.141592653589793 + 180;
      }
      orota = bearing - _rotation;
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
_X = _root.preplane._x;
_Y = _root.preplane._y;
stop();
