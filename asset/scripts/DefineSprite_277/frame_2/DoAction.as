_root.bbno += 1;
if(_root.bbno < 100)
{
   _root.score += _root.bbno * 1000;
}
else
{
   _root.score += 100000;
}
gotoAndStop(3);
