if(_root.lv1.bossdead == 0)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = _parent._x;
   initObject._y = _parent._y;
   _root.lv1.rtanks.attachMovie("diamond2","diamond" + _root.id,_root.id,initObject);
}
_parent.gotoAndStop(14);
