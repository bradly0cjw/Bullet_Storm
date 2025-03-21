adt = _root.eArray.length;
_root.eArray[adt] = this;
_width = (random(3) + 1) * 13;
_height = 0.7384615384615385 * _width;
_X = Math.random() * 200 + 50;
_Y = - _height;
xspd = Math.random() * 4 - 2;
yspd = Math.random() * 4 + 1;
hp = _width / 13;
gone = 0;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   xp = _X;
   yp = _Y;
   _X = _X + xspd;
   _Y = _Y + yspd;
   if(gone == 0)
   {
      if(hitTest(_loc1_.gun1))
      {
         _loc1_.gun1.gun.play();
         play();
         hp -= 3;
      }
      if(hitTest(_loc1_.gun2))
      {
         _loc1_.gun2.gun.play();
         play();
         hp -= 3;
      }
      if(hitTest(_loc1_.gun3))
      {
         _loc1_.gun3.gun.play();
         play();
         hp -= 3;
      }
      if(hitTest(_loc1_.gun4))
      {
         _loc1_.gun3.gun.play();
         play();
         hp -= 3;
      }
      if(hitTest(_loc1_.gun5))
      {
         _loc1_.gun3.gun.play();
         play();
         hp -= 3;
      }
      if(hitTest(_loc1_.gun6))
      {
         _loc1_.gun3.gun.play();
         play();
         hp -= 3;
      }
      if(hitTest(_loc1_.h1))
      {
         _loc1_.h1.hm.play();
         play();
         hp--;
      }
      if(hitTest(_loc1_.h2))
      {
         _loc1_.h2.hm.play();
         play();
         hp--;
      }
      if(hitTest(_loc1_.h3))
      {
         _loc1_.h3.hm.play();
         play();
         hp--;
      }
      if(hitTest(_loc1_.h4))
      {
         _loc1_.h4.hm.play();
         play();
         hp--;
      }
      if(hp <= 0)
      {
         gotoAndPlay(6);
      }
   }
   if(_X < -30 || _X > 330 || _Y > 390)
   {
      if(gone == 0)
      {
         _loc1_.lv1.planeArray[adt] = null;
         _loc1_.lv1.upd();
      }
      gotoAndStop(1);
   }
   if(hp <= 0 && _currentframe < 6)
   {
      gotoAndPlay(6);
   }
};
gotoAndStop(2);
