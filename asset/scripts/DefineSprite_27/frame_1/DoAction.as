_X = Math.random() * 250 + 25;
_Y = Math.random() * 450 - 100;
speed = Math.random() * 9 + 1;
size = Math.random() * 5 + 1;
_width = size;
_height = size;
_alpha = Math.random() * 70 + 10;
this.onEnterFrame = function()
{
   _Y = _Y + speed;
   if(_Y >= 365)
   {
      speed = Math.random() * 9 + 1;
      size = Math.random() * 5 + 1;
      _width = size;
      _height = size;
      _alpha = Math.random() * 70 + 10;
      _X = Math.random() * 250 + 25;
      _Y = - size;
   }
};
gotoAndStop(2);
