onClipEvent(enterFrame){
   if(_root.pause == 0)
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
      if(Math.abs(targetTheta - _parent.fly.fly.fly.fly._rotation) < 10 || Math.abs(targetTheta - _parent.fly.fly.fly.fly._rotation) > 350)
      {
         _parent.fly.fly.fly.fly._rotation = targetTheta;
         turning = 0;
      }
      if(_parent.fly.fly.fly.fly._rotation < targetTheta)
      {
         if(turning < turnSpeed)
         {
            turning++;
         }
      }
      else if(_parent.fly.fly.fly.fly._rotation > targetTheta)
      {
         if(turning > - turnSpeed)
         {
            turning--;
         }
      }
      _parent.fly.fly.fly.fly._rotation += turning;
   }
}
