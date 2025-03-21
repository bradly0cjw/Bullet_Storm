this.onEnterFrame = function()
{
   if(_root.manim.bgready == 1)
   {
      gotoAndStop(2);
      if(_root.pause == 0)
      {
         if(_Y < -450)
         {
            _Y = _Y + 5;
         }
         else
         {
            _Y = -1250;
         }
      }
   }
   else
   {
      gotoAndStop(1);
   }
};
