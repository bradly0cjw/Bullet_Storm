function getrandom()
{
   rd = random(2);
   rd2 = random(2);
   xp = random(2) + 1;
}
function getdir()
{
   if(rd == 0)
   {
      _X = _X + xp;
   }
   else
   {
      _X = _X - xp;
   }
   if(rd2 == 0)
   {
      _Y = _Y + (3 - xp);
   }
   else
   {
      _Y = _Y - (3 - xp);
   }
}
sc = 0;
gotoAndPlay(2);
