if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 18;
   initObject._y = yp + 20;
   initObject._rotation = 110;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 18;
   initObject._y = yp + 20;
   initObject._rotation = 250;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
}
