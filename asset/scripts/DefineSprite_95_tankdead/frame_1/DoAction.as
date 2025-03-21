this.onEnterFrame = function()
{
   if(_root.pause == 0 && _root.scroll == 1)
   {
      _Y = _Y + 0.8333333333333334;
   }
   if(_Y >= 372)
   {
      this.removeMovieClip();
   }
};
if(_X == 0)
{
   gotoAndStop(2);
}
else
{
   stop();
}
