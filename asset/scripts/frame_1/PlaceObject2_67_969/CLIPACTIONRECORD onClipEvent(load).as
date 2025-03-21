onClipEvent(load){
   barwidth = bar._width;
   loaded = _root.getBytesLoaded();
   total = _root.getBytesTotal();
   if(loaded >= total)
   {
      _root.gotoAndStop(4);
   }
   else
   {
      _root.stop();
   }
}
