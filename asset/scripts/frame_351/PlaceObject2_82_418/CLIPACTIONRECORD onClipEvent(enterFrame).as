onClipEvent(enterFrame){
   _parent.play();
   _root._x = 0;
   _root._y = 0;
   if(started == undefined)
   {
      _quality = "MEDIUM";
   }
   else
   {
      _quality = "BEST";
   }
}
