this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      _Y--;
      _alpha--;
      if(_alpha <= 0)
      {
         this.removeMovieClip();
      }
   }
};
gotoAndStop(combono);
