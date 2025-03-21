if(_Y < 200)
{
   if(_root.scroll == 1 && _root.pause == 0)
   {
      _Y = _Y + 0.8333333333333334;
   }
   gotoAndPlay(2);
}
else
{
   _Y = 200;
   fly.fly.gotoAndStop(2);
   gotoAndPlay(4);
}
