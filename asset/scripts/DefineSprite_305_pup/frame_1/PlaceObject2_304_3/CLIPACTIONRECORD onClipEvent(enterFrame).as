onClipEvent(enterFrame){
   if(hitTest(_root.plane.ha2))
   {
      _root.itemno = _root.itemno + 1;
      if(_root.gvc > 0)
      {
         if(_root.gvc == 8)
         {
            if(_root.mnc == 4 || _root.mhm == 4)
            {
               gotoAndStop(8);
            }
            else if(_root.mnc == 0 && _root.mhm == 0)
            {
               gotoAndStop(8);
            }
         }
         else
         {
            _root.gvc = 8;
            _root.score += 500;
            gotoAndStop(7);
         }
      }
      else if(_root.gls > 0)
      {
         if(_root.gls == 8)
         {
            if(_root.mnc == 4 || _root.mhm == 4)
            {
               gotoAndStop(8);
            }
            else if(_root.mnc == 0 && _root.mhm == 0)
            {
               gotoAndStop(8);
            }
         }
         else
         {
            _root.gls = 8;
            _root.score += 500;
            gotoAndStop(7);
         }
      }
      else if(_root.gps == 8)
      {
         if(_root.mnc == 4 || _root.mhm == 4)
         {
            gotoAndStop(8);
         }
         else if(_root.mnc == 0 && _root.mhm == 0)
         {
            gotoAndStop(8);
         }
      }
      else
      {
         _root.gps = 8;
         _root.score += 500;
         gotoAndStop(7);
      }
      if(_root.mnc > 0)
      {
         _root.mnc = 4;
         _root.score += 500;
      }
      else if(_root.mhm > 0)
      {
         _root.score += 500;
         _root.mhm = 4;
      }
   }
}
