onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      sc++;
      if(sc > 45)
      {
         sc = 0;
         if(gone == 0)
         {
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp - 40;
            initObject._y = _parent.yp;
            initObject._rotation = 315;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp - 40;
            initObject._y = _parent.yp;
            initObject._rotation = 225;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp + 40;
            initObject._y = _parent.yp;
            initObject._rotation = 45;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp + 40;
            initObject._y = _parent.yp;
            initObject._rotation = 135;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp - 20;
            initObject._y = _parent.yp;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp - 20;
            initObject._y = _parent.yp;
            initObject._rotation = 180;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp + 20;
            initObject._y = _parent.yp;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
            _root.id = _root.id + 1;
            initObject = new Object();
            initObject._x = _parent.xp + 20;
            initObject._y = _parent.yp;
            initObject._rotation = 180;
            _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
         }
      }
   }
}
