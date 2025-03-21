if(Key.isDown(_root.shtopt) && _root.shoot == 1 && _root.pause == 0 && _root.h1.hm._currentframe == 1 && _root.h2.hm._currentframe == 1)
{
   _root.h1.gotoAndStop(1);
   _root.h2.gotoAndStop(1);
   _root.h1.rtt = 335;
   _root.h2.rtt = 25;
   gotoAndPlay(3);
}
