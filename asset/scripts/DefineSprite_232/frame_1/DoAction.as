if(_root.lv1.shotno < 16)
{
   _root.lv1.shotno += 0.5;
   _parent.added += 0.5;
   stop();
}
else
{
   gotoAndStop(2);
}
