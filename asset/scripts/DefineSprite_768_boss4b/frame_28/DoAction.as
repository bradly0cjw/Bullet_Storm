if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = 252;
   _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = 264;
   _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = 276;
   _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = 288;
   _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
   bsound.start(0,0);
}
