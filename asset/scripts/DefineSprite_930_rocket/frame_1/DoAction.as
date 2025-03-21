adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = random(201) + 50;
_Y = -30;
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
      yp = _Y + fly._y;
      if(_loc1_.pause == 0)
      {
         sc++;
         if(sc >= 30)
         {
            sc = 0;
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp;
            initObject._y = yp;
            initObject._rotation = rota;
            _loc1_.itemc.attachMovie("shot6","shot" + _loc1_.id,_loc1_.id,initObject);
            bsound.start(0,0);
         }
         play();
      }
      else
      {
         stop();
      }
   }
};
