_root.credit = _root.credit + 1;
_root.plus3._x = _parent._x;
_root.plus3._y = _parent._y;
_root.plus3.gotoAndPlay(2);
if(_root.credit < 100)
{
   _root.score += _root.credit * 10000;
}
else
{
   _root.score += 1000000;
}
_parent.removeMovieClip();
