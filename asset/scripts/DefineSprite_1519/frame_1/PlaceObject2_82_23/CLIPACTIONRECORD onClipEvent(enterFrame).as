onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      _parent._y -= 7;
      if(_parent._y <= 256)
      {
         _parent.gotoAndStop(2);
      }
   }
}
