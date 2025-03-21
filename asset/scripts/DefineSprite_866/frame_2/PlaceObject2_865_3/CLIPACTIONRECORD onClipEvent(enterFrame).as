onClipEvent(enterFrame){
   _rotation = _parent.fly._rotation;
   if(_root.pause == 0)
   {
      _parent.play();
   }
   else
   {
      _parent.stop();
   }
}
