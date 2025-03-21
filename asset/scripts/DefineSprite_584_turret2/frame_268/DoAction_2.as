if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp - 32;
   initObject._rotation = rt - 22;
   _root.itemc.attachMovie("shot6","shot" + _root.id,_root.id,initObject);
   bsound.start(0,0);
}
