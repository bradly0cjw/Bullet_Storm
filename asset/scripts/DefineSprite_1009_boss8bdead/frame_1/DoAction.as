this.onEnterFrame = function()
{
   if(_root.pause == 0 && _root.scroll == 1)
   {
      _Y = _Y + 2;
   }
   if(_Y >= 389)
   {
      this.removeMovieClip();
   }
};
