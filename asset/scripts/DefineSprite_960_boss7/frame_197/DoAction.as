if(gone == 0)
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
