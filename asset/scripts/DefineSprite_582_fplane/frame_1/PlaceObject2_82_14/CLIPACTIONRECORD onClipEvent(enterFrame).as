onClipEvent(enterFrame){
   if(_root.pause == 0 && _parent.gone == 0)
   {
      yspd += 0.1;
      _parent._x += _parent.dist / 45;
      _parent._y += yspd;
   }
}
