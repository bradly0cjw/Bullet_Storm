onClipEvent(enterFrame){
   if(_parent.lno == 1)
   {
      _parent.letter2.gotoAndStop(2);
      _parent.letter3.gotoAndStop(2);
      _parent.letter4.gotoAndStop(2);
      _parent.letter5.gotoAndStop(2);
      _parent.letter1.gotoAndStop(3);
   }
   else if(_parent.lno == 2)
   {
      _parent.letter1.gotoAndStop(2);
      _parent.letter3.gotoAndStop(2);
      _parent.letter4.gotoAndStop(2);
      _parent.letter5.gotoAndStop(2);
      _parent.letter2.gotoAndStop(3);
   }
   else if(_parent.lno == 3)
   {
      _parent.letter1.gotoAndStop(2);
      _parent.letter2.gotoAndStop(2);
      _parent.letter4.gotoAndStop(2);
      _parent.letter5.gotoAndStop(2);
      _parent.letter3.gotoAndStop(3);
   }
   else if(_parent.lno == 4)
   {
      _parent.letter1.gotoAndStop(2);
      _parent.letter2.gotoAndStop(2);
      _parent.letter3.gotoAndStop(2);
      _parent.letter5.gotoAndStop(2);
      _parent.letter4.gotoAndStop(3);
   }
   else if(_parent.lno == 5)
   {
      _parent.letter1.gotoAndStop(2);
      _parent.letter2.gotoAndStop(2);
      _parent.letter3.gotoAndStop(2);
      _parent.letter4.gotoAndStop(2);
      _parent.letter5.gotoAndStop(3);
   }
   else
   {
      _parent.letter1.gotoAndStop(2);
      _parent.letter2.gotoAndStop(2);
      _parent.letter3.gotoAndStop(2);
      _parent.letter4.gotoAndStop(2);
      _parent.letter5.gotoAndStop(2);
      if(Key.isDown(8))
      {
         back.start(0,0);
         _parent.letter5.gotoAndStop(1);
         _parent.lno = 5;
      }
   }
   if(rel == 0)
   {
      if(!Key.isDown(13))
      {
         rel = 1;
      }
   }
   if(rel == 1 && Key.isDown(13))
   {
      _parent.confirm();
   }
}
