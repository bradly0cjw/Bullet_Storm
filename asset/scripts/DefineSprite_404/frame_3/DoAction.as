if(Key.isDown(32) || Key.isDown(13))
{
   if(_parent.opt == 1)
   {
      gotoAndStop(6);
   }
   else
   {
      gotoAndStop(7);
   }
   _parent.confirm();
}
if(Key.isDown(38))
{
   gotoAndStop(5);
   _parent.prevFrame();
}
if(Key.isDown(40))
{
   gotoAndStop(5);
   _parent.nextFrame();
}
if(Key.isDown(37) && _parent._currentframe >= 8)
{
   gotoAndStop(5);
   _parent.gotoAndStop(_parent._currentframe - 3);
}
if(Key.isDown(39) && _parent._currentframe <= 7)
{
   gotoAndStop(5);
   _parent.gotoAndStop(_parent._currentframe + 3);
}
