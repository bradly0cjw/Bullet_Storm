_parent.gone = 1;
_root.lv1.planeArray[_parent.adt] = null;
_root.lv1.upd();
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
_root.lv1.sky.attachMovie("boss5b","boss5b",1,initObject);
_root.score += Math.round(_root.dif * 20000 / 10) * 10;
delete _parent.xp;
delete _parent.yp;
