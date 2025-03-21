onClipEvent(enterFrame){
   if(hitTest(_root.plane.ha2))
   {
      _root.score += 500;
      _root.medal1 = _root.medal1 + 1;
      _root.itemno = _root.itemno + 1;
      _parent.gotoAndPlay(2);
   }
}
