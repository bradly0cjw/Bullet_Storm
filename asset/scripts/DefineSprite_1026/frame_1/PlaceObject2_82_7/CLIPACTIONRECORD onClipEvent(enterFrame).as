onClipEvent(enterFrame){
   if(_root.pause == 0 && hitTest(_root.lv1.grn.specialtank))
   {
      _root.id = _root.id + 1;
      initObject = new Object();
      initObject._x = _parent._parent.xp;
      initObject._y = _parent._parent.yp;
      _root.itemc.attachMovie("1up","item" + _root.id,_root.id,initObject);
      _parent.meda = 1;
      _parent.play();
   }
}
