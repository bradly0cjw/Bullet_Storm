onClipEvent(enterFrame){
   if(_root.pause == 1)
   {
      _parent.stop();
   }
   else
   {
      _parent.play();
   }
}
