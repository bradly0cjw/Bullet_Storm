onClipEvent(enterFrame){
   if(!Key.isDown(13) && !Key.isDown(32) && !Key.isDown(8) && !Key.isDown(65) && !Key.isDown(66) && !Key.isDown(67) && !Key.isDown(68) && !Key.isDown(69) && !Key.isDown(70) && !Key.isDown(71) && !Key.isDown(72) && !Key.isDown(73) && !Key.isDown(74) && !Key.isDown(75) && !Key.isDown(76) && !Key.isDown(77) && !Key.isDown(78) && !Key.isDown(79) && !Key.isDown(80) && !Key.isDown(81) && !Key.isDown(82) && !Key.isDown(83) && !Key.isDown(84) && !Key.isDown(85) && !Key.isDown(86) && !Key.isDown(87) && !Key.isDown(88) && !Key.isDown(89) && !Key.isDown(90) && !Key.isDown(48) && !Key.isDown(49) && !Key.isDown(50) && !Key.isDown(51) && !Key.isDown(52) && !Key.isDown(53) && !Key.isDown(54) && !Key.isDown(55) && !Key.isDown(56) && !Key.isDown(57))
   {
      released = 1;
   }
   if(released == 1)
   {
      if(Key.isDown(8))
      {
         if(_parent._parent.lno == 3)
         {
            back.start(0,0);
            _parent._parent.letter2.gotoAndStop(1);
            _parent._parent.lno--;
         }
         else if(_parent._parent.lno == 4)
         {
            back.start(0,0);
            _parent._parent.letter3.gotoAndStop(1);
            _parent._parent.lno--;
         }
         else if(_parent._parent.lno == 5)
         {
            back.start(0,0);
            _parent._parent.letter4.gotoAndStop(1);
            _parent._parent.lno--;
         }
         else
         {
            _parent._parent.gotoAndStop(18);
         }
      }
      if(Key.isDown(65))
      {
         type.start(0,0);
         _parent.letter = "A";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(66))
      {
         type.start(0,0);
         _parent.letter = "B";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(67))
      {
         type.start(0,0);
         _parent.letter = "C";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(68))
      {
         type.start(0,0);
         _parent.letter = "D";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(69))
      {
         type.start(0,0);
         _parent.letter = "E";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(70))
      {
         type.start(0,0);
         _parent.letter = "F";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(71))
      {
         type.start(0,0);
         _parent.letter = "G";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(72))
      {
         type.start(0,0);
         _parent.letter = "H";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(73))
      {
         type.start(0,0);
         _parent.letter = "I";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(74))
      {
         type.start(0,0);
         _parent.letter = "J";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(75))
      {
         type.start(0,0);
         _parent.letter = "K";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(76))
      {
         type.start(0,0);
         _parent.letter = "L";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(77))
      {
         type.start(0,0);
         _parent.letter = "M";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(78))
      {
         type.start(0,0);
         _parent.letter = "N";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(79))
      {
         type.start(0,0);
         _parent.letter = "O";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(80))
      {
         type.start(0,0);
         _parent.letter = "P";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(81))
      {
         type.start(0,0);
         _parent.letter = "Q";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(82))
      {
         type.start(0,0);
         _parent.letter = "R";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(83))
      {
         type.start(0,0);
         _parent.letter = "S";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(84))
      {
         type.start(0,0);
         _parent.letter = "T";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(85))
      {
         type.start(0,0);
         _parent.letter = "U";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(86))
      {
         type.start(0,0);
         _parent.letter = "V";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(87))
      {
         type.start(0,0);
         _parent.letter = "W";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(88))
      {
         type.start(0,0);
         _parent.letter = "X";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(89))
      {
         type.start(0,0);
         _parent.letter = "Y";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(90))
      {
         type.start(0,0);
         _parent.letter = "Z";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(48))
      {
         type.start(0,0);
         _parent.letter = "0";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(49))
      {
         type.start(0,0);
         _parent.letter = "1";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(50))
      {
         type.start(0,0);
         _parent.letter = "2";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(51))
      {
         type.start(0,0);
         _parent.letter = "3";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(52))
      {
         type.start(0,0);
         _parent.letter = "4";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(53))
      {
         type.start(0,0);
         _parent.letter = "5";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(54))
      {
         type.start(0,0);
         _parent.letter = "6";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(55))
      {
         type.start(0,0);
         _parent.letter = "7";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(56))
      {
         type.start(0,0);
         _parent.letter = "8";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(57))
      {
         type.start(0,0);
         _parent.letter = "9";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(32))
      {
         type.start(0,0);
         _parent.letter = " ";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
      else if(Key.isDown(110))
      {
         type.start(0,0);
         _parent.letter = ".";
         _parent._parent.lno = _parent._parent.lno + 1;
      }
   }
}
