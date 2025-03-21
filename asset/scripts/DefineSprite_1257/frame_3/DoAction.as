if(Key.isDown(32) || Key.isDown(13))
{
   if(_parent.opt == 1)
   {
      if(_parent.savefilex.data.missionno == undefined || _parent.savefilex.data.levelno == undefined || _parent.savefilex.data.dif == undefined || _parent.savefilex.data.score == undefined || _parent.savefilex.data.bbno == undefined || _parent.savefilex.data.fairyno == undefined || _parent.savefilex.data.gvc == undefined || _parent.savefilex.data.gls == undefined || _parent.savefilex.data.gps == undefined || _parent.savefilex.data.mnc == undefined || _parent.savefilex.data.mhm == undefined || _parent.savefilex.data.credit == undefined || _parent.savefilex.data.life == undefined || _parent.savefilex.data.busedno == undefined || _parent.savefilex.data.itemno == undefined)
      {
         gotoAndStop(8);
      }
      else
      {
         gotoAndStop(6);
      }
   }
   else
   {
      gotoAndStop(7);
   }
   _parent.confirm();
}
if(Key.isDown(38))
{
   gotoAndStop(5);
   _parent.prevFrame();
}
if(Key.isDown(40))
{
   gotoAndStop(5);
   _parent.nextFrame();
}
if(Key.isDown(37) && _parent._currentframe >= 37)
{
   gotoAndStop(5);
   _parent.gotoAndStop(_parent._currentframe - 3);
}
if(Key.isDown(39) && _parent._currentframe <= 36)
{
   gotoAndStop(5);
   _parent.gotoAndStop(_parent._currentframe + 3);
}
