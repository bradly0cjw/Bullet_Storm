adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
gone = 0;
sc = 0;
del = Math.random() * 60 + 60;
bsound = new Sound();
bsound.attachSound("eneshot");
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
      if(gone == 0)
      {
         sc++;
         if(sc > del)
         {
            sc = 0;
            del = Math.random() * 60 + 60;
            rt = Math.random() * 360;
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp;
            initObject._y = yp;
            initObject._rotation = rt - 15;
            _loc1_.itemc.attachMovie("shot6","shot" + _loc1_.id,_loc1_.id,initObject);
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp;
            initObject._y = yp;
            initObject._rotation = rt + 15;
            _loc1_.itemc.attachMovie("shot6","shot" + _loc1_.id,_loc1_.id,initObject);
            bsound.start(0,0);
         }
         if(_loc1_.lv1.dgshoot == 1)
         {
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp;
            initObject._y = yp;
            initObject._rotation = rota - 15;
            _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp;
            initObject._y = yp;
            initObject._rotation = rota + 15;
            _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
         }
      }
      if(_loc1_.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      play();
   }
   else
   {
      stop();
   }
};
