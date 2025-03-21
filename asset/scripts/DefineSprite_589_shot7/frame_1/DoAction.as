added = 0;
tm = 0;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      tm++;
      if(tm >= 137)
      {
         _root.lv1.shotno -= added;
         this.removeMovieClip();
      }
   }
};
