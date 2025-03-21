adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 150;
_Y = -38;
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
   if(_loc1_.pause == 0 && _loc1_.scroll == 1 && gone == 0)
   {
      _Y = _Y + 0.8333333333333334;
      sc++;
      play();
   }
   else
   {
      stop();
   }
   if(sc >= 75 && _loc1_.pause == 0 && gone == 0)
   {
      sc = 0;
      _loc1_.id = _loc1_.id + 1;
      initObject = new Object();
      initObject._x = xp - 1;
      initObject._y = yp + 7;
      initObject._rotation = rota;
      _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
   }
   if(_Y >= 389)
   {
      gotoAndStop(14);
   }
};
