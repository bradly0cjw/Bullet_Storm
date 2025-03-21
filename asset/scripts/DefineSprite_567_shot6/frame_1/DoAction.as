tm = 0;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      tm++;
      if(tm >= 137)
      {
         this.removeMovieClip();
      }
   }
};
