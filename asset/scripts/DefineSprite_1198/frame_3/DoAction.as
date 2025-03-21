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
   _parent.prevFrame();
   gotoAndStop(5);
}
if(Key.isDown(40))
{
   _parent.nextFrame();
   gotoAndStop(5);
}
if(Key.isDown(37) && _parent._currentframe >= 9)
{
   gotoAndStop(5);
   _parent.gotoAndStop(_parent._currentframe - 3);
}
if(Key.isDown(39) && _parent._currentframe <= 8)
{
   gotoAndStop(5);
   _parent.gotoAndStop(_parent._currentframe + 3);
}
