onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      _X = _X - 20;
   }
   if(_X <= bx)
   {
      _X = xp;
   }
}
