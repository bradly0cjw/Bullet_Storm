adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_Y = -30;
gone = 0;
sc = 0;
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
   if(_loc1_.pause == 0)
   {
      if(_loc1_.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      if(gone == 0)
      {
         sc++;
         if(sc > 90)
         {
            sc = 0;
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp - 2;
            initObject._y = yp;
            initObject._rotation = rota;
            _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp + 2;
            initObject._y = yp;
            initObject._rotation = rota;
            _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
         }
      }
      play();
   }
   else
   {
      stop();
   }
};
