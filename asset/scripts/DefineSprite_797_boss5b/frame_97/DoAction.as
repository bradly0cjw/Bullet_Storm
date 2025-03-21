if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 72;
   initObject._y = yp + 8;
   initObject._rotation = 205;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 78;
   initObject._y = yp + 8;
   initObject._rotation = 205;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 72;
   initObject._y = yp + 8;
   initObject._rotation = 155;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 78;
   initObject._y = yp + 8;
   initObject._rotation = 155;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
}
