onClipEvent(load){
   function fly()
   {
      xSpeed += 80 * Math.sin(_rotation * 3.141592653589793 / 180);
      ySpeed += 80 * Math.cos(_rotation * 3.141592653589793 / 180);
      xSpeed /= 40;
      ySpeed /= 40;
      _parent._x += xSpeed;
      _parent._y -= ySpeed;
   }
   tm = 0;
   ySpeed = 16;
}
