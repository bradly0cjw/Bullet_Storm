if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 24;
   initObject._y = yp + 32;
   initObject._rotation = rt1;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 24;
   initObject._y = yp + 32;
   initObject._rotation = rt2;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = -59;
   initObject._y = 50;
   initObject._rotation = rt3;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = 59;
   initObject._y = 50;
   initObject._rotation = rt4;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
}
