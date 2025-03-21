onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      tm++;
      if(tm <= 15)
      {
         ySpeed *= 0.85;
         _parent._y -= ySpeed;
      }
      else
      {
         if(hitTest(_root.plane.ha2))
         {
            _root.fairyno = _root.fairyno + 1;
            _root.itemno = _root.itemno + 1;
            _parent.gotoAndPlay(3);
         }
         if(tm >= 1440 || _root.plane._currentframe >= 4)
         {
            fly();
            if(_parent._x < 0)
            {
               _parent.gotoAndStop(1);
            }
            else if(_parent._x > 300)
            {
               _parent.gotoAndStop(1);
            }
            else if(_parent._y < 0)
            {
               _parent.gotoAndStop(1);
            }
            else if(_parent._y > 350)
            {
               _parent.gotoAndStop(1);
            }
         }
         else
         {
            xdiff = _parent._x - _root.plane._x;
            ydiff = _root.plane._y - _parent._y;
            if(_root.plane._y < _parent._y)
            {
               _rotation = Math.atan(xdiff / ydiff) * 180 / 3.141592653589793;
            }
            else if(_root.plane._y > _parent._y)
            {
               _rotation = Math.atan(xdiff / ydiff) * 180 / 3.141592653589793 + 180;
            }
            else
            {
               _rotation = 180;
            }
            fly();
         }
      }
   }
}
