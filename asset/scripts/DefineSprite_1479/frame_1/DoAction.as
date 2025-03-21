if(Key.isDown(_root.shtopt) && _root.shoot == 1 && _root.pause == 0)
{
   if(_root.l1.ls._currentframe == 1 && _root.l2.ls._currentframe == 1 && _root.l3.ls._currentframe == 1 && _root.l4.ls._currentframe == 1)
   {
      _root.l1.gotoAndStop(3);
      _root.l2.gotoAndStop(3);
      _root.l3.gotoAndStop(3);
      _root.l4.gotoAndStop(3);
      gotoAndPlay(3);
   }
}
