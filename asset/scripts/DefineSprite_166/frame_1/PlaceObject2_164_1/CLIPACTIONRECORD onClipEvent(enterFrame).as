onClipEvent(enterFrame){
   if(_root.pause == 0)
   {
      if(_parent._parent.leave == 0)
      {
         if(_root.plane._currentframe < 14)
         {
            targetVectorX = _root.plane._x - _parent._parent._parent.xp;
            targetVectorY = _parent._parent._parent.yp - _root.plane._y;
         }
         else
         {
            targetVectorX = 0;
            targetVectorY = _parent._parent._parent.yp - 400;
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
         if(Math.abs(targetTheta - _rotation) < 10 || Math.abs(targetTheta - _rotation) > 350)
         {
            _rotation = targetTheta;
            turning = 0;
         }
         if(_rotation < targetTheta)
         {
            if(turning < turnSpeed)
            {
               turning++;
            }
         }
         else if(_rotation > targetTheta)
         {
            if(turning > - turnSpeed)
            {
               turning--;
            }
         }
         _rotation = _rotation + turning;
      }
   }
}
