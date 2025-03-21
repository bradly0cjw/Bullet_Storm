adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
gone = 0;
sc = 0;
rt = 0;
sh = 0;
adelay1 = 0;
adelay2 = 0;
count1 = 0;
count2 = 0;
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
      xp = _X;
      yp = _Y;
   }
   if(_loc1_.pause == 0 && gone == 0)
   {
      mt++;
      _rotation = rt;
      sc++;
      if(sc > 360 && sc < 450)
      {
         _loc1_.lv1.bossastgen.gotoAndStop(2);
         rt += 24;
         if(gone == 0)
         {
            _loc1_.id = _loc1_.id + 1;
            initObject = new Object();
            initObject._x = xp;
            initObject._y = yp;
            initObject._rotation = rt + 175;
            _loc1_.itemc.attachMovie("shot7","shot" + _loc1_.id,_loc1_.id,initObject);
            sh++;
            if(sh > 0)
            {
               sh = 0;
               bsound.start(0,0);
            }
         }
      }
      else if(sc > 450)
      {
         _loc1_.lv1.bossastgen.gotoAndStop(1);
         sc = 0;
         rt = 0;
      }
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
   }
   if(_loc1_.pause == 0)
   {
      if(_loc1_.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      if(_loc1_.lv1.rtanks.tank1.gone == 1 || _loc1_.lv1.rtanks.tank1.gone == undefined)
      {
         if(adelay1 == 0)
         {
            adelay1 = 1;
         }
      }
      if(_loc1_.lv1.rtanks.tank2.gone == 1 || _loc1_.lv1.rtanks.tank2.gone == undefined)
      {
         if(adelay2 == 0)
         {
            adelay2 = 1;
         }
      }
      if(adelay1 == 1)
      {
         count1++;
         if(count1 > 90)
         {
            count1 = 0;
            adelay1 = 0;
            initObject = new Object();
            initObject._x = 59;
            _loc1_.lv1.rtanks.attachMovie("rtank2","tank1",1,initObject);
         }
      }
      if(adelay2 == 1)
      {
         count2++;
         if(count2 > 90)
         {
            count2 = 0;
            adelay2 = 0;
            initObject = new Object();
            initObject._x = 240;
            _loc1_.lv1.rtanks.attachMovie("rtank2","tank2",2,initObject);
         }
      }
   }
};
stop();
