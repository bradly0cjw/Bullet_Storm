onClipEvent(enterFrame){
   if(_root.pause == 0 && _parent.gone == 0)
   {
      if(_root.plane._y < _parent.yp)
      {
         bearing = Math.atan((_parent.xp - _root.plane._x) / (_root.plane._y - _parent.yp)) * 180 / 3.141592653589793 - _rotation;
      }
      else
      {
         bearing = Math.atan((_parent.xp - _root.plane._x) / (_root.plane._y - _parent.yp)) * 180 / 3.141592653589793 + 180 - _rotation;
      }
      if(bearing >= 360)
      {
         bearing -= 360;
      }
      else if(bearing < 0)
      {
         bearing += 360;
      }
      mr = _parent.fly._rotation;
      if(mr >= 360)
      {
         bearing -= 360;
      }
      else if(bearing < 0)
      {
         mr += 360;
      }
      up = bearing + 10;
      down = up - 20;
      orota = bearing - mr;
      if(orota < 0)
      {
         orota += 360;
      }
      else if(orota >= 360)
      {
         orota -= 360;
      }
      if(mr < up && mr > down)
      {
         mr = bearing;
      }
      else if(orota <= 180)
      {
         mr += 10;
      }
      else
      {
         mr -= 10;
      }
      _parent.fly._rotation = mr;
   }
}
