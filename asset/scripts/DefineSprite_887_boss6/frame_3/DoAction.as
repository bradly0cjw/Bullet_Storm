if(_Y > 80)
{
   if(_root.pause == 0)
   {
      _Y = _Y - 2;
      if(sht == 1 && gone == 0)
      {
         _root.id = _root.id + 1;
         initObject = new Object();
         initObject._x = xp;
         initObject._y = yp;
         initObject._rotation = rota;
         _root.itemc.attachMovie("shot2","shot" + _root.id,_root.id,initObject);
      }
   }
   gotoAndPlay(2);
}
else
{
   _Y = 80;
   fscroll = 1;
   gotoAndPlay(4);
}
