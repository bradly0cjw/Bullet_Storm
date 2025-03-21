onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      _Y = _Y - 20;
   }
   if(hitTest(_root.tborder))
   {
      _parent.gotoAndStop(1);
   }
   else if(hitTest(_root.lborder))
   {
      _parent.gotoAndStop(1);
   }
   else if(hitTest(_root.rborder))
   {
      _parent.gotoAndStop(1);
   }
}
