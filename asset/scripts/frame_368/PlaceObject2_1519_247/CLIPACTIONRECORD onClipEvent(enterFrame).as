onClipEvent(enterFrame){
   if(_root.ctrl == 1 && _root.pause == 0)
   {
      if(Key.isDown(37))
      {
         _X = _X - steer;
      }
      if(Key.isDown(39))
      {
         _X = _X + steer;
      }
      if(Key.isDown(38))
      {
         _Y = _Y - steer;
      }
      if(Key.isDown(40))
      {
         _Y = _Y + steer;
      }
      if(_Y < 48)
      {
         _Y = 48;
      }
      if(_Y > 340)
      {
         _Y = 340;
      }
      if(_X < 15)
      {
         _X = 15;
      }
      if(_X > 285)
      {
         _X = 285;
      }
   }
}
