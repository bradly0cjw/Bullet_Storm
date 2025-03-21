onClipEvent(enterFrame){
   if(_root.pause == 0 && _parent.gone == 0)
   {
      sc1++;
      if(sc1 >= 12)
      {
         sc1 = 0;
         sc2++;
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = _parent.xp - 15;
         initObject._y = _parent.yp + 16;
         initObject._rotation = 180;
         _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = _parent.xp + 15;
         initObject._y = _parent.yp + 16;
         initObject._rotation = 180;
         _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
      }
      if(sc2 >= 3)
      {
         sc2 = 0;
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = _parent.xp - 27;
         initObject._y = _parent.yp + 8;
         initObject._rotation = 222;
         _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = _parent.xp + 27;
         initObject._y = _parent.yp + 8;
         initObject._rotation = 138;
         _root.itemc.attachMovie("shot","shot" + _root.id,_root.id,initObject);
      }
   }
}
