if(Key.isDown(_root.shtopt))
{
   if(_root.shoot == 1)
   {
      if(_root.pause == 0)
      {
         if(_root.h1.hm._currentframe == 1)
         {
            if(_root.h2.hm._currentframe == 1)
            {
               if(_root.h3.hm._currentframe == 1)
               {
                  if(_root.h4.hm._currentframe == 1)
                  {
                     _root.h1.gotoAndStop(4);
                     _root.h1.rtt = 335;
                     _root.h2.gotoAndStop(4);
                     _root.h2.rtt = 25;
                     _root.h3.gotoAndStop(4);
                     _root.h3.rtt = 270;
                     _root.h4.gotoAndStop(4);
                     _root.h4.rtt = 90;
                     gotoAndPlay(3);
                  }
               }
            }
         }
      }
   }
}
