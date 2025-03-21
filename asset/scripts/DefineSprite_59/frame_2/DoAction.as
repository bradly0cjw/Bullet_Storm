count++;
_X = _X + speed;
if(_X < 50)
{
   _X = 50;
}
if(_X > 250)
{
   _X = 250;
}
if(count >= time)
{
   count = 0;
   gotoAndPlay(4);
}
