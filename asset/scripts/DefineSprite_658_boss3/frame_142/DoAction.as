if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 48;
   initObject._y = yp + 4;
   initObject._rotation = rt1;
   _root.itemc.attachMovie("shot9","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 48;
   initObject._y = yp + 4;
   initObject._rotation = rt2;
   _root.itemc.attachMovie("shot9","shot" + _root.id,_root.id,initObject);
}
