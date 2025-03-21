if(_root.plane._currentframe < 14 && xp !== undefined)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp - 21 * Math.sin((rota + 180) * 0.017453292519943295);
   initObject._y = yp - 5 + 21 * Math.cos((rota + 180) * 0.017453292519943295);
   initObject._rotation = rota;
   _root.itemc.attachMovie("shot3","shot" + _root.id,_root.id,initObject);
   fly.fly.fly.fly.play();
}
