_X = Math.random() * 200 + 50;
_Y = Math.random() * 350;
speed = Math.random() * 2 + 1;
this.onEnterFrame = function()
{
   if(_root.pause == 0 && _root.el.ebonus.ct == undefined)
   {
      _Y = _Y + speed;
   }
   if(_Y >= 450)
   {
      gotoAndStop(random(5) + 2);
      speed = Math.random() * 2 + 1;
      _X = Math.random() * 200 + 50;
      _Y = -100;
   }
};
gotoAndStop(random(5) + 2);
