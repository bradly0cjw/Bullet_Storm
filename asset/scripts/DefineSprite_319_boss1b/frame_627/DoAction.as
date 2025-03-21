if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp;
   initObject._rotation = fly.fly.fly.fly._rotation;
   _root.itemc.attachMovie("shot5","shot" + _root.id,_root.id,initObject);
   bsound.start(0,0);
}
sc = 0;
