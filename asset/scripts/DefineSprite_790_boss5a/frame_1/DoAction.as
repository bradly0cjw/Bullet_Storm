adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 150;
_Y = -116;
gone = 0;
sc = 0;
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
   if(_loc1_.pause == 0 && gone == 0)
   {
      sc++;
      play();
   }
   else
   {
      stop();
   }
   if(_loc1_.plane._y < yp + 56)
   {
      rota1 = Math.atan((xp - 68 - _loc1_.plane._x) / (_loc1_.plane._y - yp + 56)) * 180 / 3.141592653589793 - _rotation;
      rota2 = Math.atan((xp + 68 - _loc1_.plane._x) / (_loc1_.plane._y - yp + 56)) * 180 / 3.141592653589793 - _rotation;
   }
   else
   {
      rota1 = Math.atan((xp - 68 - _loc1_.plane._x) / (_loc1_.plane._y - yp + 56)) * 180 / 3.141592653589793 + 180 - _rotation;
      rota2 = Math.atan((xp + 68 - _loc1_.plane._x) / (_loc1_.plane._y - yp + 56)) * 180 / 3.141592653589793 + 180 - _rotation;
   }
   if(sc > 90 && _loc1_.pause == 0 && gone == 0)
   {
      sc = 0;
      _loc1_.id = _loc1_.id + 1;
      initObject = new Object();
      initObject._x = xp - 68;
      initObject._y = yp + 56;
      initObject._rotation = rota1;
      _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
      _loc1_.id = _loc1_.id + 1;
      initObject = new Object();
      initObject._x = xp + 68;
      initObject._y = yp + 56;
      initObject._rotation = rota2;
      _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
   }
};
