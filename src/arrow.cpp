#include "arrow.h"

Arrow::Arrow(Direction direction, beatPos pos)
{
  spawnPoints = GetSpawnPoints();
  comesFrom = direction;
  arrowSpeed = speed;
  arrowTick = GetArrowTick(pos);

  arrowDelta = GetArrowDelta();
  SpawnArrow();
}

void Arrow::SpawnArrow()
{
  arrowPos = spawnPoints[comesFrom];
  DrawCircleV(arrowPos, 20, GREEN);
}

void Arrow::MoveArrow()
{
  arrowPos.x += arrowDelta.x;
  arrowPos.y += arrowDelta.y;
  DrawCircleV(arrowPos, 20, GREEN);
}

std::map<Direction, Vector2> Arrow::GetSpawnPoints()
{
  std::map<Direction, Vector2> points;
  const float scx = screenCenter.x;
  const float scy = screenCenter.y;
  const float halfSide = spawnRadius / sqrt(2);

  points[TOP_LEFT] = {scx - halfSide, scy - halfSide};
  points[TOP] = {scx, scy - spawnRadius};
  points[TOP_RIGHT] = {scx + halfSide, scy - halfSide};

  points[LEFT] = {scx - spawnRadius, scy};
  points[RIGHT] = {scx + spawnRadius, scy};

  points[BOTTOM_LEFT] = {scx - halfSide, scy + halfSide};
  points[BOTTOM] = {scx, scy + spawnRadius};
  points[BOTTOM_RIGHT] = {scx + halfSide, scy + halfSide};

  return points;
}

Vector2 Arrow::GetArrowDelta()
{
  const float sqrt2 = sqrt(2);

  switch (comesFrom)
  {
  case TOP:
    return {0, arrowSpeed};
    break;
  case TOP_RIGHT:
    return {-arrowSpeed / sqrt2, arrowSpeed / sqrt2};
    break;
  case RIGHT:
    return {-arrowSpeed, 0};
    break;
  case BOTTOM_RIGHT:
    return {-arrowSpeed / sqrt2, -arrowSpeed / sqrt2};
    break;
  case BOTTOM:
    return {0, -arrowSpeed};
    break;
  case BOTTOM_LEFT:
    return {arrowSpeed / sqrt2, -arrowSpeed / sqrt2};
    break;
  case LEFT:
    return {arrowSpeed, 0};
    break;
  case TOP_LEFT:
    return {arrowSpeed / sqrt2, arrowSpeed / sqrt2};
    break;
  default:
    return {0, 0};
    break;
  }
}

int Arrow::GetArrowTick(beatPos pos)
{
  return (pos.bar - 1) * 16 + (pos.beat - 1) * 4 + pos.tick;
}
