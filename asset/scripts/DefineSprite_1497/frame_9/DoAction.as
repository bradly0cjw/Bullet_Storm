if(Key.isDown(_root.shtopt))
{
   if(_root.shoot == 1)
   {
      if(_root.pause == 0)
      {
         if(_root.h5.hm._currentframe == 1)
         {
            if(_root.h6.hm._currentframe == 1)
            {
               if(_root.h7.hm._currentframe == 1)
               {
                  if(_root.h8.hm._currentframe == 1)
                  {
                     _root.h5.gotoAndStop(4);
                     _root.h5.rtt = 335;
                     _root.h6.gotoAndStop(4);
                     _root.h6.rtt = 25;
                     _root.h7.gotoAndStop(4);
                     _root.h7.rtt = 270;
                     _root.h8.gotoAndStop(4);
                     _root.h8.rtt = 90;
                     gotoAndPlay(11);
                  }
               }
            }
         }
      }
   }
}
