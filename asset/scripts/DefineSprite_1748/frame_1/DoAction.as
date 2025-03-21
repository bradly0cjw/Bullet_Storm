bonus = _root.missionno * 1000000;
tbonus = bonus + " pts";
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
