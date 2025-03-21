s1 = new Sound();
s1.attachSound("itemget1");
s2 = new Sound();
s2.attachSound("itemget2");
s3 = new Sound();
s3.attachSound("itemget3");
s4 = new Sound();
s4.attachSound("bonus");
this.onEnterFrame = function()
{
   if(_root.pause == 0 && _root.el.ebonus.ct == undefined)
   {
      play();
   }
   else
   {
      stop();
   }
};
gotoAndPlay(random(360) + 2);
