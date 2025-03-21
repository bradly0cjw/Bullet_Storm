if(Key.isDown(_root.shtopt) && _root.shoot == 1 && _root.pause == 0 && _root.h1.hm._currentframe == 1 && _root.h2.hm._currentframe == 1 && _root.h3.hm._currentframe == 1 && _root.h4.hm._currentframe == 1)
{
   _root.h1.gotoAndStop(2);
   _root.h1.rtt = 335;
   _root.h2.gotoAndStop(2);
   _root.h2.rtt = 25;
   _root.h3.gotoAndStop(2);
   _root.h3.rtt = 315;
   _root.h4.gotoAndStop(2);
   _root.h4.rtt = 45;
   gotoAndPlay(3);
}
