_parent._x = _root.plane._x;
_parent._y = _root.plane._y;
_parent._rotation = _parent.rtt;
if(_root.lv1.planeArray.length > 2)
{
   if(_parent.hid == 1)
   {
      targ = _root.lv1.planeArray[_root.plane.plane.hctrl.tg];
   }
   else
   {
      targ = _root.lv1.planeArray[_root.plane.plane.hctrl.tg + 1];
   }
}
else if(_root.lv1.planeArray.length == 2)
{
   if(_parent.hid == 1)
   {
      targ = _root.lv1.planeArray[0];
   }
   else
   {
      targ = _root.lv1.planeArray[1];
   }
}
else
{
   targ = _root.lv1.planeArray[0];
}
gotoAndPlay(3);
