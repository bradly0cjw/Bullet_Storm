if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + 18;
   initObject._y = yp + 20;
   initObject._rotation = 150;
   _root.itemc.attachMovie("shot6","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 18;
   initObject._y = yp + 20;
   initObject._rotation = 210;
   _root.itemc.attachMovie("shot6","shot" + _root.id,_root.id,initObject);
   bsound.start(0,0);
}
