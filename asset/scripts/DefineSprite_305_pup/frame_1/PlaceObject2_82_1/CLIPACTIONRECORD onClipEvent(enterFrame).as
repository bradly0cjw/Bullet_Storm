onClipEvent(enterFrame){
   if(_root.pause == 0 && _root.el.ebonus.ct == undefined)
   {
      sc++;
      if(sc >= 1440)
      {
         xSpeed += accel * Math.sin(_rotation * 3.141592653589793 / 180);
         ySpeed += accel * Math.cos(_rotation * 3.141592653589793 / 180);
         xSpeed /= 3;
         ySpeed /= 3;
         _parent._x += xSpeed;
         _parent._y -= ySpeed;
         if(_parent._x < -8 || _parent._y < -8 || _parent._x > 308 || _parent._y > 358)
         {
            _parent.removeMovieClip();
         }
      }
      else
      {
         targetVectorX = 150 - _parent._x;
         targetVectorY = _parent._y - 150;
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
         xSpeed += accel * Math.sin(_rotation * 3.141592653589793 / 180);
         ySpeed += accel * Math.cos(_rotation * 3.141592653589793 / 180);
         xSpeed /= 3;
         ySpeed /= 3;
         _parent._x += xSpeed;
         _parent._y -= ySpeed;
      }
   }
}
