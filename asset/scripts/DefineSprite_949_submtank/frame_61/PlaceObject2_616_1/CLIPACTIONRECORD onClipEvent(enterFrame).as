onClipEvent(enterFrame){
   if(_parent.gone == 1 || _parent.hp <= 0)
   {
      _parent.gone = 1;
      _parent.hp = 0;
      delete _parent.xp;
      delete _parent.yp;
      _parent.gotoAndStop(31);
   }
}
