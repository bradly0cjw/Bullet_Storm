_rotation = Math.random() * 360;
_width = Math.random() * 6;
_height = Math.random() * 6;
_alpha = random(26) + 75;
speed = Math.random() * 6 + 2;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      _X = _X + speed * Math.sin(_rotation * 3.141592653589793 / 180);
      _Y = _Y - speed * Math.cos(_rotation * 3.141592653589793 / 180);
   }
   if(_X < 0 || _X > 300 || _Y < 0 || _Y > 350)
   {
      this.removeMovieClip();
   }
};
gotoAndStop(lty);
