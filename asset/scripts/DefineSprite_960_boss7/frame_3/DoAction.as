if(_Y < 144)
{
   if(_root.scroll == 1 && _root.pause == 0)
   {
      _Y = _Y + 0.8333333333333334;
      if(sht == 1 && gone == 0)
      {
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = xp - 35;
         initObject._y = yp + 7;
         initObject._rotation = rt1 - 15;
         _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = xp - 35;
         initObject._y = yp + 7;
         initObject._rotation = rt1 + 15;
         _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = xp + 35;
         initObject._y = yp + 7;
         initObject._rotation = rt2 - 15;
         _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = xp + 35;
         initObject._y = yp + 7;
         initObject._rotation = rt2 + 15;
         _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
      }
   }
   gotoAndPlay(2);
}
else
{
   _Y = 144;
   fly.fly.fly.gotoAndStop(2);
   gotoAndPlay(4);
}
