onClipEvent(enterFrame){
   if(_root.pause == 0 && _parent.gone == 0)
   {
      sc++;
      if(sc >= 2)
      {
         sc = 0;
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = _parent.xp + 1;
         initObject._y = _parent.yp - 12;
         initObject._rotation = Math.random() * 360;
         _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
         _parent.bsound.start(0,0);
      }
   }
}
