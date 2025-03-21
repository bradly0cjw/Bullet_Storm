onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      sc++;
      if(sc > 60)
      {
         sc = 0;
         if(_parent.gone == 0)
         {
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp;
            initObject._y = _parent.yp;
            initObject._rotation = 0;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp;
            initObject._y = _parent.yp;
            initObject._rotation = 90;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp;
            initObject._y = _parent.yp;
            initObject._rotation = 180;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp;
            initObject._y = _parent.yp;
            initObject._rotation = 270;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
         }
      }
   }
}
