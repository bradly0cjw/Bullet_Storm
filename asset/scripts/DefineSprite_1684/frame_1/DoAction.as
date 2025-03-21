_X = Math.random() * 250 + 25;
speed = Math.random() * 3 + 1;
size = Math.random() * 3 + 1;
_Y = - size;
_width = size;
_height = size;
_alpha = Math.random() * 70 + 10;
this.onEnterFrame = function()
{
   if(_root.pause == 0 && _root.el.ebonus.ct == undefined)
   {
      _Y = _Y + speed;
   }
   if(_Y >= 365)
   {
      speed = Math.random() * 3 + 1;
      size = Math.random() * 3 + 1;
      _width = size;
      _height = size;
      _alpha = Math.random() * 70 + 10;
      _X = Math.random() * 250 + 25;
      _Y = - size;
   }
};
gotoAndStop(2);
