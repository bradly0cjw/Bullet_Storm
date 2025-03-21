onClipEvent(enterFrame){
   if(hitTest(_root.plane.ha2))
   {
      _root.itemno = _root.itemno + 1;
      gotoAndPlay(2);
   }
   if(_root.pause == 0 && _root.el.ebonus.ct == undefined)
   {
      _rotation = _rotation + 10;
   }
}
