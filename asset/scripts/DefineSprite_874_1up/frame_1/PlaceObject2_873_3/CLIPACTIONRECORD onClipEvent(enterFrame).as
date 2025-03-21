onClipEvent(enterFrame){
   if(_parent.harea.hitTest(_root.plane.ha2))
   {
      _root.itemno = _root.itemno + 1;
      gotoAndStop(7);
   }
}
