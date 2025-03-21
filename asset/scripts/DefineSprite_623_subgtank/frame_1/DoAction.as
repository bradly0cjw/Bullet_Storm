adt = _root.lv1.planeArray.length;
_root.lv1.planeArray[adt] = this;
gone = 0;
rota = 180;
sst = random(3);
bsound = new Sound();
bsound.attachSound("eneshot");
this.onEnterFrame = function()
{
   if(gone == 0)
   {
      xp = _X;
      yp = _Y;
   }
   if(_root.pause == 0 && gone == 0)
   {
      if(_root.scroll == 1)
      {
         _Y = _Y + 0.8333333333333334;
      }
      play();
   }
   else
   {
      stop();
   }
   if(_Y >= 368)
   {
      gotoAndStop(169);
   }
};
