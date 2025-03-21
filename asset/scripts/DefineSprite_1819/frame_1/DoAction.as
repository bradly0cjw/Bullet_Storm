_root.pau = 1;
_root.pause = 0;
_root.plane._x = 150;
_root.plane._y = 250;
_root.plane.gotoAndStop(3);
bgready = 0;
bonusadded = 0;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   gotoAndStop(Math.floor(_loc1_.sctrl.bgMusic.position / _loc1_.sctrl.bgMusic.duration * 1427));
   _loc1_.ctrl = 0;
   _loc1_.shoot = 0;
   _loc1_.bomb = 0;
   if(_loc1_.pause == 0)
   {
      _quality = "MEDIUM";
   }
};
_root.galaxybg.gotoAndStop(1);
