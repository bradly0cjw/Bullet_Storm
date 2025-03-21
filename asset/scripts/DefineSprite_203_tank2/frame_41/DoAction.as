if(_root.plane._currentframe < 14 && gone == 0 && _Y < 256)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 4 - 16 * Math.sin((rota + 180) * 0.017453292519943295);
   initObject._y = yp - 1 + 16 * Math.cos((rota + 180) * 0.017453292519943295);
   initObject._rotation = rota;
   _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
   fly.fly.fly.fly.play();
}
