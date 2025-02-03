#pragma once

#include <raylib.h>
#include <map>
#include <cmath>

#include "directions.h"
#include "configs.h"

class Arrow
{
public:
  struct beatPos
  {
    int bar;
    int beat;
    int tick;
  };
  Arrow(Direction direction, beatPos pos);
  Direction comesFrom;
  int arrowTick;
  Vector2 arrowPos;

  void SpawnArrow();
  void MoveArrow();

private:
  std::map<Direction, Vector2> spawnPoints;
  float arrowSpeed;
  Vector2 arrowDelta;

  std::map<Direction, Vector2> GetSpawnPoints();
  Vector2 GetArrowDelta();
  int GetArrowTick(beatPos pos);
};