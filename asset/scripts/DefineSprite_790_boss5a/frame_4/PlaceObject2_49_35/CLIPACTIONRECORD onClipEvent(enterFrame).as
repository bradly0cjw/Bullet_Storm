onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      sc++;
      if(sc < 30)
      {
         if(_parent.gone == 0)
         {
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp;
            initObject._y = _parent.yp;
            initObject._rotation = Math.random() * 360;
            _root.itemc.attachMovie("shot7","shot" + _root.id,_root.id,initObject);
            _parent.bsound.start(0,0);
         }
      }
      if(sc > 120)
      {
         sc = 0;
      }
   }
}
