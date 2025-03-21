onClipEvent(enterFrame){
   _X = _parent.fly.fly._x;
   _rotation = _parent.fly.fly._rotation;
   if(_root.pause == 0)
   {
      _parent.play();
   }
   else
   {
      _parent.stop();
   }
}
