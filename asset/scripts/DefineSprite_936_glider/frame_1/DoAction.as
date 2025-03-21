adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = random(201) + 50;
_Y = -14;
gone = 0;
yspeed = Math.random() * 2;
sc = 40;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
   }
   if(_loc1_.plane._y < yp)
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793 - _rotation;
   }
   else
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793 + 180 - _rotation;
   }
   if(_loc1_.pause == 0 && gone == 0)
   {
      _Y = _Y + (yspeed + 1);
      sc++;
      if(sc >= 45)
      {
         sc = 0;
         _loc1_.id = _loc1_.id + 1;
         initObject = new Object();
         initObject._x = xp;
         initObject._y = yp;
         initObject._rotation = rota;
         _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
      }
      play();
   }
   else
   {
      stop();
   }
   if(_Y >= 367)
   {
      gotoAndStop(19);
   }
};
