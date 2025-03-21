sc = 0;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      sc++;
      if(sc > 15)
      {
         gotoAndStop(3);
      }
   }
};
stop();
