if(Key.isDown(_root.shtopt) && _root.shoot == 1 && _root.pause == 0)
{
   if(_root.l1.ls._currentframe == 1 && _root.l2.ls._currentframe == 1 && _root.l3.ls._currentframe == 1 && _root.l4.ls._currentframe == 1 && _root.l5.ls._currentframe == 1 && _root.l6.ls._currentframe == 1)
   {
      _root.l1.gotoAndStop(4);
      _root.l2.gotoAndStop(4);
      _root.l3.gotoAndStop(4);
      _root.l4.gotoAndStop(4);
      _root.l5.gotoAndStop(4);
      _root.l6.gotoAndStop(4);
      gotoAndPlay(3);
   }
}
