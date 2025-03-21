gone = 0;
rota = 180;
sc = 0;
bsound = new Sound();
bsound.attachSound("eneshot");
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
      play();
      if(_loc1_.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      sc++;
      if(sc > 120)
      {
         sc = 0;
         if(_loc1_.plane._currentframe < 14 && gone == 0 && _Y < 256)
         {
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp - 10 * Math.sin((rota + 180) * 0.017453292519943295);
            initObject._y = yp + 10 * Math.cos((rota + 180) * 0.017453292519943295);
            initObject._rotation = rota;
            _loc1_.itemc.attachMovie("shot6","shot" + _loc1_.id,_loc1_.id,initObject);
            fly.fly.fly.fly.play();
            bsound.start(0,0);
         }
      }
   }
   else
   {
      stop();
   }
};
