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
if(_root.gvc == 1 || _root.gls == 1 || _root.gls == 2)
{
   gotoAndStop(122);
}
else if(_parent.stat == undefined)
{
   gotoAndPlay(random(240) + 2);
}
else
{
   gotoAndPlay(_parent.stat);
}
