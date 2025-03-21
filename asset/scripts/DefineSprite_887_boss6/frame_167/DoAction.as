if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 16;
   initObject._y = yp - 61;
   initObject._rotation = rt1;
   _root.itemc.attachMovie("shot2","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 16;
   initObject._y = yp - 61;
   initObject._rotation = rt2;
   _root.itemc.attachMovie("shot2","shot" + _root.id,_root.id,initObject);
}
