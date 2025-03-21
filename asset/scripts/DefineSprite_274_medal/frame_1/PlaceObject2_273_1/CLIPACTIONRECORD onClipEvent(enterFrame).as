onClipEvent(enterFrame){
   if(_root.pause == 0 && _root.scroll == 1)
   {
      if(_root.lv1.lv2spd == 1)
      {
         _Y = _Y + 2.5;
      }
      else
      {
         _Y = _Y + 0.8333333333333334;
      }
   }
   if(hitTest(_root.bborder2))
   {
      _parent.gotoAndStop(2);
   }
}
