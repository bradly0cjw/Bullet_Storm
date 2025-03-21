if(rota >= 360)
{
   rt = rota - 360;
}
else if(rota < 0)
{
   rt = rota + 360;
}
else
{
   rt = rota;
}
if(rt >= 315 || rt < 45)
{
   sr = 0;
}
else if(rt >= 45 && rt < 135)
{
   sr = 90;
}
else if(rt >= 225 && rt < 315)
{
   sr = 270;
}
else
{
   sr = 180;
}
if(sr == 0)
{
   xsl = -5;
   xsr = 5;
   ysl = -16;
   ysr = -16;
   rsl = 350;
   rsr = 10;
}
else if(sr == 90)
{
   xsl = 12;
   xsr = 12;
   ysl = -4;
   ysr = 4;
   rsl = 80;
   rsr = 100;
}
else if(sr == 270)
{
   xsl = -12;
   xsr = -12;
   ysl = -4;
   ysr = 4;
   rsl = 280;
   rsr = 260;
}
else
{
   xsl = -5;
   xsr = 5;
   ysl = 16;
   ysr = 16;
   rsl = 190;
   rsr = 170;
}
if(_root.plane._currentframe < 14 && xp !== undefined)
{
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + xsl;
   initObject._y = yp + ysl;
   initObject._rotation = rsl;
   _root.itemc.attachMovie("shot6","shot" + _root.id,_root.id,initObject);
   _root.id = _root.id + 1;
   initObject = new Object();
   initObject._x = xp + xsr;
   initObject._y = yp + ysr;
   initObject._rotation = rsr;
   _root.itemc.attachMovie("shot6","shot" + _root.id,_root.id,initObject);
   bsound.start(0,0);
}
