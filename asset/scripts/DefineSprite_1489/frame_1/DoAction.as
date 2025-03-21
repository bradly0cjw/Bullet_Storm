if(Key.isDown(_root.shtopt) && _root.shoot == 1 && _root.pause == 0)
{
   if(_root.v1.vc._currentframe == 1 && _root.v1b.vc._currentframe == 1 && _root.v1c.vc._currentframe == 1)
   {
      _root.v1.gotoAndStop(2);
      _root.v1b.gotoAndStop(2);
      _root.v1c.gotoAndStop(2);
      _root.v1.vc.play();
      _root.v1b.vc.play();
      _root.v1c.vc.play();
      gotoAndPlay(3);
   }
   else if(_root.v2.vc._currentframe == 1 && _root.v2b.vc._currentframe == 1 && _root.v2c.vc._currentframe == 1)
   {
      _root.v2.gotoAndStop(2);
      _root.v2b.gotoAndStop(2);
      _root.v2c.gotoAndStop(2);
      _root.v2.vc.play();
      _root.v2b.vc.play();
      _root.v2c.vc.play();
      gotoAndPlay(3);
   }
   else if(_root.v3.vc._currentframe == 1 && _root.v3b.vc._currentframe == 1 && _root.v3c.vc._currentframe == 1)
   {
      _root.v3.gotoAndStop(2);
      _root.v3b.gotoAndStop(2);
      _root.v3c.gotoAndStop(2);
      _root.v3.vc.play();
      _root.v3b.vc.play();
      _root.v3c.vc.play();
      gotoAndPlay(3);
   }
}
