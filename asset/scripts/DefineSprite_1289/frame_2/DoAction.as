function confirm()
{
   var _loc3_ = SharedObject.getLocal("01RAIDE3NX445E27BY74GO0GLEY16ID04");
   var _loc1_ = SharedObject.getLocal("02RAIDE3NX446E28BZ75GO1GLEY17ID05");
   var _loc2_ = SharedObject.getLocal("03RAIDE3NX447E29CA76GO2GLEY18ID06");
   var savefile4 = SharedObject.getLocal("04RAIDE3NX448E30CB77GO3GLEY19ID07");
   var savefile5 = SharedObject.getLocal("05RAIDE3NX449E31CC78GO4GLEY20ID08");
   file1 = _loc3_.data.idname;
   file2 = _loc1_.data.idname;
   file3 = _loc2_.data.idname;
   file4 = savefile4.data.idname;
   file5 = savefile5.data.idname;
   if(file1 == undefined)
   {
      file1 = "---";
   }
   if(file2 == undefined)
   {
      file2 = "---";
   }
   if(file3 == undefined)
   {
      file3 = "---";
   }
   if(file4 == undefined)
   {
      file4 = "---";
   }
   if(file5 == undefined)
   {
      file5 = "---";
   }
   gotoAndStop(34);
}
opt = 1;
