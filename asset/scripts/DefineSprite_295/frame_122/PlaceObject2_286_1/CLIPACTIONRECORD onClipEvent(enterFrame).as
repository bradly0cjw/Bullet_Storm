onClipEvent(enterFrame){
   if(hitTest(_root.plane.ha2))
   {
      _root.itemno = _root.itemno + 1;
      if(_root.gls > 0)
      {
         if(_root.gls == 8)
         {
            _parent.s4.start(0,0);
            _parent.gotoAndStop(364);
         }
         else
         {
            _parent.s2.start(0,0);
            _root.gls += 1;
         }
      }
      else if(_root.gps > 0)
      {
         _parent.s2.start(0,0);
         _root.gls = _root.gps;
         _root.gps = 0;
      }
      else
      {
         _parent.s2.start(0,0);
         _root.gls = _root.gvc;
         _root.gvc = 0;
      }
      _parent.gotoAndStop(363);
   }
}
