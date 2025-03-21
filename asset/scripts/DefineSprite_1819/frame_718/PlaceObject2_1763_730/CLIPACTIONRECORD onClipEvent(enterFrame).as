onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      _X = _X - 13.200000000000001;
   }
   if(_X <= bx)
   {
      _X = xp;
   }
}
