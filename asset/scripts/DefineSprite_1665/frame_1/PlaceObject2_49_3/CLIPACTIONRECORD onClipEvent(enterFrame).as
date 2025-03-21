onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      if(released == 0 && !Key.isDown(17))
      {
         released = 1;
      }
      if(Key.isDown(17) && released == 1)
      {
         _parent.gotoAndStop(2);
      }
   }
}
