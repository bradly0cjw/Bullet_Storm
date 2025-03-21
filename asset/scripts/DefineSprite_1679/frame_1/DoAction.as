if(_root.levelno == 6)
{
   gotoAndStop(3);
}
else
{
   sc = 0;
   this.onEnterFrame = function()
   {
      if(_root.pause == 0)
      {
         sc++;
         if(sc > 15)
         {
            gotoAndStop(2);
         }
      }
   };
   stop();
}
