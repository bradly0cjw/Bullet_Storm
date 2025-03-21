gone = 1;
_root.lv1.planeArray[adt] = null;
_root.lv1.upd();
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = xp;
initObject._y = yp;
_root.debris.attachMovie("tankdead","debris" + _root.id,_root.id,initObject);
delete xp;
delete yp;
if(win == 1)
{
   _root.score += 10000;
   bsound.start(0,0);
   _root.tth._x = _X;
   _root.tth._y = _Y;
   _root.tth.gotoAndPlay(2);
}
this.removeMovieClip();
