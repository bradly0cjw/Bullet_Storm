i = 1;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      i++;
      if(i <= 50)
      {
         attachMovie("fire","fire" + i,i);
      }
   }
};
