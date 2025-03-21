if(_root.levelno == undefined)
{
   if(sc < 36)
   {
      gotoAndPlay(357);
   }
   else
   {
      gotoAndPlay(360);
   }
}
else
{
   stopAllSounds();
   if(_root.score == 0)
   {
      gotoAndStop(367);
   }
   else
   {
      gotoAndStop(366);
   }
}
