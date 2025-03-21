maxtime = _root.dif * 35;
combo = 10 - Math.floor(_parent.mt / 30 / maxtime * 10);
if(combo < 1)
{
   combo = 1;
}
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent._x + _X;
initObject._y = _parent._y + _Y;
initObject.combono = combo;
_root.itemc.attachMovie("combo","debris" + _root.id,_root.id,initObject);
escore = combo / 10 + 1;
_root.score += Math.round(_root.dif * 800 * escore0 / 10) * 10;
