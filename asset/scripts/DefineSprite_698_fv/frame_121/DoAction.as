if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 1;
   initObject._y = yp - 15;
   initObject._rotation = rota;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 1;
   initObject._y = yp - 11;
   initObject._rotation = rota;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 1;
   initObject._y = yp - 7;
   initObject._rotation = rota;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
}
