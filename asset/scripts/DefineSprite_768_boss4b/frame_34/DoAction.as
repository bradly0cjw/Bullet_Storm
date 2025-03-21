if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = 72;
   _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = 84;
   _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = 96;
   _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = 108;
   _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
   bsound.start(0,0);
}
