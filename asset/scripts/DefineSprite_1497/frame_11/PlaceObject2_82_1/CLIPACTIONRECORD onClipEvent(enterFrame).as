onClipEvent(enterFrame){
   if(_root.pause == 1)
   {
      _parent.stop();
   }
   else
   {
      if(_root.h1.hm._currentframe == 1)
      {
         if(_root.h2.hm._currentframe == 1)
         {
            if(_root.h3.hm._currentframe == 1)
            {
               if(_root.h4.hm._currentframe == 1)
               {
                  _parent._currentframe += 2;
               }
            }
         }
      }
      _parent.play();
   }
}
