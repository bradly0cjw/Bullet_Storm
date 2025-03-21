adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 150;
_Y = -22;
gone = 0;
sht = 0;
sc = 0;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(gone == 0)
   {
      xp = _X;
      yp = _Y + fly._y;
   }
   if(_loc1_.pause == 0 && gone == 0)
   {
      if(sht == 1)
      {
         sc++;
      }
      if(sc > 4)
      {
         sc = 0;
         _loc1_.id = _loc1_.id + 1;
         initObject = new Object();
         initObject._x = xp;
         initObject._y = yp + 16;
         initObject._rotation = 180;
         _loc1_.itemc.attachMovie("shot","shot" + _loc1_.id,_loc1_.id,initObject);
      }
      play();
   }
   else
   {
      stop();
   }
};
