bgMusic = new Sound();
bgMusic.attachSound("lvboss1");
bgMusic2 = new Sound();
bgMusic2.attachSound("lvboss2");
bgMusic.onSoundComplete = function()
{
   gotoAndPlay(7);
};
bgMusic2.onSoundComplete = function()
{
   bgMusic2.start(0,0);
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
         if(bgMusic2.position == 0)
         {
            bgMusic2.start(0,0);
         }
      }
   }
};
stop();
