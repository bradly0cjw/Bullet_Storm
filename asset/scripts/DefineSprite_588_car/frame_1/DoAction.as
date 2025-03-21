adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
_X = 312;
_Y = 170;
gone = 0;
hp = _root.dif * 40;
win = 0;
bsound = new Sound();
bsound.attachSound("bonus");
stop();
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   var _loc2_ = this;
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
   }
   if(hp <= 0)
   {
      win = 1;
      gotoAndStop(2);
   }
   if(_loc1_.pause == 0)
   {
      _X = _X - 6;
      if(_X < -12)
      {
         gotoAndStop(2);
      }
      if(_loc1_.plane._currentframe > 14 && _loc1_.gameover._currentframe == 1)
      {
         rd = random(8);
         if(rd == 0)
         {
            hp -= 10;
            _loc1_.score += 10;
         }
      }
      if(_loc1_.gvc > 0)
      {
         if(hitTest(_loc1_.v1.vc))
         {
            _loc1_.v1.vc.vc.play();
            hp -= _loc1_.v1.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v1.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2.vc))
         {
            _loc1_.v2.vc.vc.play();
            hp -= _loc1_.v2.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3.vc))
         {
            _loc1_.v3.vc.vc.play();
            hp -= _loc1_.v3.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v1b.vc))
         {
            _loc1_.v1b.vc.vc.play();
            hp -= _loc1_.v1b.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v1b.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2b.vc))
         {
            _loc1_.v2b.vc.vc.play();
            hp -= _loc1_.v2b.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2b.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3b.vc))
         {
            _loc1_.v3b.vc.vc.play();
            hp -= _loc1_.v3b.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3b.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v1c.vc))
         {
            _loc1_.v1c.vc.vc.play();
            hp -= _loc1_.v1c.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v1c.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2c.vc))
         {
            _loc1_.v2c.vc.vc.play();
            hp -= _loc1_.v2c.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2c.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3c.vc))
         {
            _loc1_.v3c.vc.vc.play();
            hp -= _loc1_.v3c.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3c.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v1d.vc))
         {
            _loc1_.v1d.vc.vc.play();
            hp -= _loc1_.v1d.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v1d.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2d.vc))
         {
            _loc1_.v2d.vc.vc.play();
            hp -= _loc1_.v2d.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2d.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3d.vc))
         {
            _loc1_.v3d.vc.vc.play();
            hp -= _loc1_.v3d.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3d.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v1e.vc))
         {
            _loc1_.v1e.vc.vc.play();
            hp -= _loc1_.v1e.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v1e.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2e.vc))
         {
            _loc1_.v2e.vc.vc.play();
            hp -= _loc1_.v2e.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2e.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3e.vc))
         {
            _loc1_.v3e.vc.vc.play();
            hp -= _loc1_.v3e.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3e.vc.dm / 10) * 10 + 10;
         }
      }
      else if(_loc1_.gls > 0)
      {
         if(hitTest(_loc1_.l1.ls))
         {
            _loc1_.l1.ls.ls.play();
            hp -= _loc1_.l1.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l1.ls.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.l2.ls))
         {
            _loc1_.l2.ls.ls.play();
            hp -= _loc1_.l2.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l2.ls.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.l3.ls))
         {
            _loc1_.l3.ls.ls.play();
            hp -= _loc1_.l3.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l3.ls.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.l4.ls))
         {
            _loc1_.l4.ls.ls.play();
            hp -= _loc1_.l4.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l4.ls.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.l5.ls))
         {
            _loc1_.l5.ls.ls.play();
            hp -= _loc1_.l5.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l5.ls.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.l6.ls))
         {
            _loc1_.l6.ls.ls.play();
            hp -= _loc1_.l6.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l6.ls.dm / 10) * 10 + 10;
         }
      }
      else if(_loc1_.gps > 0)
      {
         if(hitTest(_loc1_.plaz.plazma))
         {
            assign = random(4);
            if(assign == 0)
            {
               _loc1_.plane.plane.pctrl.plz.ene1 = new Object();
               _loc1_.plane.plane.pctrl.plz.ene1 = _loc2_;
            }
            else if(assign == 1)
            {
               _loc1_.plane.plane.pctrl.plz.ene2 = new Object();
               _loc1_.plane.plane.pctrl.plz.ene2 = _loc2_;
            }
            else if(assign == 2)
            {
               _loc1_.plane.plane.pctrl.plz.ene3 = new Object();
               _loc1_.plane.plane.pctrl.plz.ene3 = _loc2_;
            }
            else if(assign == 3)
            {
               _loc1_.plane.plane.pctrl.plz.ene4 = new Object();
               _loc1_.plane.plane.pctrl.plz.ene4 = _loc2_;
            }
            hp -= _loc1_.plane.plane.pctrl.plz.dm;
            _loc1_.score += Math.round(Math.random() * Math.random() + 0.1) * 10;
         }
      }
      if(_loc1_.mnc > 0)
      {
         if(hitTest(_loc1_.n1.nc))
         {
            _loc1_.n1.nc.nc.play();
            hp -= _loc1_.n1.nc.dm;
            _loc1_.score += Math.ceil(_loc1_.n1.nc.dm / 10) * 10;
         }
         if(hitTest(_loc1_.n2.nc))
         {
            _loc1_.n2.nc.nc.play();
            hp -= _loc1_.n2.nc.dm;
            _loc1_.score += Math.ceil(_loc1_.n2.nc.dm / 10) * 10;
         }
      }
      else if(_loc1_.mhm > 0)
      {
         if(hitTest(_loc1_.h1.hm))
         {
            _loc1_.h1.hm.hm.play();
            hp -= _loc1_.h1.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h2.hm))
         {
            _loc1_.h2.hm.hm.play();
            hp -= _loc1_.h2.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h3.hm))
         {
            _loc1_.h3.hm.hm.play();
            hp -= _loc1_.h3.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h4.hm))
         {
            _loc1_.h4.hm.hm.play();
            hp -= _loc1_.h4.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h5.hm))
         {
            _loc1_.h5.hm.hm.play();
            hp -= _loc1_.h5.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h6.hm))
         {
            _loc1_.h6.hm.hm.play();
            hp -= _loc1_.h6.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h7.hm))
         {
            _loc1_.h7.hm.hm.play();
            hp -= _loc1_.h7.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h8.hm))
         {
            _loc1_.h8.hm.hm.play();
            hp -= _loc1_.h8.hm.dm;
            _loc1_.score += 10;
         }
      }
      if(hitTest(_loc1_.b1))
      {
         hp -= _loc1_.b1.dm;
         _loc1_.score += 10;
      }
      else if(hitTest(_loc1_.b2))
      {
         hp -= _loc1_.b2.dm;
         _loc1_.score += 10;
      }
      else if(hitTest(_loc1_.b3))
      {
         hp -= _loc1_.b3.dm;
         _loc1_.score += 10;
      }
   }
   if(_loc1_.pause == 0 && _loc1_.scroll == 1)
   {
      _Y = _Y + 0.8333333333333334;
   }
};
