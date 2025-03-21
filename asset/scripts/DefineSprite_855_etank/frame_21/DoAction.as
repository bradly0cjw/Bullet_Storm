if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + xsl;
   initObject._y = yp + ysl;
   initObject._rotation = rsl;
   _root.itemc.attachMovie("shot6","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + xsr;
   initObject._y = yp + ysr;
   initObject._rotation = rsr;
   _root.itemc.attachMovie("shot6","shot" + _root.id,_root.id,initObject);
   bsound.start(0,0);
}
