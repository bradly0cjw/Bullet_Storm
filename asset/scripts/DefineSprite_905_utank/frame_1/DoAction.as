gone = 0;
rota = 180;
sc1 = 0;
sc2 = -2;
sc3 = -4;
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
      sc1++;
      sc2++;
      sc3++;
      if(sc1 > 120)
      {
         sc1 = 0;
         if(gone == 0 && _Y < 256)
         {
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp - 24 * Math.sin((rota + 180) * 0.017453292519943295);
            initObject._y = yp + 24 * Math.cos((rota + 180) * 0.017453292519943295);
            initObject._rotation = rota;
            _loc1_.itemc.attachMovie("shot6","shot" + _loc1_.id,_loc1_.id,initObject);
            fly.fly.fly.fly.play();
            bsound.start(0,0);
         }
      }
      if(sc2 > 120)
      {
         sc2 = 0;
         if(gone == 0 && _Y < 256)
         {
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp - 24 * Math.sin((rota + 180) * 0.017453292519943295);
            initObject._y = yp + 24 * Math.cos((rota + 180) * 0.017453292519943295);
            initObject._rotation = rota;
            _loc1_.itemc.attachMovie("shot6","shot" + _loc1_.id,_loc1_.id,initObject);
            fly.fly.fly.fly.play();
            bsound.start(0,0);
         }
      }
      if(sc3 > 120)
      {
         sc3 = 0;
         if(gone == 0 && _Y < 256)
         {
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp - 24 * Math.sin((rota + 180) * 0.017453292519943295);
            initObject._y = yp + 24 * Math.cos((rota + 180) * 0.017453292519943295);
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
   if(yp >= 371)
   {
      gotoAndStop(64);
   }
};
