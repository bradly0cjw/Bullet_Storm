onClipEvent(enterFrame){
   _Y = _Y - 20;
   if(_Y + _parent._y < -42)
   {
      _parent.gotoAndStop(1);
   }
}
