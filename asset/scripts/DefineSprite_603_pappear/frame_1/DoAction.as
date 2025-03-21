xspd = 16;
yspd = 16;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      play();
      xspd *= 0.92;
      yspd *= 0.92;
      _X = _X + xspd * Math.sin(rota * 3.141592653589793 / 180);
      _Y = _Y - yspd * Math.cos(rota * 3.141592653589793 / 180);
   }
   else
   {
      stop();
   }
};
