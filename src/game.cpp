#include "game.hpp"

Game::Game(Song currentSong)
{
  song = currentSong;

  shieldFaceDir = CENTER;
  if (screenCenter.x != 0 && screenCenter.y != 0)
  {
    center = screenCenter;
  }
  else
  {
    center = {400, 225};
  }

  gameTick = 0;
  lastTick = 0;
  lastHit = "-";

  arrowsAll = GetMapArrows();
}

void Game::Update()
{
  UpdateShieldDir();
  DrawEnv();

  if (arrowsAll.size())
  {
    if (song.GetSongTick() + gapInTicks >= arrowsAll[0]->arrowTick)
    {
      arrowsOnScreen.push_back(arrowsAll[0]);
      arrowsAll.erase(arrowsAll.begin());
    }
  }

  for (int i = 0; i < arrowsOnScreen.size(); i++)
  {
    arrowsOnScreen[i]->MoveArrow();
  }

  if (arrowsOnScreen.size())
  {
    float closestArrowDistance = Vector2Distance(arrowsOnScreen[0]->arrowPos, center);
    if (closestArrowDistance < shieldAreaRadius + 10 && closestArrowDistance >= shieldAreaRadius && arrowsOnScreen[0]->comesFrom == shieldFaceDir)
    {
      arrowsOnScreen.erase(arrowsOnScreen.begin());
      lastHit = "HIT";
    }

    if (closestArrowDistance < shieldAreaRadius)
    {
      lastHit = "MISS";
    }

    if (closestArrowDistance < 10)
    {
      arrowsOnScreen.erase(arrowsOnScreen.begin());
    }
  }
}

void Game::DrawEnv()
{
  DrawCircleV(center, shieldAreaRadius + 10, Fade(GREEN, 0.3));

  DrawPolyLinesEx(center, 8, shieldAreaRadius, 22.5, 6, RED);
  DrawShield();
  DrawPoly(center, 8, shieldAreaRadius - 20, 22.6, WHITE);
}

void Game::DrawShield()
{
  if (shieldFaceDir == CENTER)
  {
    // DrawCircleV(center, shieldAreaRadius - 20, BLUE);
    DrawPoly(center, 8, shieldAreaRadius - 15, 22.6, BLUE);
  }
  else
  {
    switch (shieldFaceDir)
    {
    case TOP:
      DrawCircleSector(center, shieldAreaRadius, 270 - 22.5, 270 + 22.5, 2, BLUE);
      break;
    case TOP_RIGHT:
      DrawCircleSector(center, shieldAreaRadius, 270 + 22.5, 360 - 22.5, 2, BLUE);
      break;
    case RIGHT:
      DrawCircleSector(center, shieldAreaRadius, -22.5, 22.5, 2, BLUE);
      break;
    case BOTTOM_RIGHT:
      DrawCircleSector(center, shieldAreaRadius, 22.5, 90 - 22.5, 2, BLUE);
      break;
    case BOTTOM:
      DrawCircleSector(center, shieldAreaRadius, 90 - 22.5, 90 + 22.5, 2, BLUE);
      break;
    case BOTTOM_LEFT:
      DrawCircleSector(center, shieldAreaRadius, 90 + 22.5, 180 - 22.5, 2, BLUE);
      break;
    case LEFT:
      DrawCircleSector(center, shieldAreaRadius, 180 - 22.5, 180 + 22.5, 2, BLUE);
      break;
    case TOP_LEFT:
      DrawCircleSector(center, shieldAreaRadius, 180 + 22.5, 270 - 22.5, 2, BLUE);
      break;
    default:
      break;
    }
  }
}

void Game::UpdateShieldDir()
{
  if (IsKeyDown(KEY_UP))
  {
    if (IsKeyDown(KEY_RIGHT))
    {
      shieldFaceDir = TOP_RIGHT;
      return;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
      shieldFaceDir = TOP_LEFT;
      return;
    }
    else
    {
      shieldFaceDir = TOP;
      return;
    }
  }

  if (IsKeyDown(KEY_DOWN))
  {
    if (IsKeyDown(KEY_RIGHT))
    {
      shieldFaceDir = BOTTOM_RIGHT;
      return;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
      shieldFaceDir = BOTTOM_LEFT;
      return;
    }
    else
    {
      shieldFaceDir = BOTTOM;
      return;
    }
  }

  if (IsKeyDown(KEY_RIGHT))
  {
    shieldFaceDir = RIGHT;
    return;
  }
  else if (IsKeyDown(KEY_LEFT))
  {
    shieldFaceDir = LEFT;
    return;
  }

  shieldFaceDir = CENTER;
  return;
}
