onClipEvent(enterFrame){
   if(_root.pause == 0 && _parent.gone == 0)
   {
      sc++;
      if(sc > 4)
      {
         sc = 0;
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = _parent.xp - 14;
         initObject._y = _parent.yp - 22;
         _root.debris.attachMovie("boss5cfuel","fuel" + _root.id,_root.id,initObject);
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = _parent.xp + 14;
         initObject._y = _parent.yp - 22;
         _root.debris.attachMovie("boss5cfuel","fuel" + _root.id,_root.id,initObject);
      }
   }
}
