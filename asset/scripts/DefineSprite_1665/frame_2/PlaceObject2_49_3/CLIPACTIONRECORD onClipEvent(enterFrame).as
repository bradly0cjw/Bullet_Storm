onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      if(released == 0 && !Key.isDown(17))
      {
         released = 1;
      }
      if(_parent.code == "go0gleypower")
      {
         _parent.gotoAndStop(3);
      }
      if(Key.isDown(17) && released == 1)
      {
         _parent.gotoAndStop(1);
      }
   }
   else
   {
      _parent.gotoAndStop(1);
   }
}
