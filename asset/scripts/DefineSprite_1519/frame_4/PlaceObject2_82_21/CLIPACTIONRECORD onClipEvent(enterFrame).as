onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      sc++;
   }
   if(sc >= 90)
   {
      _parent.gotoAndStop(16);
   }
}
