onClipEvent(enterFrame){
   if(hitTest(_root.plane.ha2))
   {
      _root.score += 25000;
      _root.itemno = _root.itemno + 1;
      _parent.gotoAndPlay(2);
   }
}
