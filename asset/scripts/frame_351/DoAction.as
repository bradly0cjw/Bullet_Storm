imusic2.start(0,0);
qual = "LOW";
imusic2.onSoundComplete = function()
{
   imusic1.start(0,0);
   ia.cm = 1;
};
imusic1.onSoundComplete = function()
{
   imusic2.start(0,0);
   ia.cm = 2;
};
gotoAndPlay(353);
