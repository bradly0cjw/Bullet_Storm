this.onEnterFrame = function()
{
   var _loc1_ = _root;
   var _loc2_ = _parent;
   if(_loc1_.pause == 0)
   {
      if(_loc1_.plane._currentframe > 14 && _loc1_.gameover._currentframe == 1)
      {
         rd = random(16);
         if(rd == 1)
         {
            _loc2_._parent.play();
         }
      }
      if(_loc1_.gvc > 0)
      {
         if(hitTest(_loc1_.v1.vc))
         {
            _loc2_._parent.play();
            _loc1_.v1.vc.vc.play();
         }
         if(hitTest(_loc1_.v2.vc))
         {
            _loc2_._parent.play();
            _loc1_.v2.vc.vc.play();
         }
         if(hitTest(_loc1_.v3.vc))
         {
            _loc2_._parent.play();
            _loc1_.v3.vc.vc.play();
         }
         if(hitTest(_loc1_.v1b.vc))
         {
            _loc2_._parent.play();
            _loc1_.v1b.vc.vc.play();
         }
         if(hitTest(_loc1_.v2b.vc))
         {
            _loc2_._parent.play();
            _loc1_.v2b.vc.vc.play();
         }
         if(hitTest(_loc1_.v3b.vc))
         {
            _loc2_._parent.play();
            _loc1_.v3b.vc.vc.play();
         }
         if(hitTest(_loc1_.v1c.vc))
         {
            _loc2_._parent.play();
            _loc1_.v1c.vc.vc.play();
         }
         if(hitTest(_loc1_.v2c.vc))
         {
            _loc2_._parent.play();
            _loc1_.v2c.vc.vc.play();
         }
         if(hitTest(_loc1_.v3c.vc))
         {
            _loc2_._parent.play();
            _loc1_.v3c.vc.vc.play();
         }
         if(hitTest(_loc1_.v1d.vc))
         {
            _loc2_._parent.play();
            _loc1_.v1d.vc.vc.play();
         }
         if(hitTest(_loc1_.v2d.vc))
         {
            _loc2_._parent.play();
            _loc1_.v2d.vc.vc.play();
         }
         if(hitTest(_loc1_.v3d.vc))
         {
            _loc2_._parent.play();
            _loc1_.v3d.vc.vc.play();
         }
         if(hitTest(_loc1_.v1e.vc))
         {
            _loc2_._parent.play();
            _loc1_.v1e.vc.vc.play();
         }
         if(hitTest(_loc1_.v2e.vc))
         {
            _loc2_._parent.play();
            _loc1_.v2e.vc.vc.play();
         }
         if(hitTest(_loc1_.v3e.vc))
         {
            _loc2_._parent.play();
            _loc1_.v3e.vc.vc.play();
         }
      }
      else if(_loc1_.gls > 0)
      {
         if(hitTest(_loc1_.l1.ls))
         {
            _loc2_._parent.play();
            _loc1_.l1.ls.ls.play();
         }
         if(hitTest(_loc1_.l2.ls))
         {
            _loc2_._parent.play();
            _loc1_.l2.ls.ls.play();
         }
         if(hitTest(_loc1_.l3.ls))
         {
            _loc2_._parent.play();
            _loc1_.l3.ls.ls.play();
         }
         if(hitTest(_loc1_.l4.ls))
         {
            _loc2_._parent.play();
            _loc1_.l4.ls.ls.play();
         }
         if(hitTest(_loc1_.l5.ls))
         {
            _loc2_._parent.play();
            _loc1_.l5.ls.ls.play();
         }
         if(hitTest(_loc1_.l6.ls))
         {
            _loc2_._parent.play();
            _loc1_.l6.ls.ls.play();
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
            _loc2_._parent.play();
         }
      }
      if(_loc1_.mnc > 0)
      {
         if(hitTest(_loc1_.n1.nc))
         {
            _loc2_._parent.play();
            _loc1_.n1.nc.nc.play();
         }
         if(hitTest(_loc1_.n2.nc))
         {
            _loc2_._parent.play();
            _loc1_.n2.nc.nc.play();
         }
      }
      else if(_loc1_.mhm > 0)
      {
         if(hitTest(_loc1_.h1.hm))
         {
            _loc1_.h1.hm.hm.play();
            _loc2_._parent.play();
         }
         if(hitTest(_loc1_.h2.hm))
         {
            _loc1_.h2.hm.hm.play();
            _loc2_._parent.play();
         }
         if(hitTest(_loc1_.h3.hm))
         {
            _loc1_.h3.hm.hm.play();
            _loc2_._parent.play();
         }
         if(hitTest(_loc1_.h4.hm))
         {
            _loc1_.h4.hm.hm.play();
            _loc2_._parent.play();
         }
         if(hitTest(_loc1_.h5.hm))
         {
            _loc1_.h5.hm.hm.play();
            _loc2_._parent.play();
         }
         if(hitTest(_loc1_.h6.hm))
         {
            _loc1_.h6.hm.hm.play();
            _loc2_._parent.play();
         }
         if(hitTest(_loc1_.h7.hm))
         {
            _loc1_.h7.hm.hm.play();
            _loc2_._parent.play();
         }
         if(hitTest(_loc1_.h8.hm))
         {
            _loc1_.h8.hm.hm.play();
            _loc2_._parent.play();
         }
      }
      if(hitTest(_loc1_.b1) || hitTest(_loc1_.b2) || hitTest(_loc1_.b3))
      {
         _loc2_._parent.play();
      }
   }
};
