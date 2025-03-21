function upd()
{
   tempArray = new Array();
   i = 0;
   while(i < eArray.length)
   {
      if(eArray[i] != null)
      {
         newNdx = tempArray.length;
         tempArray[newNdx] = eArray[i];
         tempArray[newNdx].adt = newNdx;
      }
      i++;
   }
   eArray = new Array();
   for(ndx in tempArray)
   {
      eArray[ndx] = tempArray[ndx];
   }
}
stop();
