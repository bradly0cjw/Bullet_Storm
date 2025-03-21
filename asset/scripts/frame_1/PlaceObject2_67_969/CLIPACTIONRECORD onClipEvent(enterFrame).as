onClipEvent(enterFrame){
   loaded = _root.getBytesLoaded();
   total = _root.getBytesTotal();
   bar._width = loaded / total * barwidth;
   _root.percent = Math.floor(loaded / total * 100) + "% COMPLETE";
   if(loaded < total)
   {
      _root.stop();
   }
   else
   {
      _root.gotoAndStop(4);
   }
}
