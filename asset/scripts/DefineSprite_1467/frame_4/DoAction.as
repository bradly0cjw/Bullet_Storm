if(_root.pause == 0)
{
   sc++;
   if(Key.isDown(_root.shtopt) && _root.shoot == 1)
   {
      if(Key.isDown(39))
      {
         bound += 20;
         if(bound > 240)
         {
            bound = 240;
         }
      }
      if(Key.isDown(37))
      {
         bound -= 20;
         if(bound < -240)
         {
            bound = -240;
         }
      }
      if(!Key.isDown(37) && !Key.isDown(39))
      {
         if(bound < 0)
         {
            bound += 20;
         }
         else if(bound > 0)
         {
            bound -= 20;
         }
      }
      rd = random(32);
      if(ene1.xp == undefined && ene2.xp == undefined && ene3.xp == undefined && ene4.xp == undefined)
      {
         _root.lightning.gotoAndStop(1);
         _root.plaz.createEmptyMovieClip("plazma",1);
         with(_root.plaz.plazma)
         {
            lineStyle(9,16637947,75);
            moveTo(_root.plane._x,_root.plane._y - 12);
            curveTo(rd / 4 + _root.plane._x - 4,_root.plane._y - 256,_root.plane._x + bound,_root.plane._y - 400);
         }
         _root.plaz.createEmptyMovieClip("plazma2",2);
         with(_root.plaz.plazma2)
         {
            lineStyle(3,16777215,75);
            moveTo(_root.plane._x,_root.plane._y - 12);
            curveTo(rd / 4 + _root.plane._x - 4,_root.plane._y - 256,_root.plane._x + bound,_root.plane._y - 400);
         }
      }
      else
      {
         if(ene1.xp == undefined)
         {
            ene1 = ene4;
         }
         if(ene2.xp == undefined)
         {
            ene2 = ene1;
         }
         if(ene3.xp == undefined)
         {
            ene3 = ene2;
         }
         if(ene4.xp == undefined)
         {
            ene4 = ene3;
         }
         if(ene1.xp == undefined)
         {
            ene1 = ene4;
         }
         if(ene2.xp == undefined)
         {
            ene2 = ene1;
         }
         _root.plaz.createEmptyMovieClip("plazma",1);
         with(_root.plaz.plazma)
         {
            lineStyle(9,16637947,75);
            moveTo(_root.plane._x,_root.plane._y - 12);
            curveTo(rd + _root.plane._x + bound * 0.65 - 8,rd + (_root.plane._y - 256),ene1.xp,ene1.yp);
         }
         _root.plaz.createEmptyMovieClip("plazma2",2);
         with(_root.plaz.plazma2)
         {
            lineStyle(3,16777215,75);
            moveTo(_root.plane._x,_root.plane._y - 12);
            curveTo(rd + _root.plane._x + bound * 0.65 - 8,rd + (_root.plane._y - 256),ene1.xp,ene1.yp);
         }
         _root.lightning._x = ene1.xp;
         _root.lightning._y = ene1.yp;
         _root.lightning.play();
         psound.nextFrame();
      }
      psound2.nextFrame();
   }
   else
   {
      _root.plaz.plazma._y = -3000;
      _root.plaz.plazma2._y = -3000;
      _root.plaz.plazma3._y = -3000;
      _root.lightning.gotoAndStop(1);
   }
}
dm = 5 / (_root.lv1.planeArray.length + 2);
if(dm < 1)
{
   dm = 1;
}
