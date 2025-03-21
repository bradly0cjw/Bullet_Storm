onClipEvent(enterFrame){
   if(_root.bomb == 1 && _root.pause == 0 && _root.bbno > 0 && Key.isDown(_root.bbopt))
   {
      if(_root.gls > 0)
      {
         _root.b2.play();
      }
      else if(_root.gps > 0)
      {
         _root.b3.play();
      }
      else
      {
         _root.b1.play();
      }
   }
}
