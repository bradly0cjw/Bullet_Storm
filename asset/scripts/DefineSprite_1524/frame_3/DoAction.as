sc = 0;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      sc++;
      if(sc > 105)
      {
         gotoAndStop(4);
      }
   }
};
stop();
