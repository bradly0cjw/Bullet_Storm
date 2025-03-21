sc = 0;
delete _root.plane.chinv;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      sc++;
      if(sc > 105)
      {
         gotoAndStop(3);
      }
   }
};
stop();
