if(_root.lv1.shotno < 12)
{
   _root.lv1.shotno = _root.lv1.shotno + 1;
   _parent.added = _parent.added + 1;
   stop();
}
else
{
   gotoAndStop(2);
}
