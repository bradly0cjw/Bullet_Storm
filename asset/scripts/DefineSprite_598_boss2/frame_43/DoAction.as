if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 24;
   initObject._y = yp + 24;
   initObject._rotation = 180;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 24;
   initObject._y = yp + 24;
   initObject._rotation = 180;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
}
