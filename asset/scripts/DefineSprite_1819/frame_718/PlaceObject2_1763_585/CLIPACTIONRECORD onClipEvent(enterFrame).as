onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      _X = _X - 20 * Math.pow(0.8,pwr);
   }
   if(_X <= bx)
   {
      _X = xp;
   }
}
