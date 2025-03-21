onClipEvent(enterFrame){
   if(hitTest(_root.plane.ha2))
   {
      _root.itemno = _root.itemno + 1;
      if(_root.mhm > 0)
      {
         if(_root.mhm == 4)
         {
            _parent.gotoAndStop(244);
         }
         else
         {
            _root.mhm += 1;
         }
      }
      else if(_root.mnc > 0)
      {
         _root.mhm = _root.mnc;
         _root.mnc = 0;
      }
      else
      {
         _root.mhm = 1;
      }
      _parent.gotoAndStop(243);
   }
}
