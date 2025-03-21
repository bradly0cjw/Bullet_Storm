spd = 1;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      spd *= 1.3;
      _Y = _Y - spd;
   }
   if(_Y < -9)
   {
      this.removeMovieClip();
   }
};
