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
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
_root.lv1.grn.attachMovie("boss8c","boss8c",1,initObject);
_root.id = _root.id + 1;
initObject = new Object();
initObject._x = _parent.xp;
initObject._y = _parent.yp;
_root.debris.attachMovie("boss8bdead","debris" + _root.id,_root.id,initObject);
_root.score += Math.round(_root.dif * 24000 / 10) * 10;
