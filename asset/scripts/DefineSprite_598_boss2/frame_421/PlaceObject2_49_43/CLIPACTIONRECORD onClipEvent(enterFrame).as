onClipEvent(enterFrame){
   if(_root.pause == 0 && _parent.gone == 0)
   {
      if(dir == 0)
      {
         _parent.fly._x -= 0.5;
      }
      else
      {
         _parent.fly._x += 0.5;
      }
      if(_parent.fly._x > 45)
      {
         _parent.fly._x = 45;
         dir = 0;
      }
      else if(_parent.fly._x < -45)
      {
         _parent.fly._x = -45;
         dir = 1;
      }
   }
}
