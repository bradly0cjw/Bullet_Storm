onClipEvent(enterFrame){
   if(_root.pause == 1)
   {
      _parent.stop();
   }
   else
   {
      if(_root.h5.hm._currentframe == 1)
      {
         if(_root.h6.hm._currentframe == 1)
         {
            if(_root.h7.hm._currentframe == 1)
            {
               if(_root.h8.hm._currentframe == 1)
               {
                  _parent._currentframe += 2;
               }
            }
         }
      }
      _parent.play();
   }
}
