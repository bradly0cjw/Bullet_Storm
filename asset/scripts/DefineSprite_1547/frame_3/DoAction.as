if(Key.isDown(32) || Key.isDown(13))
{
   gotoAndStop(1);
   _parent.confirm();
}
if(Key.isDown(38))
{
   gotoAndStop(5);
}
if(Key.isDown(40))
{
   gotoAndStop(5);
   _parent.nextFrame();
}
