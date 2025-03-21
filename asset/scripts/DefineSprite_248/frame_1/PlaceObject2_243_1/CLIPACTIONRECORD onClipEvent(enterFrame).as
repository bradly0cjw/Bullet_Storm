onClipEvent(enterFrame){
   if(hitTest(_root.plane.ha2))
   {
      _root.score += 3000;
      _root.medal2 = _root.medal2 + 1;
      _root.itemno = _root.itemno + 1;
      _parent.gotoAndPlay(2);
   }
}
