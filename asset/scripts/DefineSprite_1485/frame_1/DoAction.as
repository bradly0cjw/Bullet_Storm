if(Key.isDown(_root.shtopt) && _root.shoot == 1 && _root.pause == 0)
{
   if(_root.v1.vc._currentframe == 1)
   {
      _root.v1.gotoAndStop(1);
      _root.v1.vc.play();
      gotoAndPlay(3);
   }
   else if(_root.v2.vc._currentframe == 1)
   {
      _root.v2.gotoAndStop(1);
      _root.v2.vc.play();
      gotoAndPlay(3);
   }
   else if(_root.v3.vc._currentframe == 1)
   {
      _root.v3.gotoAndStop(1);
      _root.v3.vc.play();
      gotoAndPlay(3);
   }
}
