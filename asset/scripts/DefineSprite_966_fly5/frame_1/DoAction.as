adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = random(201) + 50;
_Y = -17;
gone = 0;
speed = 2;
sc = 25;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(gone == 0)
   {
      xp = _X + fly._x;
      yp = _Y + fly._y;
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
   if(sc >= 30 && _loc1_.pause == 0 && _loc1_.plane._currentframe < 14 && xp !== undefined)
   {
      sc = 0;
      _loc1_.id = _loc1_.id + 1;
      initObject = new Object();
      initObject._x = xp;
      initObject._y = yp;
      initObject._rotation = fly.fly.fly._rotation;
      _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
   }
};
