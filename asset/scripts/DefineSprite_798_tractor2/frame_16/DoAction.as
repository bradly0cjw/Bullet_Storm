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
