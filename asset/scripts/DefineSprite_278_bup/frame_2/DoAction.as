if(_root.pause == 0 && _root.el.ebonus.ct == undefined)
{
   if(_X < 0)
   {
      _X = 0;
      getrandom();
      rd = 0;
   }
   else if(_X > 300)
   {
      _X = 300;
      getrandom();
      rd = 1;
   }
   else
   {
      getdir();
   }
   if(_Y < 0)
   {
      _Y = 0;
      getrandom();
      rd2 = 0;
   }
   else if(_Y > 350)
   {
      _Y = 350;
      getrandom();
      rd2 = 1;
   }
   else
   {
      getdir();
   }
}
