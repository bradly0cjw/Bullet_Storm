_root.ctrl = 0;
_root.shoot = 0;
_root.bomb = 0;
_root.plane._x = 150;
_root.plane._y = 315;
_root.plane.gotoAndStop(3);
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      play();
   }
   else
   {
      stop();
   }
};
