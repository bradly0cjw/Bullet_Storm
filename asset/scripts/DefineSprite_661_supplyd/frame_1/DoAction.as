_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _X;
initObject._y = _Y;
_root.debris.attachMovie("medal","medal" + _root.id,_root.id,initObject);
this.onEnterFrame = function()
{
   if(_root.pause == 0 && _root.scroll == 1)
   {
      _Y = _Y + 0.8333333333333334;
   }
   if(_Y >= 377)
   {
      this.removeMovieClip();
   }
};
