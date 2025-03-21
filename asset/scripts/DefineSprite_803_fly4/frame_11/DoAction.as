if(gone == 0 && sht == 1)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = fly.fly.fly._rotation;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
}
