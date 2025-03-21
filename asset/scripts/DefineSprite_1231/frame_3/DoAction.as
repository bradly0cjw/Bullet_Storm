vol = _root.svol.getVolume();
this.onEnterFrame = function()
{
   if(Key.isDown(37))
   {
      vol -= 2;
      if(vol <= 0)
      {
         vol = 0;
      }
   }
   if(Key.isDown(39))
   {
      vol += 2;
      if(vol >= 100)
      {
         vol = 100;
      }
   }
   _root.svol.setVolume(vol);
};
