this.onEnterFrame = function()
{
   if(_root.pause == 0 && _root.el.ebonus.ct == undefined)
   {
      play();
   }
   else
   {
      stop();
   }
};
