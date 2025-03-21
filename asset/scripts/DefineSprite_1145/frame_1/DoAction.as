x1 = 2489573728463;
x2 = 372;
y1 = 4857362958374;
y2 = 685;
this.onEnterFrame = function()
{
   xval = "x:" + x1 + "." + x2;
   yval = "y:" + y1 + "." + y2;
   if(_root.pause == 0)
   {
      x1 = Math.floor(Math.random() * 8999999999999) + 1000000000000;
      x2 = Math.floor(Math.random() * 89) + 10;
      y1 = Math.floor(Math.random() * 8999999999999) + 1000000000000;
      y2 = Math.floor(Math.random() * 89) + 10;
   }
};
