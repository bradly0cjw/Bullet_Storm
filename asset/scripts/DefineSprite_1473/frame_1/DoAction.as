_root.plaz.plazma._y = -3000;
_root.plaz.plazma2._y = -3000;
_root.plaz.plazma3._y = -3000;
_root.lightning.gotoAndStop(1);
_root.elec.gotoAndStop(1);
this.onEnterFrame = function()
{
   gotoAndStop(_root.gps + 1);
};
