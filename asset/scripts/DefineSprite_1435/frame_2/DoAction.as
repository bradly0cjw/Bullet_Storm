_parent._x = _root.plane._x;
_parent._y = _root.plane._y;
_parent._rotation = _parent.rtt;
if(_root.lv1.planeArray.length > 4)
{
   if(_parent.hid == 1 || _parent.hid == 5)
   {
      targ = _root.lv1.planeArray[_root.plane.plane.hctrl.tg];
   }
   else if(_parent.hid == 2 || _parent.hid == 6)
   {
      targ = _root.lv1.planeArray[_root.plane.plane.hctrl.tg + 1];
   }
   else if(_parent.hid == 3 || _parent.hid == 7)
   {
      targ = _root.lv1.planeArray[_root.plane.plane.hctrl.tg + 2];
   }
   else
   {
      targ = _root.lv1.planeArray[_root.plane.plane.hctrl.tg + 3];
   }
}
else if(_root.lv1.planeArray.length == 4)
{
   if(_parent.hid == 1 || _parent.hid == 5)
   {
      targ = _root.lv1.planeArray[0];
   }
   else if(_parent.hid == 2 || _parent.hid == 6)
   {
      targ = _root.lv1.planeArray[1];
   }
   else if(_parent.hid == 3 || _parent.hid == 7)
   {
      targ = _root.lv1.planeArray[2];
   }
   else
   {
      targ = _root.lv1.planeArray[3];
   }
}
else
{
   targ = _root.lv1.planeArray[random(_root.lv1.planeArray.length)];
}
gotoAndPlay(3);
