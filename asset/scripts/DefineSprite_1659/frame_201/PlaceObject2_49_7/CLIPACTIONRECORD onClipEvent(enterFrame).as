onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      sc += 0.027777777777777776;
      if(sc >= 30)
      {
         _parent.takeoff = 1;
      }
   }
}
