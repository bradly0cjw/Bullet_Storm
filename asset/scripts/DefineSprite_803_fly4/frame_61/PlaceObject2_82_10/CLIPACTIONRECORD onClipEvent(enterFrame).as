onClipEvent(enterFrame){
   if(_root.pause == 0 && _parent.gone == 0)
   {
      tm++;
      _parent.speed *= 1.05;
      if(_parent.speed >= 5)
      {
         _parent.speed = 5;
      }
      _parent.fly._x += _parent.speed * Math.sin(_parent.fly.fly.fly._rotation * 3.141592653589793 / 180);
      _parent.fly._y -= _parent.speed * Math.cos(_parent.fly.fly.fly._rotation * 3.141592653589793 / 180);
      if(_parent.fly.hitTest(_root.tborder) || _parent.fly.hitTest(_root.rborder) || _parent.fly.hitTest(_root.bborder) || _parent.fly.hitTest(_root.lborder))
      {
         _parent.gotoAndStop(80);
      }
      if(tm < 105)
      {
         targetVectorX = _root.plane._x - _parent.xp;
         targetVectorY = _parent.yp - _root.plane._y;
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
         if(Math.abs(targetTheta - _parent.fly.fly.fly._rotation) < 10 || Math.abs(targetTheta - _parent.fly.fly.fly._rotation) > 350)
         {
            _parent.fly.fly.fly._rotation = targetTheta;
            turning = 0;
         }
         if(_parent.fly.fly.fly._rotation < targetTheta)
         {
            if(turning < turnSpeed)
            {
               turning++;
            }
         }
         else if(_parent.fly.fly.fly._rotation > targetTheta)
         {
            if(turning > - turnSpeed)
            {
               turning--;
            }
         }
         _parent.fly.fly.fly._rotation += turning;
      }
   }
}
