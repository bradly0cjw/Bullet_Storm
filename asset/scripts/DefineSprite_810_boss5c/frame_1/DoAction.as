adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
gone = 0;
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
      xp = _X + fly._x;
      yp = _Y + fly._y;
   }
   if(_loc1_.pause == 0 && gone == 0)
   {
      mt++;
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
      play();
   }
   else
   {
      stop();
   }
};
