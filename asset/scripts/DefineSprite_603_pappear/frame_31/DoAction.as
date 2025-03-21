_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _X;
initObject._y = _Y;
_root.lv1.sky.attachMovie("fplane2","en" + _root.id,_root.id,initObject);
this.removeMovieClip();
