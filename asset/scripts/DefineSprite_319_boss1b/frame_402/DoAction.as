if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp + 20;
   _root.itemc.attachMovie("shot4","shot" + _root.id,_root.id,initObject);
   bsound.start(0,0);
}
