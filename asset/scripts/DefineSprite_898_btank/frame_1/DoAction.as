adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_Y = -32;
gone = 0;
sc = 0;
sc2 = 0;
rt = 0;
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
      sc2++;
      play();
   }
   else
   {
      stop();
   }
   if(sc > 1 && sc2 < 150 && _loc1_.pause == 0 && gone == 0)
   {
      sc = 0;
      rt += 57;
      _loc1_.id = _loc1_.id + 1;
      initObject = new Object();
      initObject._x = xp;
      initObject._y = yp;
      initObject._rotation = rt;
      _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
   }
   if(sc2 > 240)
   {
      sc2 = 0;
   }
   if(_Y >= 382)
   {
      gotoAndStop(14);
   }
};
