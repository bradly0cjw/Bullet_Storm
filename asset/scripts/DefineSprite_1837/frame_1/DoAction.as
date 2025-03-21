score = _root.score;
if(_root.dif == 0.5)
{
   difficulty = "EASY";
}
else if(_root.dif == 2)
{
   difficulty = "HARD";
}
else
{
   difficulty = "NORMAL";
}
mission = _root.missionno;
levels = _root.levelno + 8 * (mission - 1);
bombs = _root.busedno;
items = _root.itemno;
