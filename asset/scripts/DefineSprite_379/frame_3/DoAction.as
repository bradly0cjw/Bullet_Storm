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
if(Key.isDown(37))
{
   gotoAndStop(5);
   _parent.prevFrame();
}
if(Key.isDown(39))
{
   gotoAndStop(5);
   _parent.nextFrame();
}
