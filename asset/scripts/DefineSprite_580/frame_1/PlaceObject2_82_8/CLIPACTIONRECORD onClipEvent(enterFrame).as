onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      if(hitTest(_root.b1))
      {
         _parent._parent.play();
      }
      else if(hitTest(_root.b2))
      {
         _parent._parent.play();
      }
      else if(hitTest(_root.b3))
      {
         _parent._parent.play();
      }
      if(hitTest(_root.plane.ha))
      {
         _parent._parent.play();
         _root.plane.dd = 1;
      }
   }
}
