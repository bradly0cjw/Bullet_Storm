adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 150;
_Y = -160;
gone = 0;
rota = 180;
sc = 0;
count = 0;
mt = 0;
tm = 0;
total = 600;
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
   if(_loc1_.pause == 0 && gone == 0)
   {
      mt++;
      sc++;
      if(sc > 120)
      {
         sc = 0;
         if(gone == 0)
         {
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp - 42 * Math.sin((rota + 180) * 0.017453292519943295);
            initObject._y = yp + 42 * Math.cos((rota + 180) * 0.017453292519943295);
            initObject._rotation = rota;
            _loc1_.itemc.attachMovie("shot8","shot" + _loc1_.id,_loc1_.id,initObject);
         }
      }
      if(_Y < 64 && _loc1_.pause == 0 && _loc1_.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      else
      {
         _Y = 64;
      }
      play();
      tm++;
      if(tm > total)
      {
         tm = 0;
         total *= 1.2;
         _loc1_.ictrl.nextFrame();
         _loc1_.id = _loc1_.id + 1;
         initObject = new Object();
         initObject._x = 150;
         initObject._y = -15;
         _loc1_.itemc.attachMovie(_loc1_.ictrl.ty,"itm" + _loc1_.id,_loc1_.id,initObject);
      }
   }
   else
   {
      stop();
   }
   fly.fly.fly.fly._rotation = rota + 180;
};
