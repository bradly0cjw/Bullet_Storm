adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 150;
_Y = -32;
gone = 0;
sc1 = -40;
sc2 = -45;
cycle = 0;
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
      play();
      sc1++;
      sc2++;
      if(sc1 >= 30)
      {
         sc1 = 0;
         _loc1_.id = _loc1_.id + 1;
         initObject = new Object();
         initObject._x = xp - 42;
         initObject._y = yp + 20;
         initObject._rotation = 180;
         _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
         _loc1_.id = _loc1_.id + 1;
         initObject = new Object();
         initObject._x = xp + 42;
         initObject._y = yp + 20;
         initObject._rotation = 180;
         _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
      }
      if(sc2 >= 30)
      {
         sc2 = 0;
         _loc1_.id = _loc1_.id + 1;
         initObject = new Object();
         initObject._x = xp - 24;
         initObject._y = yp + 16;
         initObject._rotation = 180;
         _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
         _loc1_.id = _loc1_.id + 1;
         initObject = new Object();
         initObject._x = xp + 24;
         initObject._y = yp + 16;
         initObject._rotation = 180;
         _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
      }
   }
   else
   {
      stop();
   }
};
