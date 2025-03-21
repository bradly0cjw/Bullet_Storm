if(_root.pause == 1)
{
   bgMusicPosition = bgMusic.position / 1000;
   bgMusic.stop();
   gotoAndPlay(5);
}
else
{
   bgMusicPosition = 0;
}
