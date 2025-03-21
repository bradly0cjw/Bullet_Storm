turning = 0;
this.onEnterFrame = function()
{
   var _loc1_ = _root;
   var _loc2_ = _parent;
   if(_loc1_.pause == 0)
   {
      if(_loc1_.plane._currentframe > 14)
      {
         targetVectorX = 0;
         targetVectorY = _loc2_._parent._parent.yp - 400;
         if(_loc1_.gameover._currentframe == 1)
         {
            rd = random(8);
            if(rd == 0)
            {
               _loc2_.play();
               _loc2_._parent.hp -= 10;
               _loc1_.score += 10;
            }
         }
      }
      else
      {
         targetVectorX = _loc1_.plane._x - _loc2_._parent._parent.xp;
         targetVectorY = _loc2_._parent._parent.yp - _loc1_.plane._y;
      }
      hypVector = Math.sqrt(targetVectorX * targetVectorX + targetVectorY * targetVectorY);
      targetThetaX = Math.asin(targetVectorX / hypVector) / 0.017453292519943295;
      targetThetaY = Math.acos(targetVectorY / hypVector) / 0.017453292519943295;
      if(targetVectorY < 0)
      {
         targetTheta = 180 - targetThetaX;
      }
      else
      {
         targetTheta = targetThetaX;
      }
      if(Math.abs(targetTheta - _loc2_._parent._parent.rota) < 10 || Math.abs(targetTheta - _loc2_._parent._parent.rota) > 350)
      {
         _loc2_._parent._parent.rota = targetTheta;
         turning = 0;
      }
      if(_loc2_._parent._parent.rota < targetTheta)
      {
         if(turning < 5)
         {
            turning++;
         }
      }
      else if(_loc2_._parent._parent.rota > targetTheta)
      {
         if(turning > -5)
         {
            turning--;
         }
      }
      _loc2_._parent._parent.rota += turning;
      if(_loc1_.gvc > 0)
      {
         if(hitTest(_loc1_.v1.vc))
         {
            _loc1_.v1.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v1.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v1.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2.vc))
         {
            _loc1_.v2.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v2.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3.vc))
         {
            _loc1_.v3.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v3.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v1b.vc))
         {
            _loc1_.v1b.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v1b.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v1b.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2b.vc))
         {
            _loc1_.v2b.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v2b.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2b.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3b.vc))
         {
            _loc1_.v3b.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v3b.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3b.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v1c.vc))
         {
            _loc1_.v1c.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v1c.vc.dm;
            _loc1_.score += Math.ceil(_loc1_.v1c.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2c.vc))
         {
            _loc1_.v2c.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v2c.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2c.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3c.vc))
         {
            _loc1_.v3c.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v3c.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3c.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v1d.vc))
         {
            _loc1_.v1d.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v1d.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v1d.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2d.vc))
         {
            _loc1_.v2d.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v2d.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2d.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3d.vc))
         {
            _loc1_.v3d.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v3d.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3d.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v1e.vc))
         {
            _loc1_.v1e.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v1e.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v1e.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v2e.vc))
         {
            _loc1_.v2e.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v2e.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v2e.vc.dm / 10) * 10 + 10;
         }
         if(hitTest(_loc1_.v3e.vc))
         {
            _loc1_.v3e.vc.vc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.v3e.vc.dm;
            _loc1_.score += Math.floor(_loc1_.v3e.vc.dm / 10) * 10 + 10;
         }
      }
      else if(_loc1_.gls > 0)
      {
         if(hitTest(_loc1_.l1.ls))
         {
            _loc1_.l1.ls.ls.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.l1.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l1.ls.dm / 10) * 10;
         }
         if(hitTest(_loc1_.l2.ls))
         {
            _loc1_.l2.ls.ls.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.l2.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l2.ls.dm / 10) * 10;
         }
         if(hitTest(_loc1_.l3.ls))
         {
            _loc1_.l3.ls.ls.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.l3.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l3.ls.dm / 10) * 10;
         }
         if(hitTest(_loc1_.l4.ls))
         {
            _loc1_.l4.ls.ls.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.l4.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l4.ls.dm / 10) * 10;
         }
         if(hitTest(_loc1_.l5.ls))
         {
            _loc1_.l5.ls.ls.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.l5.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l5.ls.dm / 10) * 10;
         }
         if(hitTest(_loc1_.l6.ls))
         {
            _loc1_.l6.ls.ls.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.l6.ls.dm;
            _loc1_.score += Math.ceil(_loc1_.l6.ls.dm / 10) * 10;
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
               _loc1_.plane.plane.pctrl.plz.ene1 = _loc2_._parent._parent;
            }
            else if(assign == 1)
            {
               _loc1_.plane.plane.pctrl.plz.ene2 = new Object();
               _loc1_.plane.plane.pctrl.plz.ene2 = _loc2_._parent._parent;
            }
            else if(assign == 2)
            {
               _loc1_.plane.plane.pctrl.plz.ene3 = new Object();
               _loc1_.plane.plane.pctrl.plz.ene3 = _loc2_._parent._parent;
            }
            else if(assign == 3)
            {
               _loc1_.plane.plane.pctrl.plz.ene4 = new Object();
               _loc1_.plane.plane.pctrl.plz.ene4 = _loc2_._parent._parent;
            }
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.plane.plane.pctrl.plz.dm;
            _loc1_.score += Math.round(Math.random() * Math.random() + 0.1) * 10;
         }
      }
      if(_loc1_.mnc > 0)
      {
         if(hitTest(_loc1_.n1.nc))
         {
            _loc1_.n1.nc.nc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.n1.nc.dm;
            _loc1_.score += Math.ceil(_loc1_.n1.nc.dm / 10) * 10;
         }
         if(hitTest(_loc1_.n2.nc))
         {
            _loc1_.n2.nc.nc.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.n2.nc.dm;
            _loc1_.score += Math.ceil(_loc1_.n2.nc.dm / 10) * 10;
         }
      }
      else if(_loc1_.mhm > 0)
      {
         if(hitTest(_loc1_.h1.hm))
         {
            _loc1_.h1.hm.hm.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.h1.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h2.hm))
         {
            _loc1_.h2.hm.hm.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.h2.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h3.hm))
         {
            _loc1_.h3.hm.hm.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.h3.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h4.hm))
         {
            _loc1_.h4.hm.hm.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.h4.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h5.hm))
         {
            _loc1_.h5.hm.hm.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.h5.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h6.hm))
         {
            _loc1_.h6.hm.hm.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.h6.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h7.hm))
         {
            _loc1_.h7.hm.hm.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.h7.hm.dm;
            _loc1_.score += 10;
         }
         if(hitTest(_loc1_.h8.hm))
         {
            _loc1_.h8.hm.hm.play();
            _loc2_.play();
            _loc2_._parent.hp -= _loc1_.h8.hm.dm;
            _loc1_.score += 10;
         }
      }
      if(hitTest(_loc1_.b1))
      {
         _loc2_._parent.hp -= _loc1_.b1.dm;
         _loc2_.play();
         _loc1_.score += 10;
      }
      else if(hitTest(_loc1_.b2))
      {
         _loc2_._parent.hp -= _loc1_.b2.dm;
         _loc2_.play();
         _loc1_.score += 10;
      }
      else if(hitTest(_loc1_.b3))
      {
         _loc2_._parent.hp -= _loc1_.b3.dm;
         _loc2_.play();
         _loc1_.score += 10;
      }
   }
};
