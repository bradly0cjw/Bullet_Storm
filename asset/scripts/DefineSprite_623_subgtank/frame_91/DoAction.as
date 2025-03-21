if(_root.plane._currentframe < 14 && gone == 0 && sst == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 10 * Math.sin((rota + 180) * 0.017453292519943295);
   initObject._y = yp + 10 * Math.cos((rota + 180) * 0.017453292519943295);
   initObject._rotation = rota;
   _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
   fly.fly.fly.fly.play();
   bsound.start(0,0);
}
