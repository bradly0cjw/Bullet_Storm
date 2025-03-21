if(Key.isDown(_root.shtopt) && _root.shoot == 1 && _root.pause == 0)
{
   if(_root.n1.nc._currentframe == 1)
   {
      _root.n1.gotoAndStop(2);
      _root.n1.nc.play();
      gotoAndPlay(3);
   }
   else if(_root.n2.nc._currentframe == 1)
   {
      _root.n2.gotoAndStop(2);
      _root.n2.nc.play();
      gotoAndPlay(3);
   }
}
