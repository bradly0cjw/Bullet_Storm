function upd()
{
   tempArray = new Array();
   i = 0;
   while(i < planeArray.length)
   {
      if(planeArray[i] != null)
      {
         newNdx = tempArray.length;
         tempArray[newNdx] = planeArray[i];
         tempArray[newNdx].adt = newNdx;
      }
      i++;
   }
   planeArray = new Array();
   for(ndx in tempArray)
   {
      planeArray[ndx] = tempArray[ndx];
   }
}
planeArray = new Array();
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   if(_loc1_.pause == 0 && _loc1_.pau == 1)
   {
      _quality = _loc1_.qual;
   }
};
_root.ctrl = 1;
_root.shoot = 1;
_root.bomb = 1;
_root.pause = 0;
_root.scroll = 1;
_root.pau = 1;
_root.medal1 = 0;
_root.medal2 = 0;
shotno = 0;
_root.sctrl2.gotoAndStop(1);
bossdead = 0;
gotoAndStop(2);
