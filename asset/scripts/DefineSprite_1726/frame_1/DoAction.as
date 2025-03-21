numb = _root.missionno;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      play();
   }
   else
   {
      stop();
   }
};
