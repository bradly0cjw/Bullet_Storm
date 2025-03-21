onClipEvent(enterFrame){
   if(hitTest(_root.bborder) && _parent.gone == 0)
   {
      _parent.gotoAndStop(92);
   }
}
