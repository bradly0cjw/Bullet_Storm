_root.credit--;
if(_root.credit < 0)
{
   _root.credit = 0;
   _root.gameover.gotoAndStop(2);
}
else
{
   _root.bbno = 3;
   _root.gvc = 1;
   _root.gls = 0;
   _root.gps = 0;
   _root.mnc = 0;
   _root.mhm = 0;
   gotoAndPlay(1);
}
