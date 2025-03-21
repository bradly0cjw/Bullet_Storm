this.onEnterFrame = function()
{
   if(_root.pause == 0 && _root.plane._currentframe < 14 && _parent._parent._parent._parent.sc2 < 150)
   {
      _rotation = _rotation + 7;
   }
};
