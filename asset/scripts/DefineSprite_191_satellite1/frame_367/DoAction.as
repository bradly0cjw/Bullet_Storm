if(gone == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp + 9;
   initObject._rotation = rota;
   _root.itemc.attachMovie("shot2","shot" + _root.id,_root.id,initObject);
}
