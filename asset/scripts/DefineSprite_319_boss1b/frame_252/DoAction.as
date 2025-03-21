fly.fly.fly.fly._rotation -= turn;
if(_root.plane._currentframe < 14 && xp !== undefined)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp;
   initObject._y = yp + 20;
   initObject._rotation = fly.fly.fly.fly._rotation;
   _root.itemc.attachMovie("shot4","shot" + _root.id,_root.id,initObject);
   bsound.start(0,0);
}
