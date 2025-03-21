onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      _Y = _Y - 18;
   }
   if(hitTest(_root.tborder))
   {
      _parent.gotoAndStop(1);
   }
}
