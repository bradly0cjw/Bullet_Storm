_Y = -10;
gone = 0;
hp = _root.dif * 40;
sht = random(2);
removed = 1;
bsound = new Sound();
bsound.attachSound("eneshot");
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0)
   {
      if(_loc1_.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      if(gone == 0)
      {
         play();
      }
      else
      {
         stop();
      }
   }
   else
   {
      stop();
   }
   if(_loc1_.plane._y < yp)
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793 - _rotation;
   }
   else
   {
      rota = Math.atan((xp - _loc1_.plane._x) / (_loc1_.plane._y - yp)) * 180 / 3.141592653589793 + 180 - _rotation;
   }
};
