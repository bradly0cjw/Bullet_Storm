bgMusic = new Sound();
bgMusic.attachSound("lv6");
bgMusic.start(0,0);
bgMusic.onSoundComplete = function()
{
   bgMusic.start(0,0);
   count = 1;
};
count = 0;
sc = 0;
this.onEnterFrame = function()
{
   if(_root.pause == 0)
   {
      if(count == 1)
      {
         sc++;
      }
      if(sc > 3)
      {
         sc = 0;
         count = 0;
         if(bgMusic.position == 0)
         {
            bgMusic.start(0,0);
         }
      }
   }
};
gotoAndPlay(4);
