_parent.gone = 1;
_root.lv1.planeArray[_parent.adt] = null;
_root.lv1.upd();
_root.lv1.gotoAndStop(197);
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
generate();
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
_root.itemc.attachMovie("ruby","ruby" + _root.id,_root.id,initObject);
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
_root.debris.attachMovie("boss6dead","debris" + _root.id,_root.id,initObject);
fly.gotoAndStop(1);
maxtime = _root.dif * 70;
combo = 10 - Math.floor(_parent.mt / 30 / maxtime * 10);
if(combo < 1)
{
   combo = 1;
}
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
initObject.combono = combo;
_root.itemc.attachMovie("combo","debris" + _root.id,_root.id,initObject);
escore = combo / 10 + 1;
_root.score += Math.round(_root.dif * 56000 * escore / 10) * 10;
delete _parent.xp;
delete _parent.yp;
