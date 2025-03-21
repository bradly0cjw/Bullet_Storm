function confirm()
{
   var _loc1_ = _root;
   if(savefilex.data.missionno == undefined || savefilex.data.levelno == undefined || savefilex.data.dif == undefined || savefilex.data.score == undefined || savefilex.data.bbno == undefined || savefilex.data.fairyno == undefined || savefilex.data.gvc == undefined || savefilex.data.gls == undefined || savefilex.data.gps == undefined || savefilex.data.mnc == undefined || savefilex.data.mhm == undefined || savefilex.data.credit == undefined || savefilex.data.busedno == undefined || savefilex.data.itemno == undefined)
   {
      file4 = "ERROR!";
   }
   else
   {
      _loc1_.missionno = savefilex.data.missionno;
      _loc1_.levelno = savefilex.data.levelno;
      _loc1_.dif = savefilex.data.dif;
      _loc1_.score = savefilex.data.score;
      _loc1_.bbno = savefilex.data.bbno;
      _loc1_.fairyno = savefilex.data.fairyno;
      _loc1_.gvc = savefilex.data.gvc;
      _loc1_.gls = savefilex.data.gls;
      _loc1_.gps = savefilex.data.gps;
      _loc1_.mnc = savefilex.data.mnc;
      _loc1_.mhm = savefilex.data.mhm;
      _loc1_.credit = savefilex.data.credit;
      _loc1_.busedno = savefilex.data.busedno;
      _loc1_.itemno = savefilex.data.itemno;
      if(savefilex.data.dif == 0.5)
      {
         _loc1_.bspd = 4;
      }
      else if(savefilex.data.dif == 2)
      {
         _loc1_.bspd = 5;
      }
      else
      {
         _loc1_.bspd = 4.5;
      }
      _loc1_.gotoAndStop("loadframe");
   }
}
var savefilex = SharedObject.getLocal("04RAIDE3NX448E30CB77GO3GLEY19ID07");
