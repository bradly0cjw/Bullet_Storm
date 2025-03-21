if(gone == 0 && _rotation == 0 && _Y < 180)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 24;
   initObject._y = yp + 43;
   initObject._rotation = 190;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 24;
   initObject._y = yp + 43;
   initObject._rotation = 170;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
}
