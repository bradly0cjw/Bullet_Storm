_root.el.ebonus.removeMovieClip();
_root.pau = 1;
_root.pause = 0;
_root.plane._x = 150;
_root.plane._y = 250;
_root.plane.gotoAndStop(3);
if(_root.level5back.bground.present == undefined)
{
   _root.level5back.attachMovie("bglevel5b","bground",0);
}
_root.level5back.bground.gotoAndStop(2);
if(_root.sctrl3._currentframe == 1)
{
   _root.sctrl3.gotoAndPlay(2);
}
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   _loc1_.ctrl = 0;
   _loc1_.shoot = 0;
   _loc1_.bomb = 0;
   if(_loc1_.pause == 0)
   {
      _quality = "MEDIUM";
   }
   gotoAndStop(Math.floor(_loc1_.sctrl3.bgMusic.position / _loc1_.sctrl3.bgMusic.duration * 1485) + 1);
};
