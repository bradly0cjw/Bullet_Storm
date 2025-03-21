if(bonus >= 1000)
{
   bonus -= 1000;
   _root.score += 1000;
   v4 = bonus + " pts";
}
else
{
   bonus = 0;
   v4 = "0 pts";
   gotoAndPlay(227);
}
