onClipEvent(enterFrame){
   if(_parent.dd == 1)
   {
      if(_root.fairyno > 0)
      {
         _root.fairy2._x = _parent._x;
         _root.fairy2._y = _parent._y;
         _root.fairy2.play();
      }
      _parent.gotoAndPlay(4);
   }
}
