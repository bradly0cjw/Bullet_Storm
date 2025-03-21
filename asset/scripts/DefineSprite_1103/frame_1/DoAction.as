rota = Math.random() * 360;
_X = Math.random() * 90 - 45;
_Y = Math.random() * 90 - 45;
size = Math.random() * 4 + 4;
_width = size;
_height = size;
_alpha = 100;
ispeed = Math.random();
speed = Math.random() * 2 + 1;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      _X = _X + Math.sin(rota * 3.141592653589793 / 180) * speed;
      _Y = _Y + Math.cos(rota * 3.141592653589793 / 180) * speed;
      _width = _width + ispeed;
      _height = _height + ispeed;
      _alpha = _alpha - 10;
   }
};
