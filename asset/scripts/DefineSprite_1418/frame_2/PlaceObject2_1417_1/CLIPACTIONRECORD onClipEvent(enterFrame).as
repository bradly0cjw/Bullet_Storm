onClipEvent(enterFrame){
   if(_root.pause == 0 && _currentframe == 1)
   {
      _parent.velocity *= 1.5;
      _parent.velocity *= 0.75;
      _Y = _Y - _parent.velocity;
   }
   if(hitTest(_root.tborder))
   {
      _parent.gotoAndStop(1);
   }
}
