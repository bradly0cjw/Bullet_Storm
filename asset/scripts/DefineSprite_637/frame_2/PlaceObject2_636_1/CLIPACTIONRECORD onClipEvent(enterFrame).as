onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      _parent.play();
   }
   else
   {
      _parent.stop();
   }
}
